#ifndef YSLOGINCONTROLLER_H
#define YSLOGINCONTROLLER_H

#include <QObject>

class YSLoginViewModel;
class YSLoginView;

class YSLoginViewController : public QObject
{
    Q_OBJECT
public:
    explicit YSLoginViewController(QObject *parent = nullptr);

    ~YSLoginViewController();

    void show();

    void release();
signals:

private:
    void bind();

    YSLoginView *loginView;

    YSLoginViewModel *loginViewModel;
};

#endif // YSLOGINCONTROLLER_H
