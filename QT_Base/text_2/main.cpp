#include "mainwindow.h"

#include <QApplication>


/// @brief 窗口坐标系的关系 创建按钮 按钮大小 按钮位置


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
