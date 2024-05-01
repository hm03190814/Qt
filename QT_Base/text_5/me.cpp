#include "me.h"
#include <QDebug>

me::me(QObject *parent)
    : QObject{parent}
{  
}

void me::eat()
{
    qDebug() << "带女生去吃饭_无参";
}

void me::eat(QString msg)
{
    qDebug() << "带女生去吃她想吃的_" << msg;

}