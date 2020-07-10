#include "YSScope.h"
#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

// 创建与可观察对象具有相同寿命周期的一次性资源
YSScope::YSScope(QObject *parent) : QObject(parent)
{
    typedef resource<std::vector<int>> resource;
    auto resource_factory = []() { return resource(rxcpp::util::to_vector({1, 2, 3, 4, 5})); };
    auto observable_factory = [](resource res) { return rxcpp::observable<>::iterate(res.get()); };
    auto values = rxcpp::observable<>::scope(resource_factory, observable_factory);

    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
