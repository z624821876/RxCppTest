#include "YSAmb.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSAmb::YSAmb(QObject *parent) : QObject(parent)
{
    qDebug() << "amb";
    amb();
}

// 只接受最早发出消息的可观察序列
void YSAmb::amb()
{
    auto o1 = observable<>::timer(milliseconds(15)).map([](int) { return 1; });
    auto o2 = observable<>::timer(milliseconds(10)).map([](int) { return 2; });
    auto o3 = observable<>::timer(milliseconds(5)).map([](int) { return 3; });
    auto values = o1.amb(o2, o3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });

    // 效果同上  隐式转换
    //    auto base = observable<>::from(o1.as_dynamic(), o2, o3);
    //    auto values = base.amb();
}
