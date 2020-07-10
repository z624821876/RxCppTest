#ifndef YSMERGE_H
#define YSMERGE_H

#include <QObject>

class YSMerge : public QObject
{
    Q_OBJECT
public:
    explicit YSMerge(QObject *parent = nullptr);

    void merge();

    void merge_delay_error();
signals:
};

#endif // YSMERGE_H
