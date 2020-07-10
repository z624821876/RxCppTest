#include "YSLoginViewModel.h"
#include "YSLoginModel.h"

YSLoginViewModel::YSLoginViewModel(QObject *parent)
    : QObject(parent), loginCompletedSignal(rxcpp::subjects::subject<int>())
{
    loadLoginInfo();
}

void YSLoginViewModel::loadLoginInfo()
{
    // 伪代码
    // 1. 从本地获取历史登录信息
    YSLoginModel loginModel;
    // 2. 解密
    account = loginModel.account;
    password = loginModel.password;
}

void YSLoginViewModel::saveLoginInfo()
{
    // 伪代码
    // 1. 对数据进行加密
    YSLoginModel loginModel;
    loginModel.account = loginModel.account;
    loginModel.password = loginModel.password;
    // 2. 将模型写入文件
}

void YSLoginViewModel::login()
{
    // 发起登录请求

    // 请求成功

    int data = 1;
    loginCompletedSignal.get_subscriber().on_next(data);
    loginCompletedSignal.get_subscriber().on_completed();
    saveLoginInfo();

    // 请求失败
    auto ePtr = std::make_exception_ptr(std::runtime_error("请求失败...."));
    loginCompletedSignal.get_subscriber().on_error(ePtr);
}
