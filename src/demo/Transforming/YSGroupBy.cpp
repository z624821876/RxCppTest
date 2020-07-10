#include "YSGroupBy.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSGroupBy::YSGroupBy(QObject *parent) : QObject(parent)
{
    qDebug() << "group_by";
    group_by();

    qDebug() << "groupBy_and_sort";
    groupBy_and_sort();
}

// group_by 数据分组
void YSGroupBy::group_by() {

    auto values = rxcpp::observable<>::range(0, 8).
                  group_by(
                      // 第一个闭包用来分组 返回值为对应组的key
                      [](int v){ return v % 3;}
                      // 第二个闭包用来对数据做附加操作  默认不做任何操作
                      // [](int v){ return 10 * v;}
                      );

    values.subscribe(
        [](rxcpp::grouped_observable<int, int> g)
        {
            auto key = g.get_key();
            qDebug() << "OnNext: key = " << key;
            g.subscribe(
                [key](int v) {
                    qDebug() << "key" << key << "value" << v;
                },
                [key]() {
                    qDebug() << "OnCompleted" << key;
                });

           g.subscribe(
                [key](int v){printf("[key %d] OnNext: %d\n", key, v);},
                [key](){printf("[key %d] OnCompleted\n", key);});
        },
        [](){ qDebug() << "OnCompleted"; });

}

// 增加对数据的排序
// 好像只对completed的顺序有作用
void YSGroupBy::groupBy_and_sort() {
    auto values = rxcpp::observable<>::range(0, 8).
                  group_by(
                      [](int v){ return v % 3; },
                      [](int v){ return 10 * v; },
                      [](int v1, int v2) { return v1 < v2; });

    values.subscribe(
        [](rxcpp::grouped_observable<int, int> g)
        {
            auto key = g.get_key();
            qDebug() << "OnNext: key = " << key;
            g.subscribe(
                [key](int v) {
                    qDebug() << "key" << key << "value" << v;
                },
                [key]() {
                    qDebug() << "OnCompleted" << key;
                });

            g.subscribe(
                [key](int v){printf("[key %d] OnNext: %d\n", key, v);},
                [key](){printf("[key %d] OnCompleted\n", key);});
        },
        [](){ qDebug() << "OnCompleted"; });

}


