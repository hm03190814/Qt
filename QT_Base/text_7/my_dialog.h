#ifndef MY_DIALOG_H
#define MY_DIALOG_H

#include <QDialog>

namespace Ui {
class my_Dialog;
}

class my_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit my_Dialog(QWidget *parent = nullptr);
    ~my_Dialog();

private slots:
    void on_reject_btn_clicked();

    void on_accept_btn_clicked();

    void on_down_btn_clicked();

private:
    Ui::my_Dialog *ui;
};

#endif // MY_DIALOG_H
