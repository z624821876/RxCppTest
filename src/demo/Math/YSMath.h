#ifndef YSMATHAVERAGE_H
#define YSMATHAVERAGE_H

#include <QObject>

class YSMath : public QObject
{
    Q_OBJECT
public:
    explicit YSMath(QObject *parent = nullptr);

    void average();

    void count();

    void max();

    void min();

    void sum();

    void reduce();

    void iterate();
signals:
};

#endif // YSMATHAVERAGE_H
