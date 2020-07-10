#ifndef YSDEBOUNCE_H
#define YSDEBOUNCE_H

#include <QObject>

class YSDebounce : public QObject
{
    Q_OBJECT
public:
    explicit YSDebounce(QObject *parent = nullptr);

signals:

};

#endif // YSDEBOUNCE_H
