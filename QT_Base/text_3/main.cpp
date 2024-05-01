#include "mainwindow.h"

#include <QApplication>

// 内存回收机制 子窗口先析构
// qDebug_打印数据
// QVariant_自定义结构体
// QVariant_自定义函数
// QLine
// QTime QDate QDateTime
// QElapsedTimer

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
