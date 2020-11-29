#ifndef WITHDRAWALWINDOW_H
#define WITHDRAWALWINDOW_H

#include "cardsingleton.h"

#include <QWidget>

namespace Ui {
class WithdrawalWindow;
}

class WithdrawalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawalWindow(QWidget *parent = nullptr);
    ~WithdrawalWindow();

private slots:
    void on_pushButtonTwenty_clicked();

    void on_pushButtonFourty_clicked();

    void on_pushButtonFifty_clicked();

    void on_pushButtonHundred_clicked();

    void on_pushButtonWdCustomAmount_clicked();

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
    Ui::WithdrawalWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // WITHDRAWALWINDOW_H
