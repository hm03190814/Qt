#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// @brief 创建定时器对象
    QTimer* timer = new QTimer(this);
    /// @brief 按钮点击事件
    connect(ui->run, &QPushButton::clicked, this, [=]()
    {
        if(timer -> isActive())
        {
            timer -> stop();
            ui -> run -> setText("开始");
        }else{
            ui -> run -> setText("关闭");
            timer -> start(1000); // 启动定时器
        }
    });
    /// @brief 显示时间
    connect(timer, &QTimer::timeout, this, [=]()
    {
        QTime tm = QTime::currentTime();
        // 格式化当前得到的系统时间
        QString str_tm = tm.toString("hh:mm:ss.zzz");
        // 设置要显示的时间
        ui -> now_time -> setText(str_tm);
    });

    /// @brief 发射一次信号
    connect(ui -> once_run, &QPushButton::clicked, this, [=]()
    {
        // 获取两秒以后的时间
        QTimer::singleShot(2000, this, [=]()
        {
            QTime tm = QTime::currentTime();
            // 格式化当前得到的系统时间
            QString str_tm = tm.toString("hh:mm:ss.zzz");
            // 设置要显示的时间
            ui -> once_time -> setText(str_tm);
        });
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
