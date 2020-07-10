#ifndef YSSKIP_H
#define YSSKIP_H

#include <QObject>

class YSSkip : public QObject
{
    Q_OBJECT
public:
    explicit YSSkip(QObject *parent = nullptr);

    void skip();

    void skip_last();

    void skip_util();

    void skip_while();
signals:
};

#endif // YSSKIP_H
