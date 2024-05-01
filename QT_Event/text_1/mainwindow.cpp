#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QCloseEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// @brief 重写事件处理函数_closeEvent
void MainWindow::closeEvent(QCloseEvent *ev)
{
    int ret = QMessageBox::question(this, "提问", "您确定要关闭窗口吗");
    if(ret == QMessageBox::Yes){
        ev -> accept(); // 接受
    }else{
        ev -> ignore(); // 拒绝并传递给父窗口
    }
}

/// @brief 重写事件处理函数_resizeEvent
void MainWindow::resizeEvent(QResizeEvent* ev)
{
    qDebug() << "oldsize : " << ev -> oldSize() << "currSize : " << ev -> size(); 
}   
