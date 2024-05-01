#include "mainwindow.h"

#include <QApplication>


/// @brief 功能实现 : 点击窗口上的关闭按钮, 关闭窗口

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
