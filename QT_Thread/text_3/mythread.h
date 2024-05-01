#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QVector>
#include <QObject>
#include <QRunnable>

class Generate : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
public slots:
    void curNumber(int num); // 槽函数
public:
    void run() override;
signals:
    void sendArray(QVector<int> num); // 信号
private:
    int m_num;
};

class BubbleSort : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
public slots:
    void curArray(QVector<int> list); // 槽函数_接受容器
public:
    void run() override;
signals:
    void finish(QVector<int> num); // 信号
private:
    QVector<int> m_list;
};


class QuickSort : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
public slots:
    void curArray(QVector<int> list); // 槽函数_接受容器
public:
    void run() override;
private:
    void quick_sort(QVector<int> &list, int l, int r);
signals:
    void finish(QVector<int> num); // 信号
private:
    QVector<int> m_list;
};


#endif // MYTHREAD_H
