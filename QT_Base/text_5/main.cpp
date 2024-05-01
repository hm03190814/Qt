#include "mainwindow.h"

#include <QApplication>

/// @brief 自定义信号与槽

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
// #include "main.moc"