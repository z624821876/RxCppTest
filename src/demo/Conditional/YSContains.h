#ifndef YSCONTAINS_H
#define YSCONTAINS_H

#include <QObject>

class YSContains : public QObject
{
    Q_OBJECT
public:
    explicit YSContains(QObject *parent = nullptr);

    void contains();

    void isEmpty();

    void exists();
signals:
};

#endif // YSCONTAINS_H
