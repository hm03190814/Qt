#ifndef RECVFILE_H
#define RECVFILE_H

#include <QObject>
#include <QThread>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>

class RecvFile : public QThread
{
    Q_OBJECT
public:
    explicit RecvFile(QTcpSocket* tcp, QObject *parent = nullptr);

protected:
    void run();

private:
    QTcpSocket* m_tcp;

signals: // 信号
    void thread_over();
};

#endif // RECVFILE_H
