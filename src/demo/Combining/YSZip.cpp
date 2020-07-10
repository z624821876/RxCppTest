#include "YSZip.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

// 与combinelatest 类似
// 不同点 每次获取组合值之后都会删除历史值  保证每次获取的组合值都是所有序列的最新值
YSZip::YSZip(QObject *parent) : QObject(parent)
{
    qDebug() << "zip";
    zip();

    qDebug() << "zip_selector";
    zip_selector();
}

void YSZip::zip()
{
    auto o1 = rxcpp::observable<>::interval(std::chrono::milliseconds(2));
    auto o2 = rxcpp::observable<>::interval(std::chrono::milliseconds(3));
    auto o3 = rxcpp::observable<>::interval(std::chrono::milliseconds(5));
    auto values = o1.zip(o2, o3);
    values.take(5).subscribe(
        [](std::tuple<int, int, int> v) {
            qDebug() << "OnNext" << std::get<0>(v) << std::get<1>(v) << std::get<2>(v);
        },
        []() { qDebug() << "OnCompleted"; });
}

void YSZip::zip_selector()
{
    auto o1 = rxcpp::observable<>::interval(std::chrono::milliseconds(2));
    auto o2 = rxcpp::observable<>::interval(std::chrono::milliseconds(3));
    auto o3 = rxcpp::observable<>::interval(std::chrono::milliseconds(5));
    auto values = o1.zip([](int v1, int v2, int v3) { return 100 * v1 + 10 * v2 + v3; }, o2, o3);
    values.take(5).subscribe([](int v) { qDebug() << "OnNext" << v; },
                             []() { qDebug() << "OnCompleted"; });
}
