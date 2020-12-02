#include "exitwindow.h"
#include "keypad.h"
#include "transferwindow.h"
#include "ui_transferwindow.h"
#include <QRegExpValidator>

TransferWindow::TransferWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransferWindow)
{
    ui->setupUi(this);

    Keypad *keypad = new Keypad(this);
    connect(keypad,SIGNAL(keyPressed(const QString &)), this, SLOT(onKeyPressed(const QString &)));
    ui->verticalLayout->addWidget(keypad);

    ui->lineEditAmount->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineEditAmount));
    ui->lineEditReceiverId->setValidator(new QRegExpValidator(QRegExp("[0-9]*"), ui->lineEditReceiverId));

    ui->labelAccountId->setText("Tilinumero: " + QString::number(cs->getIsCreditSelected() ? cs->getCaId() : cs->getDaId()));
    ui->labelBalance->setText("Käytettävissä: " + QString::number(cs->getIsCreditSelected() ? cs->getCaBalance() + cs->getCaLimit() : cs->getDaBalance()) + "€");

    ui->labelErrorMessage->setStyleSheet("QLabel {color: red; }");

    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

TransferWindow::~TransferWindow()
{
    delete ui;
    ui=nullptr;
}

void TransferWindow::onKeyPressed(const QString &text)
{
    qDebug() << "\n vastaanotto: " << text;
    if(text == "cancel") {
        hide();
        ExitWindow *ewf = new ExitWindow("");
        ewf->show();
    } else if (text == "clear") {
        accountIdInputed ? ui->lineEditAmount->setText("") : ui->lineEditReceiverId->setText("");
    } else if (text == "ok") {
        this->on_pushButtonEnter_clicked();
    } else {
        accountIdInputed ? ui->lineEditAmount->insert(text) : ui->lineEditReceiverId->insert(text);
    }
}

void TransferWindow::on_pushButtonExit_clicked()
{
    this->close();
}

void TransferWindow::on_pushButtonOk_clicked()
{
    int receiverAccountId = ui->lineEditReceiverId->text().toInt();
    int amount = ui->lineEditAmount->text().toInt();
    qDebug() << "Receiver account ID: " << QString::number(receiverAccountId);
    qDebug() << ui->lineEditReceiverId->text();

    if(hl->checkAccount(receiverAccountId)) {
        QString message = cs->makeTransfer(receiverAccountId, amount);
        hide();
        ExitWindow *ewf = new ExitWindow(message);
        ewf->show();
    } else {
        ui->labelErrorMessage->setText("Tilinumerolla " + QString::number(receiverAccountId) + " ei löytynyt tiliä!");
    }
}

void TransferWindow::on_pushButtonEnter_clicked()
{
    if(accountIdInputed) ui->pushButtonOk->click();
    accountIdInputed = true;
    ui->lineEditAmount->setFocus();
}
