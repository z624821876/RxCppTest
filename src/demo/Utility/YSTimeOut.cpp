#include "YSTimeOut.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSTimeOut::YSTimeOut(QObject *parent) : QObject(parent)
{
    auto values = observable<>::interval(milliseconds(100))
                      .take(3)
                      .concat(observable<>::interval(milliseconds(500)))
                      .timeout(milliseconds(200));
    values.subscribe([](long v) { qDebug() << "OnNext" << v; },
                     [](std::exception_ptr ep) {
                         try {
                             std::rethrow_exception(ep);
                         } catch (const rxcpp::timeout_error &ex) {
                             qDebug() << "OnError" << ex.what();
                         }
                     },
                     []() { qDebug() << "OnCompleted"; });
}
