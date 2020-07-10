#ifndef YSTAKE_H
#define YSTAKE_H

#include <QObject>

class YSTake : public QObject
{
    Q_OBJECT
public:
    explicit YSTake(QObject *parent = nullptr);

    void take();

    void take_util();

    void take_last();

    void take_while();

    void take_util_time();
signals:
};

#endif // YSTAKE_H
