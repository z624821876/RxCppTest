#include "YSDelay.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSDelay::YSDelay(QObject *parent) : QObject(parent)
{
    qDebug() << "delay";
    delay();
}

void YSDelay::delay()
{
    using namespace std::chrono;
    auto scheduler = rxcpp::identity_current_thread();
    auto start = scheduler.now();
    auto period = milliseconds(10);
    const auto next = [=](const char *s) {
        return [=](long v) {
            auto t = duration_cast<milliseconds>(scheduler.now() - start);
            long long int ms = t.count();
            qDebug() << QString("[%1 @ %2] OnNext: %3").arg(s).arg(ms).arg(v);
        };
    };
    auto values = rxcpp::observable<>::interval(start, period, scheduler)
                      .take(4)
                      .tap(next("interval"))
                      .delay(period);
    values.subscribe(next(" delayed"), []() { qDebug() << "OnCompleted"; });
}
