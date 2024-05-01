#include "mainwindow.h"

#include <QApplication>

/// @brief QWidget类的使用
/// @brief 使用ui界面转到槽 (如果要使用的话头文件要加东西)
/// @brief 菜单
/// @brief QDialog类中信号槽的使用
/// @brief 消息对话框类 QMseeageBox 
/// @brief 文件对话框类 QFileDialog
/// @brief 字体对话框类 QFontDialog 
/// @brief 颜色对话框类 QColorDialog
/// @brief 输入对话框类 QInputDialog
/// @brief 进度会话框类 QProgressDialog
/// @brief 窗口中的菜单栏
/// @brief 给工具栏添加按钮和单行输入框
/// @brief 状态栏添加子控件
/// @brief 使用资源文件

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


