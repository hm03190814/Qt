#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QMenu>
#include <QPushButton>
#include <QToolButton>
#include <QAction>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// @brief 一、 普通按钮 没有checked 属性
    /// @brief 按钮上按钮上设置图标的三种方式之 setIcon
    ui -> normalbtn -> setText("我是普通按键"); 
    ui -> normalbtn -> setIconSize(QSize(50, 50)); 
    ui -> normalbtn -> setIcon(QIcon(""));  // 使用资源文件设置图标 // 此处懒得设置资源文件了
    connect(ui -> normalbtn, &QPushButton::clicked, this, [=](){
        qDebug() << "刚刚按下了一个普通按钮";
    });

    /// @brief 按钮上设置图标的三种方式之 setDefaultAction
    QAction* actbtn = new QAction(QIcon(), "奥利给");
    ui -> actionbtn_1 -> setDefaultAction(actbtn);
    connect(ui -> actionbtn_1, &QToolButton::triggered, this, [=](QAction* act){
        act -> setText("修改。。。");
        act -> setIcon(QIcon());
    });    
    ui -> actionbtn_1 -> setToolButtonStyle(Qt::ToolButtonTextUnderIcon); // 设置图标显示格式

    // / @brief 按钮上设置图标的三种方式之 setArrowType
    ui -> actionbtn_2 -> setArrowType(Qt::UpArrow);
    ui -> actionbtn_2 -> setText("向上");
    ui -> actionbtn_2 -> setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


    /// @brief 二、check属性按钮
    ui -> checkbtn -> setCheckable(true); 
    connect(ui->checkbtn, &QPushButton::toggled, this, [=](bool bl){
        qDebug() << "我是一个check属性按钮,当前状态为 : " << bl;
    });


    /// @brief 三、关联菜单
    ui -> menubtn -> setText("选择一个你喜欢的水果");
    QMenu* menu = new QMenu;
    QAction* act_1 = menu -> addAction("苹果");
    QAction* act_2 = menu -> addAction("橘子");
    QAction* act_3 = menu -> addAction("橙子");
    QAction* act_4 = menu -> addAction("菠萝");
    ui -> menubtn -> setMenu(menu);
    connect(act_1, &QAction::triggered, this, [=](){    qDebug() << "我喜欢苹果";   });
    connect(act_2, &QAction::triggered, this, [=](){    qDebug() << "我喜欢橘子";   });
    connect(act_3, &QAction::triggered, this, [=](){    qDebug() << "我喜欢橙子";   });
    connect(act_4, &QAction::triggered, this, [=](){    qDebug() << "我喜欢菠萝";   });

    /// @brief 在QToolButton中菜单的三种弹出方式
    ui -> popmenu -> setMenu(menu);
    // ui -> popmenu -> setPopupMode(QToolButton::InstantPopup); // 方式一
    // ui -> popmenu -> setPopupMode(QToolButton::DelayedPopup); // 方式二
    ui -> popmenu -> setPopupMode(QToolButton::MenuButtonPopup); // 方式三
    connect(ui -> popmenu, &QToolButton::clicked, this, [=](){
        qDebug() << "我是popmenu按钮";
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}
