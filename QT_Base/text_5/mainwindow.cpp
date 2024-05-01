#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_me = new me;
    m_girl = new girl;
    
    /// @brief 按下当前窗口的hungry按钮 运行 MainWindow::hungryslot() 让女生发出饿了的信号
    connect(ui->hungry, &QPushButton::clicked, this, &MainWindow::hungryslot);

    /// @brief 按下当前窗口的hungry按钮 运行 MainWindow::just_run() 直接处理
    connect(ui->hungry, &QPushButton::clicked, this, &MainWindow::just_run);

    /// @brief 使用_QT5_进行_connect 女生发出饿了的信号 我就去带女生吃饭
    void (girl::*hungry_0)() = &girl::hungry;
    void (girl::*hungry_1)(QString) = &girl::hungry;
    void (me::*eat_0)() = &me::eat;
    void (me::*eat_1)(QString) = &me::eat;
    connect(m_girl, hungry_0, m_me, eat_0);
    connect(m_girl, hungry_1, m_me, eat_1);

    /// @brief 使用_QT4_进行_connect 女生发出饿了的信号 我就去带女生吃饭
    connect(m_girl, SIGNAL(hungry()), m_me, SLOT(eat()));
    connect(m_girl, SIGNAL(hungry(QString)), m_me, SLOT(eat(QString)));

    /// @brief 按下当前窗口的close_window按钮 关闭当前窗口
    connect(ui->close_window, &QPushButton::clicked, this, &MainWindow::close);


    /// @brief lambda_正则表达式
    int a = 100, b = 200, c = 300;
    [&](){
        qDebug() << "a+1 = " << a++ << " b + c = " << b + c ;
    }();

    [=](int m, int n)mutable{
        qDebug() << "m + n = " << m + n ;
    }(1, 2);

    /// @brief 使用_lambda_正则表达式 按下当前窗口的hungry按钮 运行 MainWindow::hungryslot() 让女生发出饿了的信号
    connect(ui->hungry, &QPushButton::clicked, this, [=](){
        emit m_girl -> hungry();
        emit m_girl -> hungry("面条");
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hungryslot()
{
    /// @brief 发射自定义信号
    emit m_girl -> hungry();
    emit m_girl -> hungry("面条");
}

void MainWindow::just_run()
{
    /// @brief 按下按钮直接处理
    qDebug() << "按下按钮直接处理";
}