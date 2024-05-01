#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
using namespace std;
#include <QDebug>
#include "my_dialog.h"
#include <QMessageBox>
#include <QString>
#include <QFileDialog>
#include <QDialog>
#include <QFontDialog>
#include <QColorDialog>
#include <QPainter>
#include <QInputDialog>
#include <QProgressDialog>
#include <QTimer>
#include <QTime>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /// @brief 设置窗口最大尺寸
    setMaximumSize(600, 600);
    /// @brief 设置窗口最小尺寸
    setMinimumSize(300, 300);
    // /// @brief 设置窗口固定尺寸
    // setFixedSize(500, 500);
    /// @brief 设置窗口标题
    setWindowTitle("hello_QT");
    /// @brief 给显示的窗口设置图标_使用磁盘文件
    // setWindowIcon(QIcon("../1.jpg"));
    /// @brief 给显示的窗口设置图标_使用资源文件
    setWindowIcon(QIcon(":/source/a.png"));

    /// @brief 菜单
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &MainWindow::customContextMenuRequested, this, [=](const QPoint &pos)
    {
        QMenu meun;
        meun.addAction("apple");
        meun.addAction("egg");
        meun.addAction("banana");
        meun.exec(QCursor::pos());
    });

    /// @brief 窗口中的菜单栏
    connect (ui -> save_action, &QAction::triggered, this, [=](){
        QMessageBox::information(this, "save", "正在保存");
    });

    /// @brief 给工具栏添加按钮和单行输入框
    ui -> toolBar -> addWidget(new QPushButton("搜索"));
    QLineEdit* edit = new QLineEdit;
    edit -> setMaximumWidth(200);    
    // edit -> setFixedWidth(200)
    ui -> toolBar -> addWidget(edit);

    /// @brief 添加第二个工具栏
    QToolBar* toolbar_left = new QToolBar("the_tool_bar");
    this -> addToolBar(Qt::LeftToolBarArea, toolbar_left);

    /// @brief 状态栏添加子控件
    ui -> statusbar -> showMessage("我是状态栏", 3000);
    // 按钮
    QPushButton* button_1 = new QPushButton("按钮");
    ui -> statusbar -> addWidget(button_1);
    // 标签
    QLabel* label_1 = new QLabel("hello_world");
    ui -> statusbar -> addWidget(label_1);
    // 通过定时器显示
    QTimer::singleShot(5000, this, [=](){
        button_1 -> show();
        label_1 -> show();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

/// @brief 移动窗口
void MainWindow::on_move_btn_clicked()
{
    QRect rect = this -> frameGeometry();
    move(rect.topLeft() + QPoint(10, 20));
}

/// @brief 获取位置
void MainWindow::on_get_pose_clicked()
{
    QRect rect = this -> frameGeometry();
    qDebug() << "左上角" << rect.topLeft()
            << "右上角" << rect.topRight()
            << "左下角" << rect.bottomLeft()
            << "右下角" << rect.bottomRight()
            << "宽度" << rect.width()
            << "高度" << rect.height();
}

/// @brief 改变位置大小
void MainWindow::on_change_clicked()
{
    int x = 100 + rand() % 50;
    int y = 100 + rand() % 50;
    int width = this -> width() + 10;
    int height = this -> height() + 10;
    setGeometry(x, y, width, height);
    
}

/// @brief 显示模态窗口
void MainWindow::on_modaldlg_clicked()
{   
    my_Dialog dlg;
    connect(&dlg, &my_Dialog::finished, this, [=](int res)
    {
        qDebug() << "result : " << res;
    });
    connect(&dlg, &my_Dialog::accepted, this, [=]()
    {
        qDebug() << "accepted 信号被发射了";
    });
    connect(&dlg, &my_Dialog::rejected, this, [=]()
    {
        qDebug() << "rejected 信号被发射了";
    });


    int ret = dlg.exec();
    if(ret == QDialog::Accepted){
        qDebug() << "Accepted";
    }else if(ret == QDialog::Rejected){
        qDebug() << "Rejected";
    }else{
        qDebug() << "down";
    }
}

/// @brief 消息对话框类 QMseeageBox 
void MainWindow::on_msgbox_clicked()
{
    QMessageBox::about(this, "about", "这是一个消息提示框");
    QMessageBox::critical(this, "crtitcal", "这是一个错误对话框");
    int ret = QMessageBox::question(this, "question", "是否要进行保存", QMessageBox::Save | QMessageBox::Cancel, QMessageBox::Save);
    if(ret == QMessageBox::Save){
        QMessageBox::information(this, "information", "保存成功");
    }else if(ret == QMessageBox::Cancel){
        QMessageBox::warning(this, "information", "保存失败");
    }
}

/// @brief 文件对话框类 QFileDialog
#define save_file
void MainWindow::on_file_dialog_clicked()
{

#ifdef open_dir
    QString dir_name = QFileDialog::getExistingDirectory(this, "打开目录", "/opt");
    QMessageBox::information(this, "打开目录", "您选择打开的目录是 : " + dir_name);
#endif

#ifdef open_file
    QString arg("Tect files (*.txt)");
    QString fileName = QFileDialog::getOpenFileName(this, tr("标题"), "../", 
            tr("Images (*.png *.jpg);; Text files (*.txt)"), // 过滤器
            &arg // 默认过滤器
        );
#endif

#ifdef open_file_s
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("标题"), "../", 
            tr("Images (*.png *.jpg);; Text files (*.txt)") // 过滤器
        ); // (不指定过滤器就默认使用第一个)
    QString names;
    for (int i = 0; i < fileNames.size(); ++i){
        names += fileNames.at(i) + " & ";
    }
    QMessageBox::information(this, "打开文件", "您选择的文件是 : " + names);
#endif

#ifdef save_file
    QString save_name = QFileDialog::getSaveFileName(this, "保存文件", "../");
    QMessageBox::information(this, "保存文件", "您指定的保存数据是 : " + save_name);
#endif

}

/// @brief QFontDialog 字体对话框类
void MainWindow::on_font_dlg_clicked()
{
#if 0
    bool ok;
    QFont ft = QFontDialog::getFont(&ok, QFont("宋体", 12, QFont::Bold), this, "选择字体");
    qDebug() << "ok = " << ok;
#else
    QFont ft = QFontDialog::getFont(NULL);
#endif
    ui -> fontlabel -> setFont(ft);
}

/// @brief 颜色对话框类 QColorDialog
void MainWindow::on_color_dlg_clicked()
{
    QColor color_label = QColorDialog::getColor();
    QBrush brush(color_label);  
    QRect rect(0, 0, ui->color_label->width(), ui->color_label->height());
    QPixmap pix(rect.width(), rect.height());
    QPainter p(&pix);
    p.fillRect(rect, brush);
    ui -> color_label -> setPixmap(pix);
}

/// @brief 输入对话框类 QInputDialog
#define get_multiLineText
void MainWindow::on_input_dialog_clicked()
{
#ifdef get_int
    int age = QInputDialog::getInt(this, tr("年龄"), tr("提示信息:您当前年龄 :"), 20, 1, 100, 2);
    // int age = QInputDialog::getInt(this, "年龄", "提示信息:您当前年龄 :", 10, 1, 100, 2);
    QMessageBox::information(this, "年龄", "您的年龄是:" + QString::number(age));
#endif

#ifdef get_double   
    double wages = QInputDialog::getDouble(this, "工资", "您的工资", 6000, 8000, 18000, 2);
    QMessageBox::information(this, "工资", "您的当前工资 : " + QString::number(wages));
#endif 

#ifdef get_item
    QStringList items;
    items << "苹果" << "橘子" << "香蕉" ;
    QString item = QInputDialog::getItem(this, "选择水果", "选择你想要的水果", items, 1, false);
    QMessageBox::information(this, "水果", "您选择的水果是 : " + item);
#endif 

#ifdef get_text
    QString text = QInputDialog::getText(this, "密码", "请输入密码", QLineEdit::Password, "aaa");
    QMessageBox::information(this, "密码", "您的密码是 : " + text);
#endif 

#ifdef get_multiLineText
    QString info = QInputDialog::getMultiLineText(this, "说话", "想说的话", "你好");
    QMessageBox::information(this, "对方", "你想说的话 : " + info);
#endif 

}

/// @brief 进度会话框类 QProgressDialog
void MainWindow::on_progress_dlg_clicked()
{
    // 创建进度条对话框对象
    QProgressDialog *progress  = new QProgressDialog("正在拷贝数据", "取消拷贝", 0, 100, this);
    // 初始化并显示进度条窗口
    progress -> setWindowTitle("请稍后");
    progress -> setWindowModality(Qt::WindowModal); // 模态显示
    progress -> show();
    // 更新进度条
    static int value = 0;
    QTimer *timer = new QTimer;
    connect(timer, &QTimer::timeout, this, [=](){
        progress -> setValue(value);
        value++;
        // 当 value>最大值 时
        if(value > progress->maximum()){
            timer -> stop();
            value =0 ;
            delete progress;
            delete timer;
        }
    });
    // 按下 "取消拷贝" 是关闭进度条窗口
    connect(progress, &QProgressDialog::canceled, this,  [=](){
        timer -> stop();
        value = 0;
        delete progress;
        delete timer;
    });
    // 启动定时器
    timer-> start(50);
}

