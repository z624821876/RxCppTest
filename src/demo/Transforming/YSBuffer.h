#ifndef YSTRANSFORMING_H
#define YSTRANSFORMING_H

#include <QObject>

class YSBuffer : public QObject
{
    Q_OBJECT
public:
    explicit YSBuffer(QObject *parent = nullptr);

    void buffer();

    void bufferWithTime();

    void bufferWithTimeOrCount();

    void pairwise();
signals:
};

#endif // YSTRANSFORMING_H
