#ifndef YSGROUPBY_H
#define YSGROUPBY_H

#include <QObject>

class YSGroupBy : public QObject
{
    Q_OBJECT
public:
    explicit YSGroupBy(QObject *parent = nullptr);

    void group_by();

    void groupBy_and_sort();
signals:

};

#endif // YSGROUPBY_H
