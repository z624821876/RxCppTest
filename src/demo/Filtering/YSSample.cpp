#include "YSSample.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSSample::YSSample(QObject *parent) : QObject(parent)
{
    auto ob = observable<>::interval(milliseconds(2)).take(7).sample_with_time(milliseconds(4));

    ob.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
