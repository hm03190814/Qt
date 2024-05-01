#include "mainwindow.h"

#include <QApplication>


/// @brief QPushButton按钮类
/// @brief QToolButton按钮类

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
