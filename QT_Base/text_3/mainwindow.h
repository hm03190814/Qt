#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct person
{
    int id;
    QString name;
};
Q_DECLARE_METATYPE(person)


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /// @brief 声明函数 the_sum
    QVariant the_sum(QVariant a, QVariant b);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
