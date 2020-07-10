#include "YSTimeInterval.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSTimeInterval::YSTimeInterval(QObject *parent) : QObject(parent)
{
    typedef schedulers::scheduler::clock_type::time_point::duration duration_type;

    auto values = observable<>::interval(milliseconds(100)).time_interval().take(3);
    values.subscribe(
        [&](duration_type v) {
            long long int ms = duration_cast<milliseconds>(v).count();
            qDebug() << "OnNext" << ms;
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
