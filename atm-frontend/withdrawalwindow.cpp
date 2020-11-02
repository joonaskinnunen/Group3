#include "withdrawalwindow.h"
#include "ui_withdrawalwindow.h"

WithdrawalWindow::WithdrawalWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WithdrawalWindow)
{
    ui->setupUi(this);
}

WithdrawalWindow::~WithdrawalWindow()
{
    delete ui;
}
