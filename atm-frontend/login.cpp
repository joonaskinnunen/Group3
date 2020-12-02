#include "login.h"
#include "ui_login.h"
#include "httplibrary.h"
#include "accountchoicewindow.h"
#include "exitwindow.h"
#include "keypad.h"
#include<QDebug>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->labelCardId->setText("Tili: " + QString::number(cs->getCardId()));
    ui->labelWelcomeMsg->setText("Tervetuloa " + cs->getOwner() + "!");

    Keypad *keypad = new Keypad(this);
    connect(keypad,SIGNAL(keyPressed(const QString &)), this, SLOT(onKeyPressed(const QString &)));
    ui->verticalLayout->addWidget(keypad);

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

void Login::onKeyPressed(const QString &text)
{
    if(text == "cancel") {
        this->on_pushButtonExit_clicked();
    } else if (text == "clear") {
        ui->lineEditPin->setText("");
        pin = "";
    } else if (text == "ok") {
        this->on_pushButtonCheckPin_clicked();
    } else {
        pin += text;
        ui->lineEditPin->insert("*");
    }
}

void Login::on_pushButtonCheckPin_clicked()
{
    HttpLibrary *hl = new HttpLibrary;    
    qDebug()<<"data for lib function from login: \n Card id:"+ QString::number(cs->getCardId()) << "\nPin code:" + pin;
    if(hl->checkPin(QString::number(cs->getCardId()), pin)) {
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
