#include "class_widget.h"
#include "ui_class_widget.h"

class_widget::class_widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::class_widget)
{
    ui->setupUi(this);
}

class_widget::~class_widget()
{
    delete ui;
}
