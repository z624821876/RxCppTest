#include "YSMerge.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSMerge::YSMerge(QObject *parent) : QObject(parent)
{
    qDebug() << "merge";
    merge();

    qDebug() << "merge_delay_error";
    merge_delay_error();
}

// 将多个信号合并为一个信号
void YSMerge::merge()
{
    auto o1 = observable<>::timer(milliseconds(15)).map([](int) { return 1; });
    auto o2 = observable<>::timer(milliseconds(10)).map([](int) { return 2; });
    auto o3 = observable<>::timer(milliseconds(5)).map([](int) { return 3; });
    auto values = o1.merge(o2, o3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

void YSMerge::merge_delay_error()
{
    auto o1 = rxcpp::observable<>::timer(std::chrono::milliseconds(15)).map([](int) { return 1; });
    auto o2 = rxcpp::observable<>::error<int>(std::runtime_error("Error from source\n"));
    auto o3 = rxcpp::observable<>::timer(std::chrono::milliseconds(5)).map([](int) { return 3; });
    auto values = o1.merge_delay_error(o2, o3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; },
                     [](std::exception_ptr eptr) {
                         printf("OnError %s\n", rxu::what(eptr).c_str());
                     },
                     []() { qDebug() << "OnCompleted"; });
}
