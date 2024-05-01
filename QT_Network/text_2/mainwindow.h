#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtNetwork/QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui {  class MainWindow;   }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_u_send_msg_clicked();
    void on_u_connect_clicked();
    void on_u_disconnect_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket* m_tcp; // 通信的套接字对象 QTcpSocket
    QLabel* m_status; // 状态栏
};
#endif // MAINWINDOW_H
