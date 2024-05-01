#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;


protected:
/// @brief 重写事件处理函数
    void closeEvent(QCloseEvent* ev);
    void resizeEvent(QResizeEvent* ev);
};
#endif // MAINWINDOW_H
