#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    QString balance = cs->getIsCreditSelected() ? QString::number(cs->getCaBalance()) : QString::number(cs ->getDaBalance());
    if(cs->getIsCreditSelected()) {
        ui->labelBalance->setText("Luottoa käytettävissä: " + QString::number((cs->getCaLimit() + cs->getCaBalance())));
    } else {
        ui->labelBalance->setText("Tilin saldo: " + QString::number(cs ->getDaBalance()));
    }
}

BalanceWindow::~BalanceWindow()
{
    delete ui;
}

void BalanceWindow::on_pushButtonExit_clicked()
{
    this->close();
}
