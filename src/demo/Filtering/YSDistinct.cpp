#include "YSDistinct.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSDistinct::YSDistinct(QObject *parent) : QObject(parent)
{
    qDebug() << "distinct";
    distinct();

    qDebug() << "distinct_until_changed";
    distinct_until_changed();
}

void YSDistinct::distinct()
{
    auto subject = subjects::subject<int>();

    auto observable = subject.get_observable().distinct();
    observable.subscribe([](int v) { qDebug() << "OnNext" << v; },
                         []() { qDebug() << "onCompleted"; });

    auto subscriber = subject.get_subscriber();
    subscriber.on_next(1);
    subscriber.on_next(1);
    subscriber.on_next(2);
    subscriber.on_next(3);
    subscriber.on_next(5);
    subscriber.on_next(2);

    identity_current_thread().now();
}

void YSDistinct::distinct_until_changed()
{
    auto subject = subjects::subject<int>();

    auto observable = subject.get_observable().distinct_until_changed();
    observable.subscribe([](int v) { qDebug() << "OnNext" << v; },
                         []() { qDebug() << "onCompleted"; });

    auto subscriber = subject.get_subscriber();
    subscriber.on_next(1);
    subscriber.on_next(1);
    subscriber.on_next(2);
    subscriber.on_next(3);
    subscriber.on_next(5);
    subscriber.on_next(2);
}
