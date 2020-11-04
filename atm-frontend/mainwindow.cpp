#include "accountchoicewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httplibrary.h"
#include "login.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonLogin_clicked()
{
    QString cardId = this->ui->lineEditId->text();
    HttpLibrary *hl = new HttpLibrary;
    qDebug()<< hl->checkCard(cardId);
    QJsonObject cardObj = hl->checkCard(cardId);
    if(!cardObj.isEmpty()) {
        cs->setCardId(cardObj["card_id"].toString());
        cs->setCaId(cardObj["ca_id"].toInt());
        cs->setDaId(cardObj["da_id"].toInt());
        cs->setCaBalance(cardObj["c_balance"].toDouble());
        cs->setDaBalance(cardObj["d_balance"].toDouble());
        cs->setOwner(cardObj["owner"].toString());
        cs->setCaLimit(cardObj["c_limit"].toInt());
        Login *login = new Login();
        login->show();
        this->close();
    }
    ui->labelErrorMessage->setStyleSheet("QLabel { color : red; }");
    ui->labelErrorMessage->setText("Tiliä ei löydy!");
}
