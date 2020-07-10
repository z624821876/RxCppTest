#ifndef YSSUBJECT_H
#define YSSUBJECT_H

#include <QObject>

class YSSubject : public QObject
{
    Q_OBJECT
public:
    explicit YSSubject(QObject *parent = nullptr);

    void subject();

    void behaviorSubject();

    void replaySubject();

    void synchronizeSubject();
signals:
};

#endif // YSSUBJECT_H
