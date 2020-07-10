#ifndef YSROUTER_H
#define YSROUTER_H

#include <QMap>
#include <QObject>
#include <QVector>

class YSRouter : public QObject
{
    Q_OBJECT
public:
    static YSRouter &instance()
    {
        static YSRouter client;

        return client;
    }

    void regist(QString key, std::function<void()> func);

    void show(QString key);

private:
    QMap<QString, std::function<void()>> map;

    explicit YSRouter(QObject *parent = nullptr);
};

#endif // YSROUTER_H
