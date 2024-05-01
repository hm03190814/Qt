#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QPushButton"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> move(10, 10);

    // 创建按钮_A, 让这个按钮作为当前创建的字控件
    QPushButton* A = new QPushButton(this);
    A -> move(10 ,10);
    A -> setFixedSize(200, 200);

    // 创建按钮_b, 作为_A_的子控件
    QPushButton* B = new QPushButton(A);
    B -> move(10, 10);
    B -> setFixedSize(100, 100);

}

MainWindow::~MainWindow()
{
    delete ui;
}
