#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "subwindow.h"
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QElapsedTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    subwindow* sub = new subwindow(this);
    sub -> show(); // 非模态显示

    /// @brief 调用函数 the_sum
    int value = the_sum(10, 20).toInt();
    QString str_sum = the_sum("hello","world").toString();
    qDebug() << "value" << value;
    qDebug() << "str_sum" << str_sum;


    /// @brief 调用自定义结构体
    person p1;
    p1.id = 23;
    p1.name = "张三";
#if 0
    QVariant v;
    v.setValue(p1);
#else
    QVariant v = QVariant::fromValue(p1);
#endif
    if(v.canConvert<person>()){
        person tmp = v.value<person>();
        qDebug () << "id " << tmp.id << " name " << tmp.name;
    }

    /// @brief QLine()
    QLine line(QPoint(100, 200), QPoint(150, 210));
    QLine new_line = line.translated(10, 20);
    qDebug() << "平移之前" << line;
    qDebug() << "平移之后" << new_line;

    /// @brief QDate()
    // 获取当前日期
    QDate d = QDate::currentDate();
    qDebug() << "year: " << d.year() << " month: " << d.month() << " day: " << d.day();
    QString str_date = d.toString("yyyy-MM-dd");
    qDebug() << "date_now : " << str_date;

    /// @brief QTime()
    // 获取当前时间
    QTime time_1 = QTime::currentTime();
    qDebug() << "hour : " << time_1.hour() << " mintue : " << time_1.minute() << " second : " << time_1.second() << " millsecond : " << time_1.msec();
    QString str_time_1 = time_1.toString("hh:mm:ss.zzz");
    qDebug() << "格式化的日期 : " << str_time_1;
    
    /// @brief QElapsedTimer()
    QElapsedTimer time_use;
    time_use.start();
    qDebug() << "调用函数 ...";
    int ms = time_use.elapsed();
    qDebug() << "耗时 : " << ms << "毫秒";

    /// @brief QDateTime()
    // 获取时间和日期
    QDateTime dt = QDateTime::currentDateTime();
    QString str_dt = dt.toString("yyy/MM/dd hh:mm:ss ap");
    qDebug() << "str_dt : " << str_dt;
    // 获取日期
    QDate d_1 = dt.date();
    qDebug() << "year: " << d_1.year() << " month: " << d_1.month() << " day: " << d_1.day();
    // 获取时间
    QTime t_1 = dt.time();
    qDebug() << "hour : " << t_1.hour() << " mintue : " << t_1.minute() << " second : " << t_1.second() << " millsecond : " << t_1.msec();





}

MainWindow::~MainWindow()
{
    delete ui;
}


/// @brief 定义函数 the_sum
QVariant MainWindow::the_sum(QVariant a, QVariant b)
{
    QVariant ret;
    // 判断参数类型
    if(a.type()==QVariant::Int && b.type()==QVariant::Int)
        ret = a.toInt() + b.toInt();
    else if (a.type()==QVariant::String && b.type()==QVariant::String)
        ret.setValue(a.toString() + b.toString());
    return ret;
}
