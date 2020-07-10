#include "YSSkip.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSSkip::YSSkip(QObject *parent) : QObject(parent)
{
    qDebug() << "skip";
    skip();

    qDebug() << "skip_last";
    skip_last();

    qDebug() << "skip_util";
    skip_util();

    qDebug() << "skip_while";
    skip_while();
}

// 跳跃前3个数据
void YSSkip::skip()
{
    auto values = rxcpp::observable<>::range(1, 7).skip(3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// 跳跃最后3个数据
void YSSkip::skip_last()
{
    auto values = rxcpp::observable<>::range(1, 7).skip_last(3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// 跳跃 直到条件触发才开始发送数据
void YSSkip::skip_util()
{
    auto source = rxcpp::observable<>::interval(std::chrono::milliseconds(10)).take(7);
    auto trigger = rxcpp::observable<>::timer(std::chrono::milliseconds(25));
    auto values = source.skip_until(trigger);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// 跳跃 直到第一个不符合条件的数据开始发送数据
void YSSkip::skip_while()
{
    auto values = rxcpp::observable<>::range(1, 8).skip_while([](int v) { return v <= 4; });
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
