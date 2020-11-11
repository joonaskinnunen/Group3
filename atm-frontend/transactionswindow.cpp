#include "transactionswindow.h"
#include "ui_transactionswindow.h"

#include <QStandardItemModel>
#include <httplibrary.h>

TransactionsWindow::TransactionsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionsWindow)
{
    ui->setupUi(this);

    HttpLibrary *hl = new HttpLibrary;

    QPixmap pmbg(":/atm-frontend/bg.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);

    qDebug() << hl->getTransactions("11000");

}

TransactionsWindow::~TransactionsWindow()
{
    delete ui;
    ui=nullptr;
}

void TransactionsWindow::on_pushButtonExit_clicked()
{
    this->close();
}
