#include "transactionswindow.h"
#include "ui_transactionswindow.h"

TransactionsWindow::TransactionsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionsWindow)
{
    ui->setupUi(this);
}

TransactionsWindow::~TransactionsWindow()
{
    delete ui;
}

void TransactionsWindow::on_pushButtonExit_clicked()
{
    this->close();
}
