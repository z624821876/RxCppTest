#ifndef YSMAINCELLMODEL_H
#define YSMAINCELLMODEL_H

#include <QObject>

struct YSMainCellModel
{
    QString userId;

    QString userName;

    QString EnglishName;

    YSMainCellModel()
    {
        userId = "id";

        userName = "userName";

        EnglishName = "EnglishName";
    }
};

struct YSMainCellViewModel {

public:
    YSMainCellViewModel() {
        labelText = "";
    }

    YSMainCellViewModel(struct YSMainCellModel model) {
        labelText = QString("%1---%1---%1").arg(model.userId).arg(model.userName).arg(model.EnglishName);
    };

    QString labelText;

};

Q_DECLARE_METATYPE(YSMainCellViewModel)

#endif // YSMAINCELLMODEL_H
