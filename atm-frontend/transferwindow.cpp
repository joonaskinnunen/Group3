#include "exitwindow.h"
#include "transferwindow.h"
#include "ui_transferwindow.h"
#include <QRegExpValidator>

TransferWindow::TransferWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransferWindow)
{
    ui->setupUi(this);

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

void TransferWindow::on_pushButtonOne_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("1") : ui->lineEditReceiverId->insert("1");
}

void TransferWindow::on_pushButtonTwo_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("2") : ui->lineEditReceiverId->insert("2");
}

void TransferWindow::on_pushButtonThree_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("3") : ui->lineEditReceiverId->insert("3");
}

void TransferWindow::on_pushButtonFour_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("4") : ui->lineEditReceiverId->insert("4");
}

void TransferWindow::on_pushButtonFive_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("5") : ui->lineEditReceiverId->insert("5");
}

void TransferWindow::on_pushButtonSix_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("6") : ui->lineEditReceiverId->insert("6");
}

void TransferWindow::on_pushButtonSeven_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("7") : ui->lineEditReceiverId->insert("7");
}

void TransferWindow::on_pushButtonEight_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("8") : ui->lineEditReceiverId->insert("8");
}

void TransferWindow::on_pushButtonNine_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("9") : ui->lineEditReceiverId->insert("9");
}

void TransferWindow::on_pushButtonZero_clicked()
{
    accountIdInputed ? ui->lineEditAmount->insert("0") : ui->lineEditReceiverId->insert("0");
}
void TransferWindow::on_pushButtonCancel_clicked()
{
    hide();
    ExitWindow *ewf = new ExitWindow("");
    ewf->show();
}

void TransferWindow::on_pushButtonClear_clicked()
{
    accountIdInputed ? ui->lineEditAmount->setText("") : ui->lineEditReceiverId->setText("");
}

void TransferWindow::on_pushButtonEnter_clicked()
{
    if(accountIdInputed) ui->pushButtonOk->click();
    accountIdInputed = true;
    ui->lineEditAmount->setFocus();
}
