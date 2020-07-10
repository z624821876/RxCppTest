#include "YSBuffer.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;
using namespace std::chrono;

YSBuffer::YSBuffer(QObject *parent) : QObject(parent)
{
    //    qDebug() << "buffer";
    //    buffer();

    //    qDebug() << "bufferWithTime";
    //    bufferWithTime();

    //    qDebug() << "bufferWithTimeOrCount";
    //    bufferWithTimeOrCount();

    qDebug() << "pairwise";
    pairwise();
}

void YSBuffer::buffer()
{
    // buffer count
    auto ob = observable<>::range(0, 10);

    ob.buffer(2).subscribe(
        [](std::vector<int> v) {
            qDebug() << "OnNext";
            for (int a : v) {
                qDebug() << a;
            }
        },
        []() { qDebug() << "OnCompleted"; });

    // buffer count skip
    // count 代表几个数据作为一个包
    // skip 代表两组数据之间的间隔  默认间隔为count
    //    auto ob = observable<>::range(0, 10);

    //    ob.buffer(2, 2).subscribe(
    //        [](std::vector<int> v) {
    //            qDebug() << "OnNext";
    //            for (int a : v) {
    //                qDebug() << a;
    //            }
    //        },
    //        []() { qDebug() << "OnCompleted"; });
}

// 以时间为标准打包数据
void YSBuffer::bufferWithTime()
{
    auto ob = observable<>::range(0, 10);

    auto period = milliseconds(4);
    auto skip = milliseconds(6);

    // period
    ob.buffer_with_time(period).subscribe(
        [](std::vector<int> v) {
            qDebug() << "OnNext";
            for (int a : v) {
                qDebug() << a;
            }
        },
        []() { qDebug() << "OnCompleted"; });

    // period + skip
    ob.buffer_with_time(period, skip)
        .subscribe(
            [](std::vector<int> v) {
                qDebug() << "OnNext";
                for (int a : v) {
                    qDebug() << a;
                }
            },
            []() { qDebug() << "OnCompleted"; });

    // period + skip + coordination
    ob.buffer_with_time(period, skip, rxcpp::observe_on_new_thread())
        .subscribe(
            [](std::vector<int> v) {
                qDebug() << "OnNext";
                for (int a : v) {
                    qDebug() << a;
                }
            },
            []() { qDebug() << "OnCompleted"; });
}

// 以时间和数量作为触发条件，任意一个条件触发都会调用on_next()
void YSBuffer::bufferWithTimeOrCount()
{
    auto ob = observable<>::range(0, 10);

    auto period = milliseconds(4);

    // period + count + coordination(可选)
    ob.buffer_with_time_or_count(period, 2, rxcpp::observe_on_new_thread())
        .subscribe(
            [](std::vector<int> v) {
                qDebug() << "OnNext";
                for (int a : v) {
                    qDebug() << a;
                }
            },
            []() { qDebug() << "OnCompleted"; });
}

// pairwise 每两个组合成一个元组 等价于 buffer(2, 1)
void YSBuffer::pairwise()
{
    auto ob = observable<>::range(0, 10);

    // 注意just只有一个数据 不会触发onNext  会直接触发OnCompleted
    //    auto ob = observable<>::just(1);

    ob.pairwise().subscribe(
        [](std::tuple<int, int> v) {
            qDebug() << "OnNext";

            int first = std::get<0>(v);
            int second = std::get<1>(v);
            qDebug() << first << second;
        },
        []() { qDebug() << "OnCompleted"; });
}
