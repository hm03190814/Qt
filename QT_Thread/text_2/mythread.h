#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QVector>
#include <QObject>

class Generate : public QObject // 改父类
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
public:
    void working(int num); // 改为_public
signals:
    void sendArray(QVector<int> num); // 信号
};

class BubbleSort : public QObject
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);
public:
    void working(QVector<int> list);
signals:
    void finish(QVector<int> num); // 信号
};


class QuickSort : public QObject
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);
public:
    void working(QVector<int> list);
private:
    void quick_sort(QVector<int> &list, int l, int r);
signals:
    void finish(QVector<int> num); // 信号
};


#endif // MYTHREAD_H
