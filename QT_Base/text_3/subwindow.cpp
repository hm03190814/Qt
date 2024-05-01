#include "subwindow.h"
#include "ui_subwindow.h"
#include <QDebug>

subwindow::subwindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::subwindow)
{
    ui->setupUi(this);
}

subwindow::~subwindow()
{
    qDebug() << "subwindow 析构 ... ";
    delete ui;

}
