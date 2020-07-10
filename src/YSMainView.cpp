#include "YSMainView.h"
#include "YSMainViewController.h"

#include <QCloseEvent>

YSMainView::YSMainView(YSMainViewController *controller) :
      ui(new Ui::YSMainView),
      controller(controller)
{
    ui->setupUi(this);
}

YSMainView::~YSMainView()
{
    delete ui;
}

void YSMainView::closeEvent(QCloseEvent *event)
{
    event->ignore();
    controller->release();
}
