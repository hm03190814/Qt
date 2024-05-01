#ifndef GIRL_H
#define GIRL_H

#include <QObject>

class girl : public QObject
{
    Q_OBJECT
public:
    explicit girl(QObject *parent = nullptr);

signals:
    /// @brief 信号只需要声明 不需要定义
    void hungry(); 
    void hungry(QString msg);
    

};

#endif // GIRL_H
