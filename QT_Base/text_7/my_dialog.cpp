#include "my_dialog.h"
#include "ui_my_dialog.h"

my_Dialog::my_Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::my_Dialog)
{
    ui->setupUi(this);
}

my_Dialog::~my_Dialog()
{
    delete ui;
}

/// @brief 隐藏窗口, 解除堵塞, 返回值值为1 
void my_Dialog::on_accept_btn_clicked()
{
    this -> accept();
}

/// @brief 隐藏窗口, 解除堵塞, 返回值值为0
void my_Dialog::on_reject_btn_clicked()
{   
    this -> reject();
}

/// @brief 删除窗口, 解除堵塞, 返回值值可以指定
void my_Dialog::on_down_btn_clicked()
{
    this -> done(10);
}
