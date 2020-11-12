#include "actionchoicewindow.h"
#include "balancewindow.h"
#include "transactionswindow.h"
#include "ui_actionchoicewindow.h"
#include "withdrawalwindow.h"

#include <QJsonArray>

ActionChoiceWindow::ActionChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionChoiceWindow)
{
    ui->setupUi(this);
    QPixmap pmbg(":/atm-frontend/bg.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

ActionChoiceWindow::~ActionChoiceWindow()
{
    delete ui;
    ui=nullptr;
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
    int acc;
    if(cs->getIsCreditSelected()){
        acc = cs->getCaId();
    }
    acc = cs->getDaId();
    qDebug() << "\n cardsingleton ca id: " << cs->getCaId();
    HttpLibrary *hl = new HttpLibrary;
    QJsonArray jsarr = hl->getTransactions(acc);
    hide();
    TransactionsWindow *tw = new TransactionsWindow(jsarr);
    tw->show();
}

void ActionChoiceWindow::on_pushButtonExit_clicked()
{
    this->close();
}
