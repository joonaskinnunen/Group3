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

void WithdrawalWindow::on_pushButtonOne_clicked()
{
    ui->lineEditWithDrawalAmount->insert("1");
}

void WithdrawalWindow::on_pushButtonTwo_clicked()
{
    ui->lineEditWithDrawalAmount->insert("2");
}

void WithdrawalWindow::on_pushButtonThree_clicked()
{
    ui->lineEditWithDrawalAmount->insert("3");
}

void WithdrawalWindow::on_pushButtonFour_clicked()
{
    ui->lineEditWithDrawalAmount->insert("4");
}

void WithdrawalWindow::on_pushButtonFive_clicked()
{
    ui->lineEditWithDrawalAmount->insert("5");
}

void WithdrawalWindow::on_pushButtonSix_clicked()
{
    ui->lineEditWithDrawalAmount->insert("6");
}

void WithdrawalWindow::on_pushButtonSeven_clicked()
{
    ui->lineEditWithDrawalAmount->insert("7");
}

void WithdrawalWindow::on_pushButtonEight_clicked()
{
    ui->lineEditWithDrawalAmount->insert("8");
}

void WithdrawalWindow::on_pushButtonNine_clicked()
{
    ui->lineEditWithDrawalAmount->insert("9");
}

void WithdrawalWindow::on_pushButtonZero_clicked()
{
    ui->lineEditWithDrawalAmount->insert("0");
}
void WithdrawalWindow::on_pushButtonCancel_clicked()
{
    hide();
    ExitWindow *ewf = new ExitWindow("");
    ewf->show();
}

void WithdrawalWindow::on_pushButtonClear_clicked()
{
    ui->lineEditWithDrawalAmount->setText("");
}

void WithdrawalWindow::on_pushButtonEnter_clicked()
{
    ui->pushButtonWdCustomAmount->click();
}
