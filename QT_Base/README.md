## [QT_基础 -> Video](https://edu.subingwen.cn/p/t_pc/course_pc_detail/column/p_61a78269e4b0c1a11a7c3b28?product_id=p_61a78269e4b0c1a11a7c3b28)   

------

### QT_模块

- [Qt系列文章011-Qt模块介绍](https://blog.csdn.net/feiyangqingyun/article/details/121178277)   

### QT_类

- [Qt的常用类及作用](https://blog.csdn.net/exlink2012/article/details/133972627)   

### 数据类型

- [QT基本数据类型](https://blog.csdn.net/x356982611/article/details/50762931) 

### 日志输出 QDebug

- [搜索 : qt qdebug](https://so.csdn.net/so/search?q=qt%20qdebug&t=blog&u=&urw=)  

### 字符串类 QByteArray

- [搜索 : qt 字符串类 QByteArray](https://so.csdn.net/so/search?q=qt%20QByteArray&t=blog&u=&urw=)  

### 字符串类 QString

- [搜索 : 字符串类 QString](https://so.csdn.net/so/search?spm=1000.2115.3001.4498&q=%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%B1%BBQString&t=blog&u=)   

###  QVariant (对QT中的多种类型进行包装)

- [搜索 : QVariant](https://so.csdn.net/so/search?spm=1000.2115.3001.4498&q=QVariant&t=&u=)  
- [搜索 : 使用QVariant对自定义类型进行处理](https://so.csdn.net/so/search?spm=1000.2115.3001.4498&q=%E4%BD%BF%E7%94%A8QVariant%E5%AF%B9%E8%87%AA%E5%AE%9A%E4%B9%89%E7%B1%BB%E8%BF%9B%E8%A1%8C%E5%A4%84%E7%90%86&t=&u=) 

### 坐标类 QPoint

- [搜索 : QPoint](https://so.csdn.net/so/search?q=QPoint&t=&u=&urw=) 

### 直线类 QLine

- [搜索 : QLine](https://so.csdn.net/so/search?q=QLine&t=&u=&urw=)   

### 尺寸类 QSize

- [搜索 : QSize](https://so.csdn.net/so/search?q=QSize&t=&u=&urw=) 

### 矩形类 QRect

- [搜索 : QRect](https://so.csdn.net/so/search?q=QRect&t=&u=&urw=)   

### 日期类 QDate

- [搜索 : QDate](https://so.csdn.net/so/search?q=QDate&t=&u=&urw=)   

### 时间类 QTime

- [搜索 : QTime](https://so.csdn.net/so/search?q=QTime&t=&u=&urw=)   

### 日期时间类 QDateTime

- [搜索 : QDateTime](https://so.csdn.net/so/search?q=QDateTime&t=&u=&urw=)  

### 信号与槽 text_4 text_5

- [搜索 : 信号与槽](https://so.csdn.net/so/search?q=%E4%BF%A1%E5%8F%B7%E4%B8%8E%E6%A7%BD&t=&u=&urw=)      

```c++
// 信号与槽联系需要 QOjbect类的connect
[static] QMetaObject::Connection  QObject::connect(
                const QObject *sender, // 静态成员
                const char *signal, // 信号 (用signals声明)(用emit使用)(只声明)
                const QObject *receiver, // 槽 (用slots声明)
                const char *method, // 接受者
                Qt::ConnectionType type = Qt::AutoConnection // 方法
		);	
connect的前四个参数都是指针，信号和槽是函数指针               
```

```c++
// 自定义信号 要求 
1 信号是类的成员函数
2 返回值是 void 类型
3 参数可以随意指定_信号也支持重载
4 信号_需要 signals 关键字声明
5 信号函数 只需要声明 不需要进行定义
6 信号函数前用关键字 emit 加不加都行
class test : public QObject
{
    Q_OBJECT
signals:
    void test_signal();
    void test_signal(int a);
}
```

```c++
// 自定义槽 要求
1 返回值是 void 类型
2 也可重载
3 信号的参数大于等于槽函数的参数个数
4 槽函数的类型
    类的成员函数
    全局函数
    静态函数
    lambda表达式(匿名函数)
5 槽函数可以使用 slots 关键字进行声明
    public slots:
    private slots:
    protected slots:
class test : public QObject
{
public slots:
    void test_slot();
    static void test_func();
    void test_slot(int a);
}
```

```c++
// @brief 信号与槽的拓展
// 一个信号可以连接多个槽 (即一个信号有多种处理动作)
// 一个槽可以连接多个信号 (即多个信号对应同一种处理动作)
// 信号可以连接信号
// 信号槽可以断开 disconnect
```

### 定时器类 QTimer text_6

- [搜索 : QTimer](https://so.csdn.net/so/search?spm=1000.2115.3001.4498&q=QTime&t=blog&u=)     

### QWidget 窗口类

- [搜索 : QWidget 窗口类](https://so.csdn.net/so/search?spm=1001.2101.3001.4498&q=QWidget%E7%AA%97%E5%8F%A3%E7%B1%BB&t=blog&u=)     

### QDialog 窗口类

- [搜索 : QDialog 窗口类](https://so.csdn.net/so/search?q=QDialog%20%E7%AA%97%E5%8F%A3%E7%B1%BB&t=blog&u=&urw=)     

### 消息对话框类 QMseeageBox 

- [搜索 : QMseeageBox](https://so.csdn.net/so/search?q=QMseeageBox&t=blog&u=&urw=)   

### 文件对话框类 QFileDialog

- [搜索 : QFileDialog](https://so.csdn.net/so/search?q=QFileDialog&t=blog&u=&urw=)   

### 字体对话框类 QFontDialog 

### 颜色对话框类 QColorDialog

### 输入对话框类 QInputDialog

### 进度会话框类 QProgressDialog

### QMainWindow 中菜单栏 工具栏 状态栏 停靠窗口 

### 资源文件 resource file 的使用

### 窗口布局 Layout



