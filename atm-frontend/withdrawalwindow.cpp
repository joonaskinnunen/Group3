#include "withdrawalwindow.h"
#include "ui_withdrawalwindow.h"
#include "exitwindow.h"

#include <QRegExpValidator>

WithdrawalWindow::WithdrawalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WithdrawalWindow)
{
    ui->setupUi(this);

    ui->lineEditWithDrawalAmount->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineEditWithDrawalAmount));

    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

WithdrawalWindow::~WithdrawalWindow()
{
    delete ui;
    ui=nullptr;
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

void WithdrawalWindow::on_pushButtonExit_clicked()
{
    this->close();
}
