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

    QPixmap pmbg(":/atm-frontend/bg.png");
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
