#ifndef YSOBSERVABLE_H
#define YSOBSERVABLE_H

#include <QObject>

class YSObservable : public QObject
{
    Q_OBJECT
public:
    explicit YSObservable(QObject *parent = nullptr);

    void from();

    void create();

    void range();

    void defer();

    void empty();

    void never();

    void error();

    void interval();

    void just();

    void repeat();

    void timer();

    void start_with();
signals:
};

#endif // YSOBSERVABLE_H
