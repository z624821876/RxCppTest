#include "YSLoginView.h"
#include "YSLoginViewController.h"

#include <rxcpp/rx.hpp>
#include <QCloseEvent>
#include <QDebug>

YSLoginView::YSLoginView(YSLoginViewController *controller) : ui(new Ui::YSLoginView), controller(controller)
{
    ui->setupUi(this);

    ui->pushButton->setEnabled(false);
}

YSLoginView::~YSLoginView()
{
    qDebug() << "~YSLoginView";
    delete ui;
}

void YSLoginView::closeEvent(QCloseEvent *event)
{
    event->ignore();
    controller->release();
}
