#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "cardsingleton.h"
#include "httplibrary.h"

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButtonCheckPin_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonOne_clicked();

    void on_pushButtonTwo_clicked();

    void on_pushButtonThree_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonFour_clicked();

    void on_pushButtonFive_clicked();

    void on_pushButtonSix_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonSeven_clicked();

    void on_pushButtonEight_clicked();

    void on_pushButtonNine_clicked();

    void on_pushButtonEnter_clicked();

    void on_pushButtonZero_clicked();

private:
    Ui::Login *ui;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // LOGIN_H
