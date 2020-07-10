#include "YSSubject.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSSubject::YSSubject(QObject *parent) : QObject(parent)
{
    qDebug() << "subject example";
    subject();

    qDebug() << "behaviorSubject example";
    behaviorSubject();

    qDebug() << "replaySubject example";
    replaySubject();

    qDebug() << "synchronizeSubject example";
    synchronizeSubject();
}

// 最基础的热信号 可以作为可观察序列  可以主动发送事件
void YSSubject::subject()
{
    auto subject = subjects::subject<int>();

    auto observable = subject.get_observable();

    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](std::exception_ptr ep) {
                             try {
                                 std::rethrow_exception(ep);
                             } catch (const rxcpp::empty_error &ex) {
                                 qDebug() << ex.what();
                             }
                         },
                         []() { qDebug() << "OnCompleted"; });
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](std::exception_ptr ep) {
                             try {
                                 std::rethrow_exception(ep);
                             } catch (const rxcpp::empty_error &ex) {
                                 qDebug() << ex.what();
                             }
                         },
                         []() { qDebug() << "OnCompleted"; });

    auto subscriber = subject.get_subscriber();
    subscriber.on_next(1);
    subscriber.on_next(2);
    subscriber.on_next(3);
    subscriber.on_completed();

    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](std::exception_ptr ep) {
                             try {
                                 std::rethrow_exception(ep);
                             } catch (const rxcpp::empty_error &ex) {
                                 qDebug() << ex.what();
                             }
                         },
                         []() { qDebug() << "OnCompleted"; });
}

// 将一个值包装成热信号 每次被订阅都会发送原始数据
void YSSubject::behaviorSubject()
{
    auto subject = subjects::behavior<int>(0);

    qDebug() << subject.get_value();

    auto observable = subject.get_observable();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; });

    auto subscriber = subject.get_subscriber();
    subscriber.on_next(1);
    subscriber.on_next(2);

    qDebug() << subject.get_value();

    observable.subscribe([](int v) { qDebug() << "onNext" << v; });
}

// 重播，可以设置重播次数
void YSSubject::replaySubject()
{
    auto subject = new subjects::replay<int, observe_on_one_worker>(5, observe_on_new_thread());
    auto observable = subject->get_observable();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; });

    auto subscriber = subject->get_subscriber();
    subscriber.on_next(1);
    subscriber.on_next(2);
    subscriber.on_next(3);
    subscriber.on_next(4);
    subscriber.on_next(5);
    subscriber.on_next(6);
    subscriber.on_next(7);
    subscriber.on_next(8);
    subscriber.on_completed();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; });

    // 阻塞 要不然上面收不到数据
    observable.as_blocking().subscribe();
}

// 保证所有观察者获取的数据一样
void YSSubject::synchronizeSubject()
{
    auto subject = subjects::synchronize<int, observe_on_one_worker>(observe_on_event_loop());
    auto observable = subject.get_observable();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; });

    auto subscriber = subject.get_subscriber();
    subscriber.on_next(1);
    subscriber.on_next(2);
    subscriber.on_next(3);
    subscriber.on_next(4);
    subscriber.on_next(5);
    subscriber.on_next(6);
    subscriber.on_next(7);
    subscriber.on_next(8);

    observable.subscribe([](int v) { qDebug() << "onNext" << v; });
    observable.subscribe([](int v) { qDebug() << "onNext" << v; });
}
