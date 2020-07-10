#ifndef YSSAMPLE_H
#define YSSAMPLE_H

#include <QObject>

class YSSample : public QObject
{
    Q_OBJECT
public:
    explicit YSSample(QObject *parent = nullptr);

signals:

};

#endif // YSSAMPLE_H
