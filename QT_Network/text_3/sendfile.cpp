#include "sendfile.h"
#include <QtNetwork/QHostAddress>
#include <QFile>
#include <QFileInfo>

SendFile::SendFile(QObject *parent) : QObject{parent} {}

/// @brief 连接服务器
void SendFile::connect_server(unsigned short port, QString ip)
{
    /// @brief 创建 QTcpSocket 对象
    m_tcp = new QTcpSocket;
    m_tcp -> connectToHost(QHostAddress(ip), port);

    // 调用 connectToHost() 函数并成功建立连接之后发出 connected() 信号
    connect(m_tcp, &QTcpSocket::connected, this, &SendFile::connect_ok);
    connect(m_tcp, &QTcpSocket::disconnected, this, [=](){
        m_tcp -> close(); 
        m_tcp -> deleteLater();
        emit connect_not();
    });    
}

/// @brief 发送文件
void SendFile::send_file(QString path)
{
    QFile file(path);
    QFileInfo info(path);
    int file_size = info.size();
    file.open(QFile::ReadOnly);
    while(!file.atEnd())
    {
        static int num = 0;
        if(num == 0)
            m_tcp -> write((char*)&file_size, 4);
        QByteArray line = file.readLine();
        num += line.size();
        int schedule = (num * 100 / file_size);
        emit send_schedule(schedule);
        m_tcp -> write(line);
    }
}