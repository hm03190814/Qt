#include "mainwindow.h"

#include <QApplication>

/// @brief 

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
