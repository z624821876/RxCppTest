#ifndef YSLOGINVIEWMODEL_H
#define YSLOGINVIEWMODEL_H

#include <rxcpp/rx.hpp>
#include <QObject>

class YSLoginModel;

class YSLoginViewModel : public QObject
{
    Q_OBJECT
public:
    explicit YSLoginViewModel(QObject *parent = nullptr);

    void login();

    rxcpp::subjects::subject<int> loginCompletedSignal;

    QString account;

    QString password;

    void loadLoginInfo();

    void saveLoginInfo();
};

#endif // YSLOGINVIEWMODEL_H
