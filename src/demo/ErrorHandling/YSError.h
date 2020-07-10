#ifndef YSERROR_H
#define YSERROR_H

#include <QObject>

class YSError : public QObject
{
    Q_OBJECT
public:
    explicit YSError(QObject *parent = nullptr);

    void error();

    void retry();
signals:
};

#endif // YSERROR_H
