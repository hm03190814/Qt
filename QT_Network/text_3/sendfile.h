#ifndef SENDFILE_H
#define SENDFILE_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

class SendFile : public QObject
{
    Q_OBJECT
public:
    explicit SendFile(QObject *parent = nullptr);
public:
    /// @brief 连接服务器
    void connect_server(unsigned short port, QString ip);
    /// @brief 发送文件
    void send_file(QString path);
signals: // 信号
    void connect_ok();
    void connect_not();
    void send_schedule(int num);
private:
    QTcpSocket* m_tcp; // 通信的套接字对象 QTcpSocket
};

#endif // SENDFILE_H
