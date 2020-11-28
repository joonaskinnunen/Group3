#include "accountchoicewindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "httplibrary.h"
#include "login.h"
#include "qmath.h"
#include "note.h"
#include "exitwindow.h"

#include <QDebug>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QRegExpValidator>
#include <QSequentialAnimationGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    group = new QSequentialAnimationGroup;

//    int amount = 410;
//    QList<int> list = getNotes(amount);
//    Note *twohundred = new Note(ui->label_twohundred, list[0], ui->label_money_2);
//    Note *hundred = new Note(ui->label_hundred, list[1], ui->label_money_2);
//    Note *fifty = new Note(ui->label_fifty, list[2], ui->label_money_2);
//    Note *twenty = new Note(ui->label_twenty, list[3], ui->label_money_2);
//    Note *ten = new Note(ui->label_ten, list[4], ui->label_money_2);
//    QList<Note> *notes = new QList<Note> ;
//    notes->append(*twohundred);
//    notes->append(*hundred);
//    notes->append(*fifty);
//    notes->append(*twenty);
//    notes->append(*ten);

//    for (int i = 0;i < notes->size() ;i++ ) {
//        Note note = notes->at(i);
//        if(note.getCount() > 0){
//            note.setCopy(ui->label_money_2);
//            group->addAnimation(note.getAnimation());
//            if(note.getCount() > 1) {
//                group->addAnimation(note.getLoopAnim());
//            }
//        }
//    }

//    group->start();

    ui->lineEditId->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineEditId));

    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
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

//QList<int> MainWindow::getNotes(int amount)
//{
//    int twohundreds = qFloor(amount / 200);
//    amount -= twohundreds*200;
//    int hundreds = qFloor(amount / 100);
//    amount -= hundreds*100;
//    int fifties = qFloor(amount / 50);
//    amount -= fifties*50;
//    int twenties = qFloor(amount / 20);
//    amount -= twenties*20;
//    int tens = amount/10;

//    QList<int> notes;
//    notes.append(twohundreds);
//    notes.append(hundreds);
//    notes.append(fifties);
//    notes.append(twenties);
//    notes.append(tens);

//    qDebug()<< "\n notes: " << notes;
//    return notes;
//}

void MainWindow::on_pushButtonOne_clicked()
{
    ui->lineEditId->insert("1");
}

void MainWindow::on_pushButtonTwo_clicked()
{
    ui->lineEditId->insert("2");
}

void MainWindow::on_pushButtonThree_clicked()
{
    ui->lineEditId->insert("3");
}

void MainWindow::on_pushButtonFour_clicked()
{
    ui->lineEditId->insert("4");
}

void MainWindow::on_pushButtonFive_clicked()
{
    ui->lineEditId->insert("5");
}

void MainWindow::on_pushButtonSix_clicked()
{
    ui->lineEditId->insert("6");
}

void MainWindow::on_pushButtonSeven_clicked()
{
    ui->lineEditId->insert("7");
}

void MainWindow::on_pushButtonEight_clicked()
{
    ui->lineEditId->insert("8");
}

void MainWindow::on_pushButtonNine_clicked()
{
    ui->lineEditId->insert("9");
}

void MainWindow::on_pushButtonZero_clicked()
{
    ui->lineEditId->insert("0");
}
void MainWindow::on_pushButtonCancel_clicked()
{
    hide();
    ExitWindow *ewf = new ExitWindow("");
    ewf->show();
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->lineEditId->setText("");
}

void MainWindow::on_pushButtonEnter_clicked()
{
    ui->pushButtonLogin->click();
}
