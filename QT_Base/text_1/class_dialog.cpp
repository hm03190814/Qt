#include "class_dialog.h"
#include "ui_class_dialog.h"

class_dialog::class_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::class_dialog)
{
    ui->setupUi(this);
}

class_dialog::~class_dialog()
{
    delete ui;
}
