#ifndef YSDISTINCT_H
#define YSDISTINCT_H

#include <QObject>

class YSDistinct : public QObject
{
    Q_OBJECT
public:
    explicit YSDistinct(QObject *parent = nullptr);

    void distinct();

    void distinct_until_changed();
signals:
};

#endif // YSDISTINCT_H
