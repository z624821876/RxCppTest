#include "YSObservable.h"

//#include <rxcpp/rx.hpp>
#include <rxcpp/rx.hpp>

#include <QDebug>

YSObservable::YSObservable(QObject *parent) : QObject(parent)
{
    qDebug() << "create example";
    create();

    qDebug() << "from example";
    from();

    qDebug() << "range example";
    range();

    qDebug() << "defer example";
    defer();

    qDebug() << "empty example";
    empty();

    //    qDebug() << "never example";
    //    never();

    qDebug() << "error example";
    error();

    //    qDebug() << "interval example";
    //    interval();

    qDebug() << "just example";
    just();

    qDebug() << "repeat example";
    repeat();

    //    qDebug() << "timer example";
    //    timer();

    qDebug() << "start_with example";
    start_with();
}

// create 通过一个闭包创建可观察序列，订阅后闭包才会执行
void YSObservable::create()
{
    // completed、error只会触发一个 并且会立马结束可观察序列
    auto ints = rxcpp::observable<>::create<int>([](rxcpp::subscriber<int> s) {
        s.on_next(1);
        s.on_next(2);
        s.on_completed();
        s.on_error(std::exception_ptr());
    });
    ints.subscribe([](int v) { qDebug() << "OnNext" << v; },
                   [](std::exception_ptr ep) {
                       try {
                           std::rethrow_exception(ep);
                       } catch (const rxcpp::empty_error &ex) {
                           qDebug() << ex.what();
                       }
                   },
                   []() { qDebug() << "OnCompleted"; });

    // 自定义观察者
    //    auto subscription = rxcpp::composite_subscription();
    //    auto subscriber = rxcpp::make_subscriber<int>(
    //        subscription,
    //        [&](int v) {
    //            qDebug() << "OnNext" << v;
    //            // 取消订阅
    //            if (v == 2)
    //                subscription.unsubscribe();
    //        },
    //        []() { qDebug() << "OnCompleted"; });
    //    rxcpp::observable<>::create<int>([](rxcpp::subscriber<int> s) {
    //        for (int i = 0; i < 5; ++i) {
    //            s.on_next(i);
    //        }
    //        s.on_completed();
    //    }).subscribe(subscriber);

    // 控制终止条件
    //    auto subscription = rxcpp::composite_subscription();
    //    auto subscriber = rxcpp::make_subscriber<int>(
    //        subscription,
    //        [&](int v) {
    //            qDebug() << "OnNext" << v;
    //            // 取消订阅
    //            if (v == 2)
    //                subscription.unsubscribe();
    //        },
    //        []() { qDebug() << "OnCompleted"; });
    //    rxcpp::observable<>::create<int>([](rxcpp::subscriber<int> s) {
    //        for (int i = 0; i < 5; ++i) {
    //            if (!s.is_subscribed()) // Stop emitting if nobody is listening
    //                break;
    //            s.on_next(i);
    //        }
    //        s.on_completed();
    //    }).subscribe(subscriber);
}

// from 将其他一些对象或数据结构转为可观察序列
void YSObservable::from()
{
    qDebug() << "from example";
    auto observable = rxcpp::observable<>::from(QString("123"));

    observable.subscribe([](QString v) { qDebug() << "onNext" << v; },
                         [](std::exception_ptr ep) {
                             try {
                                 std::rethrow_exception(ep);
                             } catch (const rxcpp::empty_error &ex) {
                                 qDebug() << ex.what();
                             }
                         },
                         []() { qDebug() << "OnCompleted"; });
}

// range  通过一个范围创建可观察序列
void YSObservable::range()
{
    // 1. 可观察序列   订阅者
    auto observable = rxcpp::observable<>::range(1, 12);
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](std::exception_ptr ep) {
                             try {
                                 std::rethrow_exception(ep);
                             } catch (const rxcpp::empty_error &ex) {
                                 printf("OnError: %s\n", ex.what());
                             }
                         },
                         []() { qDebug() << "OnCompleted"; });
}

// defer 延迟创建观察序列，被订阅时，内部才会调用闭包创建观察序列
void YSObservable::defer()
{
    auto observable_factory = []() {
        qDebug() << "2. 创建可观察序列";
        return rxcpp::observable<>::range(1, 3);
    };
    auto values = rxcpp::observable<>::defer(observable_factory);
    qDebug() << "1. 订阅信号";
    values.subscribe([](int v) { qDebug() << "onNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// empty 被订阅后直接发送completed事件
void YSObservable::empty()
{
    auto observable = rxcpp::observable<>::empty<int>();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         []() { qDebug() << "OnCompleted"; });
}

// never  一个不发送任何事件的信号，也不会暂停
void YSObservable::never()
{
    auto observable = rxcpp::observable<>::never<int>();
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         []() { qDebug() << "OnCompleted"; });
}

// error  被订阅后直接发送error事件
void YSObservable::error()
{
    auto observable = rxcpp::observable<>::error<int>(std::runtime_error("Error from source"));
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](rxcpp::util::error_ptr ep) {
                             qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                         },
                         []() { qDebug() << "OnCompleted"; });
}

// interval 定时器
void YSObservable::interval()
{
    using namespace std::chrono;

    auto values = rxcpp::observable<>::interval(milliseconds(1));
    values.subscribe([&](int v) { qDebug() << "OnNext" << v; },
                     [](std::exception_ptr ep) {
                         try {
                             std::rethrow_exception(ep);
                         } catch (const std::exception &ex) {
                             qDebug() << ex.what();
                         }
                     },
                     []() { qDebug() << "OnCompleted"; });

    // 延迟触发
    // start + period
    //    auto start = steady_clock::now() + milliseconds(1);
    //    auto period = std::chrono::milliseconds(1);
    //    auto values = rxcpp::observable<>::interval(start, period);

    //    values.subscribe([&](int v) { qDebug() << "OnNext" << v; },
    //                     [](std::exception_ptr ep) {
    //                         try {
    //                             std::rethrow_exception(ep);
    //                         } catch (const std::exception &ex) {
    //                             qDebug() << ex.what();
    //                         }
    //                     },
    //                     []() { qDebug() << "OnCompleted"; });

    // 获取时间
    //    typedef rxcpp::schedulers::scheduler::clock_type::time_point::duration duration_type;
    //    auto values = rxcpp::observable<>::interval(milliseconds(1)).time_interval();
    //    values.subscribe(
    //        [&](duration_type v) {
    //            long long int ms = duration_cast<milliseconds>(v).count();
    //            qDebug() << "OnNext" << ms << "ms";
    //        },
    //        [](std::exception_ptr ep) {
    //            try {
    //                std::rethrow_exception(ep);
    //            } catch (const std::exception &ex) {
    //                qDebug() << ex.what();
    //            }
    //        },
    //        []() { qDebug() << "OnCompleted"; });
}

// just 可以包装一个数据，被订阅后，直接发送next事件和completed事件
void YSObservable::just()
{
    auto observable = rxcpp::observable<>::just<int>(10);
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

// repeat  无限重复发送指定数据，注意阻塞主线程
void YSObservable::repeat()
{
    // repeat() 无限循环   repeat(n) 循环N次
    auto observable = rxcpp::observable<>::from(1, 2, 3).repeat(3);

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

// timer 定时延后执行
void YSObservable::timer()
{
    using namespace std::chrono;
    // 延迟调用  会阻塞线程
    qDebug() << "延迟调用";
    //    auto start = steady_clock::now() + seconds(10);
    //    auto values = rxcpp::observable<>::timer(start);
    //    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });

    // 同上
    //    auto values1 = rxcpp::observable<>::timer(seconds(10));
    //    values1.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });

    // 子线程 延迟调用 不会阻塞
    //    auto scheduler = rxcpp::observe_on_new_thread();
    //    auto start = scheduler.now() + seconds(10);
    //    auto values2 = rxcpp::observable<>::timer(start, scheduler);
    //    values2.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });

    // 同上
    auto scheduler = rxcpp::observe_on_new_thread();
    auto values3 = rxcpp::observable<>::timer(seconds(10), scheduler);
    values3.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}

// start_with 在序列前增加数据
void YSObservable::start_with()
{
    //    auto observable = rxcpp::observable<>::range(10, 12);
    //    auto values = rxcpp::observable<>::start_with(observable, 1, 2, 3);
    //    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });

    // 同上
    auto values = rxcpp::observable<>::range(10, 12).start_with(1, 2, 3);
    values.subscribe([](int v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
