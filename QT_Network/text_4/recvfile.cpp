#include "recvfile.h"
#include <QFile>

RecvFile::RecvFile(QTcpSocket* tcp, QObject *parent) : QThread{parent} {
    m_tcp = tcp;
}

void RecvFile::run()
{
    QFile* file = new QFile("./a.txt");
    file -> open(QFile::WriteOnly);
    // 接收数据
    connect(m_tcp, &QTcpSocket::readyRead, this, [=](){
        static int count = 0;
        static int the_size = 0;

        if(count == 0)
            m_tcp -> read((char*)&the_size, 4);
        // 读取数据内容
        QByteArray all = m_tcp -> readAll();
        count += all.size();
        file -> write(all);

        // 判断数据是否接受完毕
        if(count == the_size){
            m_tcp -> close();
            m_tcp -> deleteLater();
            file -> close();
            file -> deleteLater();
            emit thread_over();
        }
    });

    // 线程不退出 进入事件循环
    exec();
}

