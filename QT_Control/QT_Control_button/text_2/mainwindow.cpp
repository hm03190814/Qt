#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置根节点的三态属性
    ui -> class_num -> setTristate(true);
    // 根节点状态改变时 子节点随之改变
    connect(ui -> class_num, &QCheckBox::clicked, this, [=](bool bl){
        if(bl){
            ui -> the_1 -> setChecked(true); // 设置按钮状态为_被选中
            ui -> the_2 -> setChecked(true);
        }else{
            ui -> the_1 -> setChecked(false);
            ui -> the_2 -> setChecked(false);
        }
    });
    // 子节点槽函数
    connect(ui -> the_1, &QCheckBox::stateChanged, this, &MainWindow::statusChanged);
    connect(ui -> the_2, &QCheckBox::stateChanged, this, &MainWindow::statusChanged);

}

MainWindow::~MainWindow()
{
    delete ui;
}

/// @brief QCheckBox_类的使用
void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 = Qt::Checked)
        qDebug() << "最喜欢的数字是_1";
    // 怎么保存选中的数据, 具体去看视频提供了三种方法
}


/// @brief 子节点状态改变时 根节点随之改变
void MainWindow::statusChanged(int state){
    // 实时更新状态
    if(state == Qt::Checked){
        m_number ++;
    }else{
        m_number --;
    }
    // 判断根节点是否需要做状态的更新
    if(m_number == 2){
        ui -> class_num -> setCheckState(Qt::Checked); // 全选中
    }else if(m_number == 0){
        ui -> class_num -> setCheckState(Qt::Unchecked); // 未选中

    }else{
        ui -> class_num -> setCheckState(Qt::PartiallyChecked); // 半选中
    }
}
