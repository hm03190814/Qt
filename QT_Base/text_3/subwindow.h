#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QDialog>

namespace Ui {
class subwindow;
}

class subwindow : public QDialog
{
    Q_OBJECT

public:
    explicit subwindow(QWidget *parent = nullptr);
    ~subwindow();

private:
    Ui::subwindow *ui;
};

#endif // SUBWINDOW_H
