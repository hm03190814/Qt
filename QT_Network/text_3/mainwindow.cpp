#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QThread>
#include "sendfile.h"
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /// @brief 初始化
    setWindowTitle("TCP - 客户端");
    ui -> u_port -> setText("8899");
    ui -> u_ip -> setText("127.0.0.1");
    ui -> u_progressBar -> setRange(0, 100); // 进度条
    ui -> u_progressBar -> setValue(0);
    
    /// @brief 创建线程对象
    QThread* t = new QThread;
    /// @brief 创建任务对象
    SendFile* worker = new SendFile;
    /// @brief 将任务放到线程中
    worker -> moveToThread(t);

    /// @brief 主线程发出信号 子线程执行对应槽函数
    connect(this, &MainWindow::start_connect, worker, &SendFile::connect_server);
    connect(this, &MainWindow::send_file, worker, &SendFile::send_file);

    /// @brief 主线程发出信号 主线程执行对应槽函数
    // 链接
    connect(worker, &SendFile::connect_ok, this, [=](){
        QMessageBox::information(this, "连接服务器", "连接成功");
    });
    // 断开
    connect(worker, &SendFile::connect_not, this, [=](){
        // 释放资源 
        t -> quit();
        t -> wait();
        worker -> deleteLater();
        t -> deleteLater();
    });
    // 进度条
    connect(worker, &SendFile::send_schedule, ui -> u_progressBar, &QProgressBar::setValue);
    
    // 子线程运行
    t -> start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// @brief 按下_链接服务器_按钮
void MainWindow::on_u_connect_clicked()
{
    QString the_ip = ui -> u_ip -> text();
    unsigned short the_port = ui -> u_port -> text().toUShort();
    emit start_connect(the_port, the_ip);
}

/// @brief 按下_选择文件_按钮
void MainWindow::on_u_choose_file_clicked()
{
    QString the_path = QFileDialog::getOpenFileName();
    if(the_path.isEmpty()){
        QMessageBox::warning(this, "打开文件", "选择的文件路径不能为空");
        return;
    }    
    ui -> u_file_path -> setText(the_path);
}

/// @brief 按下_发送文件_按钮
void MainWindow::on_u_send_file_clicked()
{
    emit send_file(ui -> u_file_path -> text());
}

