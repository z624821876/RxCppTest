#include "YSFinally.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSFinally::YSFinally(QObject *parent) : QObject(parent)
{
    auto values = observable<>::range(1, 3).finally([]() { qDebug() << "The final action"; });
    values.subscribe([](int v) { qDebug() << "subscribe -       OnNext:" << v; },
                     []() { qDebug() << "subscribe -       OnCompleted"; });
}
