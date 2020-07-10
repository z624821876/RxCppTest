/********************************************************************************
** Form generated from reading UI file 'YSMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YSMAINWINDOW_H
#define UI_YSMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_YSMainWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *YSMainWindow)
    {
        if (YSMainWindow->objectName().isEmpty())
            YSMainWindow->setObjectName(QString::fromUtf8("YSMainWindow"));
        YSMainWindow->resize(800, 600);
        centralwidget = new QWidget(YSMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        YSMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(YSMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        YSMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(YSMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        YSMainWindow->setStatusBar(statusbar);

        retranslateUi(YSMainWindow);

        QMetaObject::connectSlotsByName(YSMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *YSMainWindow)
    {
        YSMainWindow->setWindowTitle(QApplication::translate("YSMainWindow", "YSMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class YSMainWindow: public Ui_YSMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YSMAINWINDOW_H
