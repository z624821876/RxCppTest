#ifndef YSDELAY_H
#define YSDELAY_H

#include <QObject>

class YSDelay : public QObject
{
    Q_OBJECT
public:
    explicit YSDelay(QObject *parent = nullptr);

    void delay();
signals:
};

#endif // YSDELAY_H
