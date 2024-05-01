#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QDebug>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "主线程对象地址: " << QThread::currentThread();

    // 创建子线程对象
    QThread* t1 = new QThread;
    QThread* t2 = new QThread;
    QThread* t3 = new QThread;
    // 创建任务类的对象
    Generate* subThread = new Generate;
    BubbleSort* bubble = new BubbleSort;
    QuickSort* quick = new QuickSort;
    // 将任务对象移动到某个子线程中
    subThread -> moveToThread(t1);
    bubble -> moveToThread(t2);
    quick -> moveToThread(t3);

    connect(this, &MainWindow::starting, subThread, &Generate::working);
    /// @brief 按下 the_run 生成随机数的子线程启动
    connect(ui -> the_run, &QPushButton::clicked, this, [=]()
    {
        emit starting(1000); // 发出信号
        t1->start(); // 启动子线程
    });

    /// @brief 接受信号
    connect(subThread, &Generate::sendArray, bubble, &BubbleSort::working);
    connect(subThread, &Generate::sendArray, quick, &QuickSort::working);

    // 接收子线程的数据并在窗口显示
    connect(subThread, &Generate::sendArray, this, [=](QVector<int> list){
        t2 -> start();
        t3 -> start();
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
        t1 -> quit();
        t1 -> wait();
        t1 -> deleteLater();
        t2 -> quit();
        t2 -> wait();
        t2 -> deleteLater();
        t3 -> quit();
        t3 -> wait();
        t3 -> deleteLater();
        subThread -> deleteLater();
        bubble -> deleteLater();
        quick -> deleteLater();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
