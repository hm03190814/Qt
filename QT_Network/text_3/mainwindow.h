#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>

QT_BEGIN_NAMESPACE 
namespace Ui {   class MainWindow;   }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals: // 信号
    void start_connect(unsigned short, QString);
    void send_file(QString path);

private slots: // 槽
    void on_u_connect_clicked(); // 连接服务器
    void on_u_choose_file_clicked(); // 选择文件
    void on_u_send_file_clicked(); // 发送文件
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
