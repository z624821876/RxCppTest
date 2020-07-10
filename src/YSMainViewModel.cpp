#include "YSMainViewModel.h"
#include "YSMainCellViewModel.h"

YSMainViewModel::YSMainViewModel(QObject *parent)
    : QObject(parent), loadDataSignal(rxcpp::subjects::subject<int>())
{}

void YSMainViewModel::loadData(bool loadMore)
{
    if (!loadMore) {
        dataSource.clear();
    }

    // 1. 获取数据
    // 网络请求或者本地数据
    // 伪代码 代表网络请求数据
    QVector<struct YSMainCellModel> data;
    for (int i = 0; i < 10; ++i) {
        struct YSMainCellModel model = YSMainCellModel();
        data.append(model);
    }

    // 2. 更新listModel
    for (struct YSMainCellModel model : data) {
        struct YSMainCellViewModel viewModel(model);
        dataSource.append(viewModel);
    }

    loadDataSignal.get_subscriber().on_next(1);
}
