#include "login.h"
#include "ui_login.h"
#include "httplibrary.h"
#include "accountchoicewindow.h"
#include<QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->labelCardId->setText(QString::number(cs->getCardId()));
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButtonCheckPin_clicked()
{
    HttpLibrary *hl = new HttpLibrary;    
    qDebug()<<"data for lib function from login: \n Card id:"+ this->ui->labelCardId->text() + "\nPin code:" + this->ui->lineEditPin->text();
    if(hl->checkPin(QString::number(cs->getCardId()), this->ui->lineEditPin->text())) {
        hide();
        AccountChoiceWindow *acw = new AccountChoiceWindow();
        acw->show();
    }
    ui->labelErrorMessage->setStyleSheet("QLabel { color : red; }");
    ui->labelErrorMessage->setText("Virheellinen pin-koodi!");

}
