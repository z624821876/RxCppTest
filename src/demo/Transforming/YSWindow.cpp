#include "YSWindow.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSWindow::YSWindow(QObject *parent) : QObject(parent)
{
    qDebug() << "window";
    window();
}

// 类似于buffer  buffer将数据合并成一个数组发出去  window将数据合并生成一个新的信号
void YSWindow::window()
{
    //    int counter = 0;
    //    auto values = rxcpp::observable<>::range(1, 5).window(2);
    //    values.
    //        subscribe(
    //            [&counter](rxcpp::observable<int> v){
    //                int id = counter++;
    //                qDebug() << "Create window" << id;
    //                v.subscribe(
    //                    [id](int v){
    //                        qDebug() << "window" << id << "OnNext" << v;
    //                    },
    //                    [id](){
    //                        qDebug() << "window" << id << "OnCompleted";
    //                    });
    //            });

    // window  count + skip
    // 默认情况 window(n) == window(n, n)
    // skip 控制生成序列的间隔
    int counter = 0;
    auto values = rxcpp::observable<>::range(1, 5).window(2, 2);
    values.subscribe([&counter](rxcpp::observable<int> v) {
        int id = counter++;
        qDebug() << "Create window" << id;
        v.subscribe([id](int v) { qDebug() << "window" << id << "OnNext" << v; },
                    [id]() { qDebug() << "window" << id << "OnCompleted"; });
    });
}
