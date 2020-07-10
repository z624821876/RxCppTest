#ifndef YSMAP_H
#define YSMAP_H

#include <QObject>

class YSMap : public QObject
{
    Q_OBJECT
public:
    explicit YSMap(QObject *parent = nullptr);

    void map();
signals:

};

#endif // YSMAP_H
