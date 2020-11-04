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

private:
    Ui::WithdrawalWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // WITHDRAWALWINDOW_H
