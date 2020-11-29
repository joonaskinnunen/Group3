#include "depositwindow.h"
#include "exitwindow.h"
#include "ui_depositwindow.h"

DepositWindow::DepositWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);
    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

DepositWindow::~DepositWindow()
{
    delete ui;
    ui=nullptr;
}

void DepositWindow::on_pushButtonOne_clicked()
{
    ui->lineEditDepositAmount->insert("1");
}

void DepositWindow::on_pushButtonTwo_clicked()
{
    ui->lineEditDepositAmount->insert("2");
}

void DepositWindow::on_pushButtonThree_clicked()
{
    ui->lineEditDepositAmount->insert("3");
}

void DepositWindow::on_pushButtonFour_clicked()
{
    ui->lineEditDepositAmount->insert("4");
}

void DepositWindow::on_pushButtonFive_clicked()
{
    ui->lineEditDepositAmount->insert("5");
}

void DepositWindow::on_pushButtonSix_clicked()
{
    ui->lineEditDepositAmount->insert("6");
}

void DepositWindow::on_pushButtonSeven_clicked()
{
    ui->lineEditDepositAmount->insert("7");
}

void DepositWindow::on_pushButtonEight_clicked()
{
    ui->lineEditDepositAmount->insert("8");
}

void DepositWindow::on_pushButtonNine_clicked()
{
    ui->lineEditDepositAmount->insert("9");
}

void DepositWindow::on_pushButtonZero_clicked()
{
    ui->lineEditDepositAmount->insert("0");
}
void DepositWindow::on_pushButtonCancel_clicked()
{
    hide();
    ExitWindow *ewf = new ExitWindow("");
    ewf->show();
}

void DepositWindow::on_pushButtonClear_clicked()
{
    ui->lineEditDepositAmount->setText("");
}

void DepositWindow::on_pushButtonEnter_clicked()
{
}

void DepositWindow::on_pushButtonExit_clicked()
{
    this->close();
}
