#include "balancewindow.h"
#include "ui_balancewindow.h"

BalanceWindow::BalanceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BalanceWindow)
{
    ui->setupUi(this);
    QString balance = cs->getIsCreditSelected() ? QString::number(cs->getCaBalance(), 'f', 2) : QString::number(cs ->getDaBalance(), 'f', 2);
    if(cs->getIsCreditSelected()) {
        ui->labelBalance->setText("Luottoa käytettävissä: " + QString::number((cs->getCaLimit() + cs->getCaBalance()), 'f', 2) + "€");
    } else {
        ui->labelBalance->setText("Tilin saldo: " + QString::number(cs ->getDaBalance(), 'f', 2) + "€");
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
