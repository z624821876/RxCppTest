#include "YSConcat.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSConcat::YSConcat(QObject *parent) : QObject(parent)
{
    qDebug() << "concatSample";
    concatSample();

    qDebug() << "implicitConcatSample";
    implicitConcatSample();
}

void YSConcat::concatSample()
{
    auto o1 = observable<>::range(1, 3);
    auto o2 = observable<>::just(4);
    auto o3 = observable<>::from(5, 6);
    auto values = o1.concat(o2, o3);
    values.subscribe([](int v) { qDebug() << "onNext" << v; },
                     [](rxcpp::util::error_ptr ep) {
                         qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                     },
                     []() { qDebug() << "OnCompleted"; });
}

void YSConcat::implicitConcatSample()
{
    auto o1 = observable<>::range(1, 3);
    auto o2 = observable<>::just(4);
    auto o3 = observable<>::from(5, 6);
    auto base = observable<>::from(o1.as_dynamic(), o2, o3);
    auto values = base.concat();

    values.subscribe([](int v) { qDebug() << "onNext" << v; },
                     [](rxcpp::util::error_ptr ep) {
                         qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                     },
                     []() { qDebug() << "OnCompleted"; });
}
