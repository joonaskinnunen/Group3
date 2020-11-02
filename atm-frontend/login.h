#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "httplibrary.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QString cardId, QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButtonCheckPin_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
