#include "YSError.h"

#include <rxcpp/rx.hpp>
#include <QDebug>

using namespace rxcpp;

YSError::YSError(QObject *parent) : QObject(parent)
{
    qDebug() << "error";
    error();

    qDebug() << "error";
    retry();
}

void YSError::error()
{
    auto observable = rxcpp::observable<>::error<int>(std::runtime_error("Error from source"));   
    observable.subscribe([](int v) { qDebug() << "onNext" << v; },
                         [](rxcpp::util::error_ptr ep) {
                             qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                         },
                         []() { qDebug() << "OnCompleted"; });
}

void YSError::retry()
{
    auto ob = observable<>::create<int>([](subscriber<int> s) {
                  s.on_next(1);
                  s.on_next(2);
                  s.on_next(3);
                  auto ePtr = std::make_exception_ptr(std::runtime_error("retry error"));
                  s.on_error(ePtr);
              }).retry(3);

    ob.subscribe([](int v) { qDebug() << "onNext" << v; },
                 [](rxcpp::util::error_ptr ep) {
                     qDebug() << "OnError" << rxcpp::util::what(ep).c_str();
                 },
                 []() { qDebug() << "OnCompleted"; });
}
