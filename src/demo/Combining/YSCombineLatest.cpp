#include "YSCombineLatest.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSCombineLatest::YSCombineLatest(QObject *parent) : QObject(parent)
{
    qDebug() << "combine_latest";
    combine_latest();

    qDebug() << "combine_latest_selector";
    combine_latest_selector();
}

// 组合多个序列  每次获取所有序列的最新值组合
void YSCombineLatest::combine_latest()
{
    auto o1 = rxcpp::observable<>::interval(std::chrono::milliseconds(2));
    auto o2 = rxcpp::observable<>::interval(std::chrono::milliseconds(3));
    auto o3 = rxcpp::observable<>::interval(std::chrono::milliseconds(5));
    auto values = o1.combine_latest(o2, o3);
    values.take(5).subscribe(
        [](std::tuple<int, int, int> v) {
            qDebug() << "OnNext" << std::get<0>(v) << std::get<1>(v) << std::get<2>(v);
        },
        []() { qDebug() << "OnCompleted"; });
}

// 可以对组合结果进行处理 转换  类似于加了map
void YSCombineLatest::combine_latest_selector()
{
    auto o1 = rxcpp::observable<>::interval(std::chrono::milliseconds(2));
    auto o2 = rxcpp::observable<>::interval(std::chrono::milliseconds(3));
    auto o3 = rxcpp::observable<>::interval(std::chrono::milliseconds(5));
    auto values = o1.combine_latest([](int v1, int v2, int v3) { return 100 * v1 + 10 * v2 + v3; },
                                    o2,
                                    o3);
    values.take(5).subscribe([](int v) { qDebug() << "OnNext" << v; },
                             []() { qDebug() << "OnCompleted"; });
}
