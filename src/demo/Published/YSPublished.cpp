#include "YSPublished.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSPublished::YSPublished(QObject *parent) : QObject(parent)
{
    //    qDebug() << "published";
    //    published();

    //    qDebug() << "ref_count";
    //    ref_count();

    //    qDebug() << "connect_forever";
    //    connect_forever();

    qDebug() << "replay";
    replay();
}

// 冷信号转热信号 connect之后开始执行
void YSPublished::published()
{
    auto published = observable<>::range(0, 10).publish();

    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    published.connect();
}

// 冷信号转热信号 第一次被订阅的时候执行
void YSPublished::ref_count()
{
    auto published = observable<>::range(0, 10).publish().ref_count();

    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    //    published.connect();
}

void YSPublished::connect_forever()
{
    auto published = observable<>::range(0, 10).publish();

    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });
    published.subscribe([](int v) { qDebug() << "onNext" << v; },
                        [](rxcpp::util::error_ptr ep) {
                            qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                        },
                        []() { qDebug() << "OnCompleted"; });

    published.connect_forever();
}

void YSPublished::replay()
{
    auto values = rxcpp::observable<>::interval(std::chrono::milliseconds(50)).take(10).replay(5);

    // Subscribe from the beginning
    values.subscribe([](long v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });

    // Start emitting
    values.connect();

    values.subscribe([](long v) { qDebug() << "OnNext" << v; }, []() { qDebug() << "OnCompleted"; });
}
