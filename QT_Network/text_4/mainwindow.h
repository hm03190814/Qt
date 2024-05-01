#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QTcpServer>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_u_set_listen_clicked();

private:
    Ui::MainWindow *ui;
    QTcpServer* m_server; // 创建套接字服务器对象 QTcpServer

};
#endif // MAINWINDOW_H
