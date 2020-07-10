#ifndef YSZIP_H
#define YSZIP_H

#include <QObject>

class YSZip : public QObject
{
    Q_OBJECT
public:
    explicit YSZip(QObject *parent = nullptr);

    void zip();

    void zip_selector();
signals:
};

#endif // YSZIP_H
