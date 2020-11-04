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
