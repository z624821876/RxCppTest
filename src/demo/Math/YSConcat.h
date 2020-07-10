#ifndef YSCONCAT_H
#define YSCONCAT_H

#include <QObject>

class YSConcat : public QObject
{
    Q_OBJECT
public:
    explicit YSConcat(QObject *parent = nullptr);

    void concatSample();

    void implicitConcatSample();
signals:
};

#endif // YSCONCAT_H
