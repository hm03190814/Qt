#include "mybutton.h"
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <QPaintEvent>
#include <QPixmap>

/// @brief 初始化
MyButton::MyButton(QWidget *parent) : QWidget{parent}
{
    m_pixmap.load(":/source/1"); // 设置开始时显示的图片
    setFixedSize(m_pixmap.size());
}

/// @brief 重写鼠标相关的事件
// 鼠标按下
void MyButton::mousePressEvent(QMouseEvent* ev)
{
    Q_UNUSED(ev);
    m_pixmap.load(":/source/2");    
    update();   
    emit the_clicked();
    // QWidget::mouseReleaseEvent(ev); // 在子类中执行父类的函数
}
// 鼠标释放
void MyButton::mouseReleaseEvent(QMouseEvent* ev){}
// 鼠标进入指定区域
void MyButton::enterEvent(QEvent* ev){}
// 鼠标离开
void MyButton::leaveEvent(QEvent* ev){}
// 窗口刷新函数
void MyButton::paintEvent(QPaintEvent* ev)
{
    // 设置绘图设备
    QPainter p(this);
    p.drawPixmap(rect(), m_pixmap);
}