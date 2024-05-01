

## [QT_实践 -> Video](https://edu.subingwen.cn/p/t_pc/course_pc_detail/column/p_61a83984e4b00db3cebe74e5)		

- https://subingwen.cn/qt/socket-tcp/
- https://space.bilibili.com/147020887

```c++
01-Qt 套接字通信概述
02-QTcpServer类的常用API
03-QTcpSocket类的常用API
04-Qt中基于tcp进行套接字通信的流程

05-07 服务端 text_1
08-客户端 text_2
09-程序测试

10-13 客户端 text_3
14-接收文件的服务器端和客户端建立连接 text_4
15-程序测试

16-解决通信的套接字对象无法在子线程中工作的问题 // 未记笔记
```

```c
// 使用Qt提供的类进行基于TCP的套接字通信需要用到两个类：
QTcpServer：服务器类，用于监听客户端连接以及和客户端建立连接。
QTcpSocket：通信的套接字类，客户端、服务器端都需要使用。
// 这两个套接字通信类都属于网络模块network。
```

```shell
# 通信流程
创建套接字服务器QTcpServer对象
通过QTcpServer对象设置监听，即：QTcpServer::listen()
基于QTcpServer::newConnection()信号检测是否有新的客户端连接
如果有新的客户端连接调用QTcpSocket *QTcpServer::nextPendingConnection()得到通信的套接字对象
使用通信的套接字对象QTcpSocket和客户端进行通信
```

