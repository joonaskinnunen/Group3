#include "accountchoicewindow.h"
#include "actionchoicewindow.h"
#include "ui_accountchoicewindow.h"

AccountChoiceWindow::AccountChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountChoiceWindow)
{
    ui->setupUi(this);
}

AccountChoiceWindow::~AccountChoiceWindow()
{
    delete ui;
}

void AccountChoiceWindow::on_pushButtonDebit_clicked()
{
    hide();
    ActionChoiceWindow *acwf = new ActionChoiceWindow();
    acwf->show();
}

void AccountChoiceWindow::on_pushButtonCredit_clicked()
{
    cs->setIsCreditSelected(true);
    hide();
    ActionChoiceWindow *acwf = new ActionChoiceWindow();
    acwf->show();
}
