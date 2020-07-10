#ifndef YSWINDOW_H
#define YSWINDOW_H

#include <QObject>

class YSWindow : public QObject
{
    Q_OBJECT
public:
    explicit YSWindow(QObject *parent = nullptr);

    void window();
signals:

};

#endif // YSWINDOW_H
