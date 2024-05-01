#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::login)
{
    ui->setupUi(this);
    setFixedSize(260,330);
}

login::~login()
{
    delete ui;
}
