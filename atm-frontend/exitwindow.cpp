#include "exitwindow.h"
#include "mainwindow.h"
#include "ui_exitwindow.h"

ExitWindow::ExitWindow(QString message, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExitWindow)
{
    ui->setupUi(this);
    ui->labelMessage->setStyleSheet("QLabel {color: green; }");
    ui->labelMessage->setText(message);
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
