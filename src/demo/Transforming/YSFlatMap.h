#ifndef YSFLATMAP_H
#define YSFLATMAP_H

#include <QObject>

class YSFlatMap : public QObject
{
    Q_OBJECT
public:
    explicit YSFlatMap(QObject *parent = nullptr);

    void flat_map();

    void concat_map();
signals:
};

#endif // YSFLATMAP_H
