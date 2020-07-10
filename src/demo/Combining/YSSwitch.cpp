#include "YSSwitch.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

// 用于将信息中信号平铺
YSSwitch::YSSwitch(QObject *parent) : QObject(parent)
{
    auto base = rxcpp::observable<>::interval(milliseconds(30)).take(3).map([](long) {
        return rxcpp::observable<>::interval(milliseconds(10)).as_dynamic();
    });
    auto values = base.switch_on_next().take(10);
    values.subscribe([](long v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
