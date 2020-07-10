#ifndef YSLOGINVIEW_H
#define YSLOGINVIEW_H

#include "ui_YSLoginView.h"
#include <QWidget>

class YSLoginViewController;

namespace Ui {
class YSLoginView;
}

class YSLoginView : public QWidget
{
    Q_OBJECT

public:

    YSLoginView(YSLoginViewController *controller);

    ~YSLoginView();

    void closeEvent(QCloseEvent *event) override;

    Ui::YSLoginView *ui;

private:
    YSLoginViewController   *controller;
};

#endif // YSLOGINVIEW_H
