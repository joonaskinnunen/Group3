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

private:
    Ui::WithdrawalWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // WITHDRAWALWINDOW_H
