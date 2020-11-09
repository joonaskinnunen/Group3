#include "exitwindow.h"
#include "mainwindow.h"
#include "ui_exitwindow.h"

ExitWindow::ExitWindow(QString message, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExitWindow)
{
    ui->setupUi(this);
    ui->labelMessage->setStyleSheet("QLabel {color: green; }");
    QString msgColor = message.contains("epäonnistui") ? "red" : "green";
    ui->labelMessage->setStyleSheet("QLabel {color: " + msgColor + "; }");
    ui->labelMessage->setText(message);

    QPixmap pmbg(":/atm-frontend/bg.png");
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
