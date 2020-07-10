#include "YSIgnoreElements.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSIgnoreElements::YSIgnoreElements(QObject *parent) : QObject(parent)
{
    auto ob = observable<>::range(0, 10);

    ob.ignore_elements().subscribe([](int v) { qDebug() << "OnNext" << v; },
                                   []() { qDebug() << "OnCompleted"; });
}
