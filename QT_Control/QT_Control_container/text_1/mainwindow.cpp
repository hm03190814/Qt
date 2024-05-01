#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QLabel>
#include <QVBoxLayout> // 垂直布局

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /// @brief QScrollArea中显示多个
    // 创建垂直布局
    QVBoxLayout* vlayout = new QVBoxLayout;
    for(int i = 0; i < 6; ++i)
    {
        QLabel* pic = new QLabel;
        QString name = QString(":/source/%1").arg(i+1);
        pic -> setPixmap(QPixmap(name));
        vlayout -> addWidget(pic);
    }
    // 设置布局
    QWidget*  wg = new QWidget;
    wg -> setLayout(vlayout);
    ui -> scrollArea -> setWidget(wg);
    ui -> scrollArea -> setMinimumSize(250,250);
    ui -> scrollArea -> setAlignment(Qt::AlignHCenter); // 居中

    /// @brief QScrollArea中显示一个
    // QLabel* pic = new QLabel;
    // pic -> setPixmap(QPixmap(":/source/o.png"));
    // ui -> scrollArea -> setWidget(pic);
    // pic -> setFixedSize(300, 300);
    // ui -> scrollArea -> setAlignment(Qt::AlignHCenter);
    // ui -> scrollArea -> setMinimumSize(500,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}
