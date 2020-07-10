#include "YSFlatMap.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSFlatMap::YSFlatMap(QObject *parent) : QObject(parent)
{
    qDebug() << "flat_map";
    flat_map();

    qDebug() << "concat_map";
    concat_map();
}

// 一般用来解析信号中信号
// 但是c++中的实现比较奇怪 和 其他平台不一致
void YSFlatMap::flat_map()
{
    auto values = observable<>::range(1, 3);

    auto flatMapOb = values.flat_map(
        [](int v) {
            qDebug() << "OnNext";
            return observable<>::range(1, 3);
        },
        [](int sub, int origin) { return std::make_tuple(sub, origin); });

    flatMapOb.subscribe(
        [](std::tuple<int, int> v) { qDebug() << "OnNext" << std::get<0>(v) << std::get<1>(v); });
}

// 能保证顺序
void YSFlatMap::concat_map() {
    auto values = observable<>::range(1, 3);

    auto flatMapOb = values.concat_map(
        [](int v) {
            qDebug() << "OnNext";
            return observable<>::range(1, 3);
        },
        [](int main, int sub)
        {
            return std::make_tuple(main, sub);
        }
        );


    flatMapOb.subscribe(
        [](std::tuple<int, int> v) { qDebug() << "OnNext" << std::get<0>(v) << std::get<1>(v); });

}
