#include "accountchoicewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httplibrary.h"
#include "login.h"

#include <QDebug>
#include <QPixmap>
#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEditId->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineEditId));

    QPixmap pmbg(":/atm-frontend/bg.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
    ui=nullptr;
}


void MainWindow::on_pushButtonLogin_clicked()
{
    QString cardId = this->ui->lineEditId->text();
    HttpLibrary *hl = new HttpLibrary;
    qDebug()<< hl->checkCard(cardId);
    QJsonObject cardObj = hl->checkCard(cardId);
    qDebug()<< "\n cardObj: " << cardObj << "\n";
    if(!cardObj["card_id"].isNull()) {
        cs->setCardId(cardObj["card_id"].toString().toInt());
        cs->setCaId(cardObj["ca_id"].toString().toInt());
        cs->setDaId(cardObj["da_id"].toString().toInt());
        cs->setCaBalance(cardObj["c_balance"].toString().toDouble());
        cs->setDaBalance(cardObj["d_balance"].toString().toDouble());
        cs->setOwner(cardObj["owner"].toString());
        cs->setCaLimit(cardObj["c_limit"].toString().toInt());
        qDebug()<< "\nkortti id:" << cs->getCardId() << "\n";
        Login *login = new Login();
        login->show();
        this->close();
    }
    ui->labelErrorMessage->setStyleSheet("QLabel { color : red; }");
    ui->labelErrorMessage->setText("Tiliä ei löydy!");
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}
