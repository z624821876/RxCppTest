#ifndef YSOBSERVEON_H
#define YSOBSERVEON_H

#include <QObject>

class YSObserveOn : public QObject
{
    Q_OBJECT
public:
    explicit YSObserveOn(QObject *parent = nullptr);

signals:

};

#endif // YSOBSERVEON_H
