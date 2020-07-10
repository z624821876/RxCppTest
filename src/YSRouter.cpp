#include "YSRouter.h"

YSRouter::YSRouter(QObject *parent) : QObject(parent) {}

void YSRouter::regist(QString key, std::function<void()> func)
{
    map.insert(key, func);
}

void YSRouter::show(QString key)
{
    if (map.contains(key)) {
        std::function<void()> func = map[key];
        func();
    }
}
