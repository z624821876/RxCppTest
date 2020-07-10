#include "YSMap.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSMap::YSMap(QObject *parent) : QObject(parent)
{
    qDebug() << "map";
    map();
}

// 映射
void YSMap::map() {

    auto ob = observable<>::range(0, 10);

    ob.map(
        [](int v){
            qDebug() << "map" << v;
            return v * 10;
        }).subscribe(
            [](int v) {
                qDebug() << "OnNext" << v;
            },
            []() { qDebug() << "OnCompleted"; });

}
