#include "YSElementAt.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSElementAt::YSElementAt(QObject *parent) : QObject(parent)
{
    auto ob = observable<>::range(10, 15).element_at(3);
    ob.subscribe([](int v) { qDebug() << "onNext" << v; }, []() { qDebug() << "OnCompleted"; });

    //    auto ob = observable<>::range(10, 15).first();
    //    ob.subscribe([](int v) { qDebug() << "onNext" << v; }, []() { qDebug() << "OnCompleted"; });

    //    auto ob = observable<>::range(10, 15).last();
    //    ob.subscribe([](int v) { qDebug() << "onNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
