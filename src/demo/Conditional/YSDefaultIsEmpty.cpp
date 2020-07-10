#include "YSDefaultIsEmpty.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSDefaultIsEmpty::YSDefaultIsEmpty(QObject *parent) : QObject(parent)
{
    qDebug() << "defaultIsEmpty";
    defaultIfEmpty();

    qDebug() << "switchIfEmpty";
    switchIfEmpty();
}

// 如果值为空  设置一个默认值
void YSDefaultIsEmpty::defaultIfEmpty()
{
    auto values = rxcpp::observable<>::empty<int>().default_if_empty(42);

    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// 如果值为空  设置一个可观察序列替换原序列
void YSDefaultIsEmpty::switchIfEmpty()
{
    auto values = rxcpp::observable<>::empty<int>().switch_if_empty(
        rxcpp::observable<>::range(1, 5));

    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
