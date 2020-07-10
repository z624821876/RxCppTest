#ifndef YSMAINVIEWCONTROLLER_H
#define YSMAINVIEWCONTROLLER_H

#include <QObject>

class YSMainView;
class YSMainViewModel;
class YSMainViewDelegate;

class YSMainViewController : public QObject
{
    Q_OBJECT
public:
    explicit YSMainViewController(QObject *parent = nullptr);

    ~YSMainViewController();

    void show();

    void release();

private:
    YSMainView *mainView;

    YSMainViewModel *mainViewModel;
};

#endif // YSMAINVIEWCONTROLLER_H
