#include "actionchoicewindow.h"
#include "balancewindow.h"
#include "transactionswindow.h"
#include "ui_actionchoicewindow.h"
#include "withdrawalwindow.h"

ActionChoiceWindow::ActionChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionChoiceWindow)
{
    ui->setupUi(this);
}

ActionChoiceWindow::~ActionChoiceWindow()
{
    delete ui;
}

void ActionChoiceWindow::on_pushButtonWithdrawal_clicked()
{
    hide();
    WithdrawalWindow *ww = new WithdrawalWindow();
    ww->show();
}

void ActionChoiceWindow::on_pushButtonBalance_clicked()
{
    hide();
    BalanceWindow *bw = new BalanceWindow();
    bw->show();
}

void ActionChoiceWindow::on_pushButtonTransactions_clicked()
{
    hide();
    TransactionsWindow *tw = new TransactionsWindow();
    tw->show();
}
