#include "YSContains.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSContains::YSContains(QObject *parent) : QObject(parent)
{
    qDebug() << "contains";
    contains();

    qDebug() << "isEmpty";
    isEmpty();

    qDebug() << "exists";
    exists();
}

void YSContains::contains()
{
    auto values = rxcpp::observable<>::from(1, 2, 3, 4, 5).contains(3);
    values.subscribe([](bool v) { qDebug() << "OnNext" << (v ? "true" : "false"); },
                     []() { qDebug() << "OnCompleted"; });
}

void YSContains::isEmpty()
{
    auto values = rxcpp::observable<>::from(1, 2, 3, 4, 5).is_empty();
    values.subscribe([](bool v) { qDebug() << "OnNext" << (v ? "true" : "false"); },
                     []() { qDebug() << "OnCompleted"; });
}

void YSContains::exists()
{
    auto values = rxcpp::observable<>::from(1, 2, 3, 4, 5).exists([](int n) { return n > 3; });
    values.subscribe([](bool v) { qDebug() << "OnNext" << (v ? "true" : "false"); },
                     []() { qDebug() << "OnCompleted"; });
}
