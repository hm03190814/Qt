#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "me.h"
#include "girl.h"

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

    /// @brief 按钮的槽函数
    void hungryslot();

    /// @brief 按下当前窗口的hungry按钮 直接处理
    void just_run();

private:
    Ui::MainWindow *ui;

    me* m_me;
    girl* m_girl;

};
#endif // MAINWINDOW_H
