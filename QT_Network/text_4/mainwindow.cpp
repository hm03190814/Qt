#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "recvfile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TCP - 服务端");
    // ui -> u_port -> setText("8899");
    
    /// @brief 创建 监听服务器_QTcpServer 对象
    m_server = new QTcpServer(this);

    /// @brief 每次有新连接可用时 触发 newConnection() 信号
    connect(m_server, &QTcpServer::newConnection, this, [=]()
    {
        // 得到用于通信的QTcpSocket套接字对象
        QTcpSocket* tcp = m_server -> nextPendingConnection();
        // 创建子线程
        RecvFile* subthread = new RecvFile(tcp);
        subthread -> start();

        connect(subthread, &RecvFile::thread_over, this, [=](){
            subthread -> exit();
            subthread -> wait();
            subthread -> deleteLater();
        });
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_u_set_listen_clicked()
{
    // 读取_端口号
   unsigned short port_num = ui -> u_port -> text().toUShort();
   // 给监听的套接字设置监听
   m_server -> listen(QHostAddress::Any, port_num);
}

