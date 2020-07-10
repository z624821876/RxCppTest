#include "YSDebounce.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSDebounce::YSDebounce(QObject *parent) : QObject(parent)
{
    auto scheduler = identity_current_thread();
    auto start = scheduler.now();
    auto period = milliseconds(10);
    auto debounce = milliseconds(11);
    auto values = observable<>::interval(start, period, scheduler).take(4).debounce(debounce);
    values.subscribe([](long v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
