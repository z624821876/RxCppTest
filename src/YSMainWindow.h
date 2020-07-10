#ifndef YSMAINWINDOW_H
#define YSMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class YSMainWindow;
}

class YSMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit YSMainWindow(QWidget *parent = nullptr);
    ~YSMainWindow();

private:
    Ui::YSMainWindow *ui;
};

#endif // YSMAINWINDOW_H
