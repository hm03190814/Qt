#include "mainwindow.h"

#include <QApplication>

/// @brief 三个窗口类的特点

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
