#ifndef CLASS_WIDGET_H
#define CLASS_WIDGET_H

#include <QWidget>

namespace Ui {
class class_widget;
}

class class_widget : public QWidget
{
    Q_OBJECT

public:
    explicit class_widget(QWidget *parent = nullptr);
    ~class_widget();

private:
    Ui::class_widget *ui;
};

#endif // CLASS_WIDGET_H
