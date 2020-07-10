#include "YSTake.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSTake::YSTake(QObject *parent) : QObject(parent)
{
    qDebug() << "take";
    take();

    qDebug() << "take_last";
    take_last();

    qDebug() << "take_util";
    take_util();

    qDebug() << "take_util_time";
    take_util_time();

    qDebug() << "take_while";
    take_while();
}

// 只获取前N个数据
void YSTake::take()
{
    auto values = observable<>::range(1, 7).take(3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// 获取数据  直到依赖observable触发 才停止
void YSTake::take_util()
{
    auto source = rxcpp::observable<>::interval(std::chrono::milliseconds(10)).take(7);
    auto trigger = rxcpp::observable<>::timer(std::chrono::milliseconds(25));
    auto values = source.take_until(trigger);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// 以时间点为依赖  获取时间点到达前的所有数据
void YSTake::take_util_time()
{
    auto source = rxcpp::observable<>::interval(std::chrono::milliseconds(10)).take(7);
    auto values = source.take_until(std::chrono::steady_clock::now()
                                    + std::chrono::milliseconds(25));
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// 获取最后的N个数据
void YSTake::take_last()
{
    auto values = observable<>::range(1, 7).take_last(3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

void YSTake::take_while() {}
