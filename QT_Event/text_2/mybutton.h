#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QEvent>
#include <QPaintEvent>
#include <QPixmap>

class MyButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);

protected:
    /// @brief 重写鼠标相关的事件
    void mousePressEvent(QMouseEvent* ev); // 鼠标按下
    void mouseReleaseEvent(QMouseEvent* ev); // 鼠标释放
    void enterEvent(QEvent* ev); // 鼠标进入指定区域
    void leaveEvent(QEvent* ev); // 鼠标离开
    void paintEvent(QPaintEvent* ev); // 窗口刷新函数

signals:
    void the_clicked();

private:
    QPixmap m_pixmap; // 只对图像进行显示_不能修改
    // QImage m_image; // 可对图像进行显示修改

};

#endif // MYBUTTON_H
