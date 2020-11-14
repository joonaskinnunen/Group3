#include "transferwindow.h"
#include "ui_transferwindow.h"

TransferWindow::TransferWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransferWindow)
{
    ui->setupUi(this);

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
