#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 开始默认显示_toolBox抽屉盒子_的哪个页面
    ui -> toolBox -> setCurrentIndex(0);
    // ui -> toolBox -> setCurrentWidget(ui -> the_1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// @brief toolBox 类
void MainWindow::on_toolBox_currentChanged(int index)
{
    qDebug() << ui -> toolBox -> itemText(index);
}

