#include "login.h"
#include "ui_login.h"
#include "httplibrary.h"
#include<QDebug>

Login::Login(QString cardId, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->labelCardId->setText(cardId);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButtonCheckPin_clicked()
{
    HttpLibrary *hl = new HttpLibrary;    
    qDebug()<<"data for lib function from login: \n Card id:"+ this->ui->labelCardId->text() + "\nPin code:" + this->ui->lineEditPin->text();
    hl->checkPin(this->ui->labelCardId->text(), this->ui->lineEditPin->text());
}
