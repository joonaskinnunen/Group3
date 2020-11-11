#include "accountchoicewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httplibrary.h"
#include "login.h"

#include <QDebug>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
  //  qDebug()<< hl->checkCard(cardId);
    QJsonObject cardObj = hl->checkCard(cardId);
 //   qDebug()<< "\n" << cardObj["card_id"].toString().toInt() << "\n";
    if(!cardObj.isEmpty()) {
        qDebug() << "cardObj[d_balance].toString().toDouble(): " << QString::number(cardObj["d_balance"].toString().toDouble(), 'f', 2);
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
        qDebug() << QString::number(cs->getDaBalance(), 'f', 2);
    }
    ui->labelErrorMessage->setStyleSheet("QLabel { color : red; }");
    ui->labelErrorMessage->setText("Tiliä ei löydy!");
}

void MainWindow::on_pushButtonExit_clicked()
{
    this->close();
}
