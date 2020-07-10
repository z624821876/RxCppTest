#include "YSTap.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

// 对生命周期的监听
YSTap::YSTap(QObject *parent) : QObject(parent)
{
    qDebug() << "tap";
    tap();

    qDebug() << "tap_error";
    tap_error();
}

void YSTap::tap()
{
    auto values = observable<>::range(1, 3).tap([](int v) { qDebug() << "Tap -       OnNext:" << v; },
                                                []() { qDebug() << "Tap -       OnCompleted"; });
    values.subscribe([](int v) { qDebug() << "subscribe -       OnNext:" << v; },
                     []() { qDebug() << "subscribe -       OnCompleted"; });
}

void YSTap::tap_error()
{
    auto values = observable<>::range(1, 3)
                      .concat(observable<>::error<int>(std::runtime_error("Error from source")))
                      .tap([](int v) { qDebug() << "Tap -       OnNext:" << v; },
                           [](std::exception_ptr ep) {
                               qDebug() << "Tap -       OnError" << util::what(ep).c_str();
                           },
                           []() { qDebug() << "Tap -       OnCompleted"; });

    values.subscribe([](int v) { qDebug() << "subscribe -       OnNext:" << v; },
                     [](std::exception_ptr ep) {
                         qDebug() << "subscribe -       OnError" << util::what(ep).c_str();
                     },
                     []() { qDebug() << "subscribe -       OnCompleted"; });
}
