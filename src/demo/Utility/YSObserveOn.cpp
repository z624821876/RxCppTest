#include "YSObserveOn.h"

#include <rxcpp/rx.hpp>
#include <QDebug>
#include <QThread>

using namespace rxcpp;

YSObserveOn::YSObserveOn(QObject *parent) : QObject(parent)
{
    qDebug() << QString("[thread %1] Start task").arg(quintptr(QThread::currentThreadId()));
    auto values = rxcpp::observable<>::range(1, 3).map([](int v) {
        qDebug() << QString("[thread %1] -- map %1").arg(quintptr(QThread::currentThreadId())).arg(v);
        return v;
    });
    values.observe_on(rxcpp::synchronize_new_thread())
        .as_blocking()
        .subscribe(
            [](int v) {
                qDebug() << QString("[thread %1] -- OnNext %1")
                                .arg(quintptr(QThread::currentThreadId()))
                                .arg(v);
            },
            []() {
                qDebug() << QString("[thread %1] -- OnCompleted")
                                .arg(quintptr(QThread::currentThreadId()));
            });
    qDebug() << QString("[thread %1] Finish task").arg(quintptr(QThread::currentThreadId()));
}
