#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "主线程对象地址: " << QThread::currentThread();

    // 创建子线程
    Generate* subThread = new Generate;
    BubbleSort* bubble = new BubbleSort;
    QuickSort* quick = new QuickSort;

    connect(this, &MainWindow::starting, subThread, &Generate::curNumber);
    /// @brief 按下 the_run 生成随机数的子线程启动
    connect(ui -> the_run, &QPushButton::clicked, this, [=]()
    {
        emit starting(1000); // 发出信号
        subThread->start(); // 启动子线程
    });

    /// @brief 接受信号
    connect(subThread, &Generate::sendArray, bubble, &BubbleSort::curArray);
    connect(subThread, &Generate::sendArray, quick, &QuickSort::curArray);

    // 接收子线程的数据并在窗口显示
    connect(subThread, &Generate::sendArray, this, [=](QVector<int> list){
        bubble -> start();
        quick -> start();
        for(int i = 0; i < list.size(); ++i)
            ui -> the_new -> addItem(QString::number(list.at(i)));
    });
    // 接收子线程的数据并在窗口显示
    connect(bubble, &BubbleSort::finish, this, [=](QVector<int> list){
        for(int i = 0; i < list.size(); ++i)
            ui -> the_1 -> addItem(QString::number(list.at(i)));
    });
    // 接收子线程的数据并在窗口显示
    connect(quick, &QuickSort::finish, this, [=](QVector<int> list){
        for(int i = 0; i < list.size(); ++i)
            ui -> the_2 -> addItem(QString::number(list.at(i)));
    });

    /// @brief 线程资源释放
    connect(this, &MainWindow::destroyed, this, [=](){
        subThread -> quit();
        subThread -> wait();
        subThread -> deleteLater();
        bubble -> quit();
        bubble -> wait();
        bubble -> deleteLater();
        quick -> quit();
        quick -> wait();
        quick -> deleteLater();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
