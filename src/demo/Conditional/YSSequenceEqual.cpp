#include "YSSequenceEqual.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSSequenceEqual::YSSequenceEqual(QObject *parent) : QObject(parent)
{
    auto source = observable<>::range(1, 3);
    auto values = source.sequence_equal(observable<>::range(1, 3));
    values.subscribe([](bool v) { qDebug() << "OnNext" << (v ? "true" : "false"); },
                     []() { qDebug() << "OnCompleted"; });
}
