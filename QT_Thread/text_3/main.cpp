#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<QVector<int>>("QVector<int>"); // 防止电脑不识别 QVector<int>
    MainWindow w;
    w.show();
    return a.exec();
}
