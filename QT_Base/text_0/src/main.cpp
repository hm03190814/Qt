#include <QApplication>
#include <QPushButton>
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();

    return QApplication::exec();

}
