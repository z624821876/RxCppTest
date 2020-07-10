#ifndef YSMAINVIEW_H
#define YSMAINVIEW_H

#include "ui_YSMainView.h"

#include <QWidget>

class YSMainViewController;

namespace Ui {
class YSMainView;
}

class YSMainView : public QWidget
{
    Q_OBJECT

public:
    YSMainView(YSMainViewController *controller);
    ~YSMainView();

    Ui::YSMainView *ui;

    void closeEvent(QCloseEvent *event) override;

private:
    YSMainViewController    *controller;
};

#endif // YSMAINVIEW_H
