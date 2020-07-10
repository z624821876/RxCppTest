#ifndef YSCOMBINELATEST_H
#define YSCOMBINELATEST_H

#include <QObject>

class YSCombineLatest : public QObject
{
    Q_OBJECT
public:
    explicit YSCombineLatest(QObject *parent = nullptr);

    void combine_latest();

    void combine_latest_selector();

signals:
};

#endif // YSCOMBINELATEST_H
