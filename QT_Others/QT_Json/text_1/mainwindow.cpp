#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QJsonDocument doc;
    if(doc.isEmpty())
        qDebug() << "Empty ..." ;
    if(doc.isNull())
        qDebug() << "Null ..." ;
    writeJson();
    readJson();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeJson(){
    QJsonObject obj;
    obj.insert("name", "Ace");
    obj.insert("Sex", "man");
    obj.insert("Age", "20");

    QJsonObject sub_obj;
    sub_obj.insert("Father", "Gol·D·Roger");
    sub_obj.insert("Mother", "Portgas·D·Rouge");
    QJsonArray array;
    array.append("Sabo");
    array.append("Monkey D. Luffy");
    sub_obj.insert("Brother", "array");

    obj.insert("Family", "sub_obj");
    obj.insert("IsAlive", "false");
    obj.insert("Comment", "yyds");

    QJsonDocument doc(obj);
    QJsonArray json = doc.toJson();

    QFile file ("a.json");
    file.open(QFile::WriteOnly);
    file.write(json);
    file.close();
}
void MainWindow::readJson(){

    QFile file ("a.json");
    file.open(QFile::ReadOnly);
    QJsonArray json_all = file.readAll();
    file.close();
    QJsonDocument doc = QJsonDocument::fromJson(json_all);

    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QStringList keys = obj.keys();
        for(int i = 0; i < keys.size(); ++i)
        {
            QString key = keys.at(i);
            QJsonValue value = obj.value(key);
            if(value.isBool()){
                qDebug() << key << ":" << value.toBool();
            }else if(value.isString){
                qDebug() << key << ":" << value.toString();
            }else if(value.isDouble){
                qDebug() << key << ":" << value.toInt();
            }else if(value.isObject){
                qDebug() << key << ":" ;
                QJsonObject sub_obj = value.toObject();
                QStringList sub_keys = sub_obj.keys();
                for(int k = 0; k < sub_keys.size(); ++k)
                {
                    QJsonValue sub_value = sub_keys.at(k);
                    if(sub_value.isString()){
                        qDebug() << "   " << sub_keys.at(k) << ":" << sub_value.toString();
                    }else if(sub_value.isArray){
                        QJsonArray array = sub_value.toArray();
                        for(int j = 0; j < array.size(); ++j)
                            qDebug() << "   " << array[i].toString();
                    }
                }
            }
        }
    }
}