#include "YSLoginViewController.h"
#include "YSLoginView.h"
#include "YSLoginViewModel.h"
#include "YSMainViewController.h"
#include "src/Global.h"
#include "src/YSRouter.h"

#include <rxqt.hpp>
#include <QDebug>
#include <QLineEdit>
#include <QString>

using namespace rxcpp;
using namespace rxqt;

YSLoginViewController::YSLoginViewController(QObject *parent)
    : QObject(parent), loginView(new YSLoginView(this)), loginViewModel(new YSLoginViewModel(this))
{    
    //绑定
    bind();

    loginView->ui->account->setText(loginViewModel->account);
    loginView->ui->password->setText(loginViewModel->password);
}

YSLoginViewController::~YSLoginViewController()
{
    qDebug() << "~YSLoginViewController";
    delete loginView;
}

void YSLoginViewController::show()
{
    loginView->show();
}

void YSLoginViewController::release()
{
    qDebug() << "release";
    this->deleteLater();
}

void YSLoginViewController::bind()
{
    // 监听登录接口回调
    auto ob = loginViewModel->loginCompletedSignal.get_observable();
    ob.subscribe(
        [](int data) {
            // 获取登录成功数据
            qDebug() << "获取登录成功数据" << data;
        },
        [](std::exception_ptr eptr) { qDebug() << "OnError" << rxcpp::util::what(eptr).c_str(); },
        [=]() {
            // 登录成功  跳转页面
            qDebug() << "登录成功";
            YSRouter::instance().show(ROUTER_KEY_MAIN);

            // 关闭当前页面
            this->deleteLater();
        });

    // 输入框变化监听
    auto accountChangeSignal = from_signal(loginView->ui->account, &QLineEdit::textChanged);
    auto passwordChangeSignal = from_signal(loginView->ui->password, &QLineEdit::textChanged);

    accountChangeSignal.combine_latest(passwordChangeSignal)
        .map([](std::tuple<QString, QString> v) {
            QString account = std::get<0>(v);
            QString password = std::get<1>(v);

            if (account.length() == 11 && password.length() == 8) {
                return true;
            } else {
                return false;
            }
        })
        .subscribe([=](bool b) { loginView->ui->pushButton->setEnabled(b); });


    from_signal(loginView->ui->pushButton, &QPushButton::clicked).throttled(std::chrono::seconds(1)).subscribe([=](const auto &) {
//        loginViewModel->login();
        qDebug() << "点击登录";
    });
}
























