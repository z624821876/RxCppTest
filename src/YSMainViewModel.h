#ifndef YSMAINVIEWMODEL_H
#define YSMAINVIEWMODEL_H

#include <rxcpp/rx.hpp>
#include <QObject>
#include <QVector>

#include "YSMainCellViewModel.h"

class YSMainViewModel : public QObject
{
    Q_OBJECT
public:
    explicit YSMainViewModel(QObject *parent = nullptr);

    rxcpp::subjects::subject<int> loadDataSignal;

    QVector<struct YSMainCellViewModel> dataSource;

    void loadData(bool loadMore);

};

#endif // YSMAINVIEWMODEL_H
