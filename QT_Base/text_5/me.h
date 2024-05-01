#ifndef ME_H
#define ME_H

#include <QObject>

class me : public QObject
{
    Q_OBJECT
public:
    explicit me(QObject *parent = nullptr);

public slots:
    /// @brief 槽函数
    void eat();
    void eat(QString msg);
};

#endif // ME_H
