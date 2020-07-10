#ifndef YSAMB_H
#define YSAMB_H

#include <QObject>

class YSAmb : public QObject
{
    Q_OBJECT
public:
    explicit YSAmb(QObject *parent = nullptr);

    void amb();
signals:
};

#endif // YSAMB_H
