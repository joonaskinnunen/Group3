#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include "cardsingleton.h"

#include <QWidget>

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DepositWindow(QWidget *parent = nullptr);
    ~DepositWindow();

public slots:
    void onKeyPressed(const QString &text);

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonTwenty_clicked();

    void on_pushButtonFourty_clicked();

    void on_pushButtonFifty_clicked();

    void on_pushButtonHundred_clicked();

    void on_pushButtonWdCustomAmount_clicked();

private:
    Ui::DepositWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // DEPOSITWINDOW_H
