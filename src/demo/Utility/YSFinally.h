#ifndef YSFINALLY_H
#define YSFINALLY_H

#include <QObject>

class YSFinally : public QObject
{
    Q_OBJECT
public:
    explicit YSFinally(QObject *parent = nullptr);

signals:

};

#endif // YSFINALLY_H
