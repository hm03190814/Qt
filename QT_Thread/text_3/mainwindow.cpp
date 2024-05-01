#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"
#include <QDebug>
#include <QThreadPool>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "主线程对象地址: " << QThread::currentThread();

    // 创建任务类对象
    Generate* subThread = new Generate;
    BubbleSort* bubble = new BubbleSort;
    QuickSort* quick = new QuickSort;

    connect(this, &MainWindow::starting, subThread, &Generate::curNumber);
    /// @brief 按下 the_run 把任务扔到线程池中去
    connect(ui -> the_run, &QPushButton::clicked, this, [=]()
    {
        emit starting(1000); // 发出信号
        QThreadPool::globalInstance() -> start(subThread); // 把任务扔到线程池中去
    });

    /// @brief 接受信号
    connect(subThread, &Generate::sendArray, bubble, &BubbleSort::curArray);
    connect(subThread, &Generate::sendArray, quick, &QuickSort::curArray);

    // 接收线程数据并在窗口显示
    connect(subThread, &Generate::sendArray, this, [=](QVector<int> list){
        QThreadPool::globalInstance() -> start(bubble); // 把任务扔到线程池中去
        QThreadPool::globalInstance() -> start(quick); // 把任务扔到线程池中去
        for(int i = 0; i < list.size(); ++i)
            ui -> the_new -> addItem(QString::number(list.at(i)));
    });
    // 接收线程数据并在窗口显示
    connect(bubble, &BubbleSort::finish, this, [=](QVector<int> list){
        for(int i = 0; i < list.size(); ++i)
            ui -> the_1 -> addItem(QString::number(list.at(i)));
    });
    // 接收线程数据并在窗口显示
    connect(quick, &QuickSort::finish, this, [=](QVector<int> list){
        for(int i = 0; i < list.size(); ++i)
            ui -> the_2 -> addItem(QString::number(list.at(i)));
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
