#ifndef CLASS_DIALOG_H
#define CLASS_DIALOG_H

#include <QDialog>

namespace Ui {
class class_dialog;
}

class class_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit class_dialog(QWidget *parent = nullptr);
    ~class_dialog();

private:
    Ui::class_dialog *ui;
};

#endif // CLASS_DIALOG_H
