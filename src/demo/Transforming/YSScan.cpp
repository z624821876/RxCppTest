#include "YSScan.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSScan::YSScan(QObject *parent) : QObject(parent)
{

    qDebug() << "scan";
    scan();
}

// scan 就是先给一个初始化的数，然后不断的拿前一个结果和最新的值进行处理操作
void YSScan::scan() {
    auto values = rxcpp::observable<>::range(1, 7).
                  scan(
                      0,
                      [](int seed, int v){
                          return seed + v;
                      });
    values.
        subscribe(
            [](int v){
                qDebug() << "OnNext" << v;
            },
            [](){
                qDebug() << "OnCompleted";
            });
}
