#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->win_1, &QPushButton::clicked, this, [=](){
        ui -> stackedWidget -> setCurrentIndex(1); // 按动按钮_win_1_显示 Index=1 的
    });
    connect(ui->win_2, &QPushButton::clicked, this, [=](){
        ui -> stackedWidget -> setCurrentWidget(ui -> _2); // 按动按钮_win_2_显示 叫做_2 的
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
