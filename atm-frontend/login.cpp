#include "login.h"
#include "ui_login.h"
#include "httplibrary.h"
#include "accountchoicewindow.h"
#include "exitwindow.h"
#include<QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->labelCardId->setText("Tili: " + QString::number(cs->getCardId()));
    ui->labelWelcomeMsg->setText("Tervetuloa " + cs->getOwner() + "!");

    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

Login::~Login()
{
    delete ui;
    ui=nullptr;
}

void Login::on_pushButtonCheckPin_clicked()
{
    HttpLibrary *hl = new HttpLibrary;    
    qDebug()<<"data for lib function from login: \n Card id:"+ QString::number(cs->getCardId()) << "\nPin code:" + this->ui->lineEditPin->text();
    if(hl->checkPin(QString::number(cs->getCardId()), this->ui->lineEditPin->text())) {
        hide();
        AccountChoiceWindow *acw = new AccountChoiceWindow();
        acw->show();
    }
    ui->labelErrorMessage->setStyleSheet("QLabel { color : red; }");
    ui->labelErrorMessage->setText("Virheellinen pin-koodi!");

}

void Login::on_pushButtonExit_clicked()
{
    this->close();
}

void Login::on_pushButtonOne_clicked()
{
    ui->lineEditPin->insert("1");
}

void Login::on_pushButtonTwo_clicked()
{
    ui->lineEditPin->insert("2");
}

void Login::on_pushButtonThree_clicked()
{
    ui->lineEditPin->insert("3");
}

void Login::on_pushButtonFour_clicked()
{
    ui->lineEditPin->insert("4");
}

void Login::on_pushButtonFive_clicked()
{
    ui->lineEditPin->insert("5");
}

void Login::on_pushButtonSix_clicked()
{
    ui->lineEditPin->insert("6");
}

void Login::on_pushButtonSeven_clicked()
{
    ui->lineEditPin->insert("7");
}

void Login::on_pushButtonEight_clicked()
{
    ui->lineEditPin->insert("8");
}

void Login::on_pushButtonNine_clicked()
{
    ui->lineEditPin->insert("9");
}

void Login::on_pushButtonZero_clicked()
{
    ui->lineEditPin->insert("0");
}
void Login::on_pushButtonCancel_clicked()
{
    hide();
    ExitWindow *ewf = new ExitWindow("");
    ewf->show();
}

void Login::on_pushButtonClear_clicked()
{
    ui->lineEditPin->setText("");
}

void Login::on_pushButtonEnter_clicked()
{
    ui->pushButtonCheckPin->click();
}
