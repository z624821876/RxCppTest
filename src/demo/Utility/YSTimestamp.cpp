#include "YSTimestamp.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

// 将一个时间戳附加到由一个可观察对象发出的每个项上
YSTimestamp::YSTimestamp(QObject *parent) : QObject(parent)
{
    auto values = observable<>::interval(milliseconds(100)).timestamp().take(3);

    typedef rxcpp::schedulers::scheduler::clock_type::time_point time_point;

    time_point start = identity_current_thread().now();
    values.subscribe(
        [&](std::pair<long, time_point> v) {
            long long int ms = duration_cast<milliseconds>(v.second - start).count();
            qDebug() << "OnNext" << v.first << ms;
        },
        [](std::exception_ptr ep) {
            try {
                std::rethrow_exception(ep);
            } catch (const std::exception &ex) {
                qDebug() << "OnError" << ex.what();
            }
        },
        []() { qDebug() << "OnCompleted"; });
}
