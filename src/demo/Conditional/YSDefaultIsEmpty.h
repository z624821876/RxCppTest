#ifndef YSDEFAULTISEMPTY_H
#define YSDEFAULTISEMPTY_H

#include <QObject>

class YSDefaultIsEmpty : public QObject
{
    Q_OBJECT
public:
    explicit YSDefaultIsEmpty(QObject *parent = nullptr);

    void defaultIfEmpty();

    void switchIfEmpty();
signals:
};

#endif // YSDEFAULTISEMPTY_H
