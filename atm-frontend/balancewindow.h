#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include "cardsingleton.h"

#include <QWidget>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BalanceWindow(QWidget *parent = nullptr);
    ~BalanceWindow();

private slots:
    void on_pushButtonExit_clicked();

private:
    Ui::BalanceWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // BALANCEWINDOW_H
