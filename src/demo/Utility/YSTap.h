#ifndef YSTAP_H
#define YSTAP_H

#include <QObject>

class YSTap : public QObject
{
    Q_OBJECT
public:
    explicit YSTap(QObject *parent = nullptr);

    void tap();

    void tap_error();
signals:
};

#endif // YSTAP_H
