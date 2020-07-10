#ifndef YSSCHEDULER_H
#define YSSCHEDULER_H

#include <QObject>

class YSScheduler : public QObject
{
    Q_OBJECT
public:
    explicit YSScheduler(QObject *parent = nullptr);

    void observeOn();

    void subscribeOn();
    void subscribeOn_observeOn();

    void scheduleTest();
    void scheduleTest1();
signals:
};

#endif // YSSCHEDULER_H
