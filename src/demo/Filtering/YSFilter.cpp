#include "YSFilter.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSFilter::YSFilter(QObject *parent) : QObject(parent)
{
    auto ob = observable<>::range(0, 10);

    ob.filter([](int v) {
          return v % 2 == 0;
      }).subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
