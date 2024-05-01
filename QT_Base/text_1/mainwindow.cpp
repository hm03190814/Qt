#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "class_widget.h"
#include "class_dialog.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 显示当前窗口时 顺便显示另一个窗口
    #if 1
            // 创建窗口对象 制定父对象 是独立窗口 要显示的话必须单独show
        class_widget* w = new class_widget;
        w->show();
    #else
            // 创建窗口对象 指定父对象 不是独立窗口 无需专门show
        class_widget* w = new class_widget(this);
    #endif


    // 创建对话框窗口
    class_dialog* dia = new class_dialog(this);
    dia->show(); // 显示窗口
    // dia->exec(); // 阻塞显示窗口



}

MainWindow::~MainWindow()
{
    delete ui;
}
