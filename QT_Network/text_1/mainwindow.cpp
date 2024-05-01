#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtNetwork/QAbstractSocket>
#include <QMainWindow>
#include <QLabel>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TCP - 服务端");
    ui -> u_port -> setText("8899");
    
    /// @brief 创建 监听服务器_QTcpServer 对象
    m_server = new QTcpServer(this);

    /// @brief 每次有新连接可用时 触发 newConnection() 信号
    connect(m_server, &QTcpServer::newConnection, this, [=]()
    {
        // 得到用于通信的QTcpSocket套接字对象
        QTcpSocket* m_tcp = m_server -> nextPendingConnection();
        ui -> u_show -> append("成功和客户端建立了新的连接...");
        m_status -> setPixmap(QPixmap("").scaled(20, 20));
        // 对端发送的数据达到时 调用_readyRead
        connect(m_tcp, &QTcpSocket::readyRead, this, [=](){
            // 一次读取全部数据 并显示
            QByteArray data = m_tcp -> readAll(); 
            ui -> u_show -> append("客户端say : " + data);
        });
        // 套接字断开连接时发出 disconnected() 信号
        connect(m_tcp, &QTcpSocket::disconnected, this, [=](){
            ui->u_show->append("客户端已经断开了连接...");
            m_tcp -> close();
            m_tcp -> deleteLater(); // 释放
            m_status -> setPixmap(QPixmap("").scaled(20, 20));
        });
    });

    /// @brief 状态栏
    m_status = new QLabel;
    m_status -> setPixmap(QPixmap("").scaled(20, 20)); // 资源图片_懒得弄了
    ui -> statusbar -> addWidget(new QLabel("链接状态"));
    ui -> statusbar -> addWidget(m_status);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/// @brief 按下启动监听服务按钮后的处理
void MainWindow::on_u_run_listen_clicked()
{
    // 读取_端口号
   unsigned short port_num = ui -> u_port -> text().toUShort();
   // 给监听的套接字设置监听
   m_server -> listen(QHostAddress::Any, port_num);
   ui -> u_run_listen -> setDisabled(true);
}

/// @brief 按下发送信息按钮后的处理
void MainWindow::on_u_send_msg_clicked()
{
    QString the_msg = ui -> u_msg -> toPlainText(); // 以纯文本方式取出
    m_tcp -> write(the_msg.toUtf8()); // 发送
    ui -> u_show -> append("客户端say : " + the_msg);
}

