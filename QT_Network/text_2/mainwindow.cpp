#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    setWindowTitle("TCP - 客户端");
    ui -> u_port -> setText("8899");
    ui -> u_ip -> setText("127.0.0.1");
    ui -> u_disconnect -> setEnabled(false);

    /// @brief 创建 QTcpSocket 对象
    m_tcp = new QTcpSocket(this);

    // 调用 connectToHost() 函数并成功建立连接之后发出 connected() 信号
    connect(m_tcp, &QTcpSocket::connected, this, [=]()
    {
        ui->u_show->append("连接服务器成功!!!");
        m_status->setPixmap(QPixmap("").scaled(20, 20));
        ui -> u_connect->setEnabled(false);
        ui -> u_disconnect->setEnabled(true);
    });

    // 套接字断开连接时发出 disconnected() 信号
    connect(m_tcp, &QTcpSocket::disconnected, this, [=](){
        ui -> u_show->append("连接断开...");
        m_tcp -> close();
        m_tcp -> deleteLater(); // 释放
        m_status -> setPixmap(QPixmap("").scaled(20, 20));
        ui -> u_connect->setEnabled(true);
        ui -> u_disconnect->setEnabled(false);
    });

    // 对端发送的数据达到时 调用_readyRead
    connect(m_tcp, &QTcpSocket::readyRead, this, [=](){
        // 一次读取全部数据 并显示
        QByteArray data = m_tcp -> readAll();
        ui -> u_show -> append("服务器say : " + data);
    });

    /// @brief 状态栏
    m_status = new QLabel;
    m_status -> setPixmap(QPixmap("").scaled(20, 20));
    ui -> statusbar -> addWidget(new QLabel("链接状态 : "));
    ui -> statusbar -> addWidget(m_status);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// @brief 按下连接服务器按钮后的处理
void MainWindow::on_u_connect_clicked()
{
    QString the_ip = ui -> u_ip -> text();
    unsigned short the_port = ui -> u_port -> text().toUShort();
    // 连接服务器
    m_tcp -> connectToHost(QHostAddress(the_ip), the_port);
    ui -> u_connect->setEnabled(false);
    ui -> u_disconnect->setEnabled(true);
}

/// @brief 按下断开链接按钮后的处理
void MainWindow::on_u_disconnect_clicked()
{
    m_tcp -> close();
    ui -> u_connect->setEnabled(true);
    ui -> u_disconnect->setEnabled(false);
}

/// @brief 按下发送信息按钮后的处理
void MainWindow::on_u_send_msg_clicked()
{
    QString the_msg = ui -> u_msg -> toPlainText(); // 以纯文本方式取出
    m_tcp -> write(the_msg.toUtf8()); // 发送
    ui -> u_show -> append("客户端say : " + the_msg);
}