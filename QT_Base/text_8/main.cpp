#include "mainwindow.h"

#include <QApplication>
#include "login.h"

/// @brief 窗口布局举例

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login login_window;
    login_window.exec();
    
    MainWindow w;
    w.show();
    return a.exec();
}
