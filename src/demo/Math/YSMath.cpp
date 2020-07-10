#include "YSMath.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSMath::YSMath(QObject *parent) : QObject(parent)
{
    qDebug() << "average";
    average();

    qDebug() << "count";
    count();

    qDebug() << "max";
    max();

    qDebug() << "min";
    min();

    qDebug() << "sum";
    sum();

    qDebug() << "reduce";
    reduce();

    qDebug() << "iterate";
    iterate();
}

void YSMath::average()
{
    auto observable = rxcpp::observable<>::range(0, 10).average();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](rxcpp::util::error_ptr ep) {
                             qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                         },
                         []() { qDebug() << "OnCompleted"; });
}

void YSMath::count()
{
    auto observable = rxcpp::observable<>::range(0, 10).count();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](rxcpp::util::error_ptr ep) {
                             qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                         },
                         []() { qDebug() << "OnCompleted"; });
}

void YSMath::max()
{
    auto observable = rxcpp::observable<>::range(0, 10).max();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](rxcpp::util::error_ptr ep) {
                             qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                         },
                         []() { qDebug() << "OnCompleted"; });
}

void YSMath::min()
{
    auto observable = rxcpp::observable<>::range(0, 10).min();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](rxcpp::util::error_ptr ep) {
                             qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                         },
                         []() { qDebug() << "OnCompleted"; });
}

void YSMath::sum()
{
    auto observable = rxcpp::observable<>::range(0, 10).sum();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](rxcpp::util::error_ptr ep) {
                             qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                         },
                         []() { qDebug() << "OnCompleted"; });
}

// reduce 将函数依次应用于Observable发出的每个项目，并发出最终值
void YSMath::reduce()
{
    auto observable = rxcpp::observable<>::range(0, 10);
    auto reduceOb = observable.reduce(
        1,                    // 初始值
        [](int seed, int v) { // 对序列每个值的处理
            qDebug() << seed << v;
            return seed + v;
        },
        [](int res) { // 对结果的过滤
            qDebug() << res;
            return res;
        });

    reduceOb.subscribe([](int v) { qDebug() << "onNext" << v; },
                       [](rxcpp::util::error_ptr ep) {
                           qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                       },
                       []() { qDebug() << "OnCompleted"; });
}

void YSMath::iterate()
{
    std::array<int, 3> a = {1, 2, 3};
    auto values = rxcpp::observable<>::iterate(a);
    values.subscribe([](int v) { qDebug() << "onNext" << v; },
                     [](rxcpp::util::error_ptr ep) {
                         qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                     },
                     []() { qDebug() << "OnCompleted"; });
}
