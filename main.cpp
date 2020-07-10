#include "src/Global.h"
#include "src/YSLoginViewController.h"
#include "src/YSMainViewController.h"
#include "src/YSMainWindow.h"

#include <rxqt.hpp>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QScrollArea>
#include <QDebug>

#include "src/YSRouter.h"

using namespace std::chrono;

class Test {

public:
    Test() {

    }

    ~Test() {
        qDebug() << "释放";
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    rxqt::run_loop rxqt_run_loop;

    //    YSMainWindow w;
    //    w.show();

    YSRouter::instance().regist(ROUTER_KEY_LOGIN, []() {
        auto loginController = new YSLoginViewController();
        loginController->show();
    });
    YSRouter::instance().regist(ROUTER_KEY_MAIN, []() {
        auto mainController = new YSMainViewController();
        mainController->show();
    });

    YSRouter::instance().show(ROUTER_KEY_LOGIN);

    return a.exec();
}
