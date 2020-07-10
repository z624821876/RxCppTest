#ifndef YSLOGINMODEL_H
#define YSLOGINMODEL_H

#include <QObject>

class YSLoginModel : public QObject
{
    Q_OBJECT
public:
    explicit YSLoginModel(QObject *parent = nullptr);

    QString account;

    QString password;

signals:
};

#endif // YSLOGINMODEL_H
