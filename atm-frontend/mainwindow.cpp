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
    QString cardFound = "false";

    QString cardId = this->ui->lineEditId->text();
    HttpLibrary *hl = new HttpLibrary;

    if(hl->checkCard(cardId)) {
        Login *login = new Login(cardId);
        login->show();
        this->close();
    }
    this->ui->labelErrorMessage->setText("Tiliä ei löydy!");
}
