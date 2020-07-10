#include "YSScheduler.h"

#include <rxcpp/rx.hpp>
#include <QDebug>
#include <QEventLoop>
#include <QThread>

using namespace rxcpp;
using namespace std::chrono;

// 特定调度程序
//identity_immediate()
//identity_current_thread()
//identity_same_worker(worker w)
//serialize_event_loop()
//serialize_new_thread()
//serialize_same_worker(worker w)
//observe_on_event_loop()
//observe_on_new_thread()

YSScheduler::YSScheduler(QObject *parent) : QObject(parent)
{
    //    qDebug() << "observeOn";
    //    observeOn();

    //    qDebug() << "subscribeOn";
    //    subscribeOn();

    qDebug() << "subscribeOn_observeOn";
    subscribeOn_observeOn();
    qDebug() << "subscribeOn_observeOn_end";

    //    qDebug() << "scheduleTest";
    //    scheduleTest();
}

void YSScheduler::scheduleTest()
{
    //---------- Get a Coordination
    auto coordination = serialize_new_thread();

    //------- Create a Worker instance
    auto worker = coordination.create_coordinator().get_worker();

    auto sub_action = schedulers::make_action([](const rxcpp::schedulers::schedulable &) {
        qDebug() << QString("Action Executed in Thread # : %1")
                        .arg(quintptr(QThread::currentThreadId()));
    });

    auto scheduled = schedulers::make_schedulable(worker, sub_action);
    scheduled.schedule();

    qDebug() << QString("main Thread # : %1").arg(quintptr(QThread::currentThreadId()));
    rxcpp::observable<>::timer(std::chrono::milliseconds(2000)).subscribe([&](long) {});
}

void YSScheduler::scheduleTest1()
{
    auto coordination = identity_current_thread();
    auto worker = coordination.create_coordinator().get_worker();
    auto start = coordination.now() + milliseconds(1);
    auto period = milliseconds(1);
    auto values = observable<>::interval(start, period).take(5).replay(2, coordination);

    worker.schedule([&](const schedulers::schedulable &) {
        values.subscribe(
            [](long v) {
                qDebug() << QString("#1 --- %1 : %2")
                                .arg(quintptr(QThread::currentThreadId()))
                                .arg(v);
            },

            []() { printf("#1 --- OnCompleted\n"); });
    });

    worker.schedule([&](const schedulers::schedulable &) {
        values.subscribe(
            [](long v) {
                qDebug() << QString("#1 --- %1 : %2")
                                .arg(quintptr(QThread::currentThreadId()))
                                .arg(v);
            },

            []() { printf("#2 --- OnCompleted\n"); });
    });

    // Start emitting
    worker.schedule([&](const schedulers::schedulable &) { values.connect(); });

    // Add blocking subscription to see results
    values.as_blocking().subscribe();
}

// 控制回调在子线程调用
void YSScheduler::observeOn()
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

// 控制 Observable 在子线程执行
// 由于 Observable 在子线程执行  所以回调也会在子线程执行
void YSScheduler::subscribeOn()
{
    qDebug() << QString("[thread %1] Start task").arg(quintptr(QThread::currentThreadId()));
    auto values = rxcpp::observable<>::range(1, 3).map([](int v) {
        qDebug() << QString("[thread %1] -- map %1").arg(quintptr(QThread::currentThreadId())).arg(v);
        return v;
    });

    values.subscribe_on(synchronize_new_thread())
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

// 使用 identity_current_thread 没有生效 , 使用其他 schedule 可以生效。 暂时原因不明...

// 由于 Observable 在子线程执行  所以回调也会在子线程执行
// 所以可以通过 observeOn 让回调在主线程执行
void YSScheduler::subscribeOn_observeOn()
{
    qDebug() << QString("[thread %1] Start task").arg(quintptr(QThread::currentThreadId()));
    auto values = rxcpp::observable<>::range(1, 3).map([](int v) {
        qDebug() << QString("[thread %1] -- map %1").arg(quintptr(QThread::currentThreadId())).arg(v);
        return v;
    });

    auto main_thread = identity_current_thread();
    auto worker_thread = synchronize_new_thread();

    values.subscribe_on(worker_thread)
        .observe_on(main_thread)
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
