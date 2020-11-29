#include "exitwindow.h"
#include "mainwindow.h"
#include "ui_exitwindow.h"
#include "qmath.h"
#include "note.h"

ExitWindow::ExitWindow(QString message, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExitWindow)
{
    ui->setupUi(this);
    ui->labelMessage->setStyleSheet("QLabel {color: green; }");
    QString msgColor = message.contains("epäonnistui") ? "red" : "green";
    ui->labelMessage->setStyleSheet("QLabel {color: " + msgColor + "; }");
    ui->labelMessage->setText(message);

    group = new QSequentialAnimationGroup;

    int amount = cs->getAmount();
    QList<int> list = getNoteCounts(amount);
    Note *twohundred = new Note(ui->label_twohundred, list[0], ui->label_money_2);
    Note *hundred = new Note(ui->label_hundred, list[1], ui->label_money_2);
    Note *fifty = new Note(ui->label_fifty, list[2], ui->label_money_2);
    Note *twenty = new Note(ui->label_twenty, list[3], ui->label_money_2);
    Note *ten = new Note(ui->label_ten, list[4], ui->label_money_2);
    QList<Note> *notes = new QList<Note> ;
    notes->append(*twohundred);
    notes->append(*hundred);
    notes->append(*fifty);
    notes->append(*twenty);
    notes->append(*ten);

    for (int i = 0;i < notes->size() ;i++ ) {
        Note note = notes->at(i);
        if(note.getCount() > 0){
            note.setCopy(ui->label_money_2);
            group->addAnimation(note.getAnimation());
            if(note.getCount() > 1) {
                group->addAnimation(note.getLoopAnim());
            }
        }
    }

    group->start();
    if(msgColor == "green") group->start();

    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

ExitWindow::~ExitWindow()
{
    delete ui;
    ui=nullptr;
}

void ExitWindow::on_pushButtonExit_clicked()
{
    this->close();
}

QList<int> ExitWindow::getNoteCounts(int amount)
{
    int twohundreds = qFloor(amount / 200);
    amount -= twohundreds*200;
    int hundreds = qFloor(amount / 100);
    amount -= hundreds*100;
    int fifties = qFloor(amount / 50);
    amount -= fifties*50;
    int twenties = qFloor(amount / 20);
    amount -= twenties*20;
    int tens = amount/10;

    QList<int> notes;
    notes.append(twohundreds);
    notes.append(hundreds);
    notes.append(fifties);
    notes.append(twenties);
    notes.append(tens);

    qDebug()<< "\n notes: " << notes;
    return notes;
}

