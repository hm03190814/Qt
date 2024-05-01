#include "mainwindow.h"

#include <QApplication>

/// @brief 定时器的使用

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
