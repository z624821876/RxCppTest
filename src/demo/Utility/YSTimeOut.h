#ifndef YSTIMEOUT_H
#define YSTIMEOUT_H

#include <QObject>

class YSTimeOut : public QObject
{
    Q_OBJECT
public:
    explicit YSTimeOut(QObject *parent = nullptr);

signals:

};

#endif // YSTIMEOUT_H
