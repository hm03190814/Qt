#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <QPaintEvent>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui -> the_button, &MyButton::the_clicked, this, [=](){
        qDebug() << "1111";
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
