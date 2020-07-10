#ifndef YSSCAN_H
#define YSSCAN_H

#include <QObject>

class YSScan : public QObject
{
    Q_OBJECT
public:
    explicit YSScan(QObject *parent = nullptr);

    void scan();
signals:

};

#endif // YSSCAN_H
