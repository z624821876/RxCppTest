#include "YSMainViewController.h"
#include "YSMainView.h"
#include "YSMainViewModel.h"
#include "YSMainCellViewModel.h"

#include <rxqt.hpp>

YSMainViewController::YSMainViewController(QObject *parent)
    : QObject(parent), mainView(new YSMainView(this)), mainViewModel(new YSMainViewModel(this))
{
    mainViewModel->loadDataSignal.get_observable().subscribe([=](int v) {

        mainView->ui->listWidget->clear();

        for (struct YSMainCellViewModel model : mainViewModel->dataSource) {

            QListWidgetItem *add_item = new QListWidgetItem(mainView->ui->listWidget);
            add_item->setText(model.labelText);
            mainView->ui->listWidget->addItem(add_item);
        }
    });

    rxqt::from_signal(mainView->ui->refresh, &QPushButton::clicked).subscribe([=](bool checked) {
        mainViewModel->loadData(false);
    });
    rxqt::from_signal(mainView->ui->loadMore, &QPushButton::clicked).subscribe([=](bool checked) {
        mainViewModel->loadData(true);
    });
}

YSMainViewController::~YSMainViewController()
{
    delete mainView;
}

void YSMainViewController::show()
{
    mainView->show();
}

void YSMainViewController::release()
{
    this->deleteLater();
}
