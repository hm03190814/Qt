#include "mythread.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QThread>

Generate::Generate(QObject *parent) : QObject(parent) {}
BubbleSort::BubbleSort(QObject *parent) : QObject(parent) {}
QuickSort::QuickSort(QObject *parent) : QObject(parent) {}

/// @brief 生成随机数_类
void Generate::working(int num)
{
    qDebug() << "生成随机数线程对象的地址: " << QThread::currentThread();
    QVector<int> list;
    QElapsedTimer timer;
    timer.start();
    for(int i = 0; i < num; ++i)
        list.push_back(qrand() % 1000);
    int the_time = timer.elapsed();
    qDebug() << "生成随机数用时:  " << the_time ;
    emit sendArray(list); // 发出信号
}

/// @brief 冒泡排序_类
void BubbleSort::working(QVector<int> list)
{
    qDebug() << "冒泡排序线程对象的地址: " << QThread::currentThread();
    QElapsedTimer timer;
    timer.start();
    int temp;
    for(int i = 0; i < list.size(); ++i){
        for(int j = 0; j < list.size()-i-1; ++j){
            if(list[j] > list[j+1]){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
    int the_time = timer.elapsed();
    qDebug() << "冒泡排序用时:  " << the_time ;
    emit finish(list); // 发出信号
}

/// @brief 快速排序_类
void QuickSort::working(QVector<int> list)
{
    qDebug() << "快速排序线程对象的地址: " << QThread::currentThread();
    QElapsedTimer timer;
    timer.start();
    quick_sort(list, 0, list.size()-1);
    int the_time = timer.elapsed();
    qDebug() << "快速排序用时:  " << the_time ;
    emit finish(list); // 发出信号
}

/// @brief 快速排序
void QuickSort::quick_sort(QVector<int> &s, int l, int r) {
    if(l < r)
    {
        int i = l, j = r;
        int x = s[l];
        while(i < j){
            while(i < j && s[j] >= x){
                j--;
            }
            if(i < j) {
                s[i++] = s[j];
            }
            while(i < j && s[i] < x){
                i++;
            }
            if(i < j){
                s[j--] = s[i];
            }
        }
        s[i] = x;
        quick_sort(s, l, i - 1);
        quick_sort(s, i + 1, r);
    }
}