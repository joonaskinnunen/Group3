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

    QPixmap pmbg(":/atm-frontend/bg.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
    ui->labelErrorMessage->setStyleSheet("QLabel {color: red; }");
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
    qDebug() << "Receiver account ID: " << receiverAccountId;
    qDebug() << hl->checkAccount(receiverAccountId);
    if(hl->checkAccount(receiverAccountId)) {
        QString message = cs->makeWithdrawal(ui->lineEditAmount->text().toInt());
        if(message.contains("epäonnistui")) {
            ui->labelErrorMessage->setText("Tilin saldo ei riitä siirron tekemiseen!");
        } else {
            hide();
            ExitWindow *ewf = new ExitWindow("Tilisiirto onnistui!");
            ewf->show();
        }
    } else {
        ui->labelErrorMessage->setText("Vastaanottajan tilinumero virheellinen!");
    }

}
