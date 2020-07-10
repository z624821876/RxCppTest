#include "YSAll.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

// 确定一个可观察对象发出的所有项是否都满足某些标准
YSAll::YSAll(QObject *parent) : QObject(parent)
{
    auto values = rxcpp::observable<>::from(1, 2, 3, 4, 5, 10).all([](int n) { return n < 6; });
    values.subscribe([](bool v) { qDebug() << "OnNext" << (v ? "true" : "false"); },
                     []() { qDebug() << "OnCompleted"; });

    // 快捷操作 效果同上

    //    using namespace rxcpp::sources;
    //    using namespace rxcpp::operators;
    //    auto values = range(1, 10) | all([](int n) { return n < 100; });
    //    values.subscribe([](bool v) { qDebug() << "OnNext" << (v ? "true" : "false"); },
    //                     []() { qDebug() << "OnCompleted"; });
}
