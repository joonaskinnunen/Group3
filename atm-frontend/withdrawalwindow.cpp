#include "withdrawalwindow.h"
#include "ui_withdrawalwindow.h"
#include "exitwindow.h"

WithdrawalWindow::WithdrawalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WithdrawalWindow)
{
    ui->setupUi(this);
}

WithdrawalWindow::~WithdrawalWindow()
{
    delete ui;
}

void WithdrawalWindow::on_pushButtonTwenty_clicked()
{
        QString message = cs->makeWithdrawal(20);
        hide();
        ExitWindow *ewf = new ExitWindow(message);
        ewf->show();
}

void WithdrawalWindow::on_pushButtonFourty_clicked()
{
    QString message = cs->makeWithdrawal(40);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}

void WithdrawalWindow::on_pushButtonFifty_clicked()
{
    QString message = cs->makeWithdrawal(50);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}

void WithdrawalWindow::on_pushButtonHundred_clicked()
{
    QString message = cs->makeWithdrawal(100);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}

void WithdrawalWindow::on_pushButtonWdCustomAmount_clicked()
{
    int amount = ui->lineEditWithDrawalAmount->text().toInt();
    QString message = cs->makeWithdrawal(amount);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}
