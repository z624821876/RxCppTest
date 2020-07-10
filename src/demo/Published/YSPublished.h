#ifndef YSPUBLISHED_H
#define YSPUBLISHED_H

#include <QObject>

class YSPublished : public QObject
{
    Q_OBJECT
public:
    explicit YSPublished(QObject *parent = nullptr);

    void published();

    void ref_count();

    void connect_forever();

    void replay();
signals:
};

#endif // YSPUBLISHED_H
