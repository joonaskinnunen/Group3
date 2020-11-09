#include "accountchoicewindow.h"
#include "actionchoicewindow.h"
#include "ui_accountchoicewindow.h"

AccountChoiceWindow::AccountChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountChoiceWindow)
{
    ui->setupUi(this);

    QPixmap pmbg(":/atm-frontend/bg.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

AccountChoiceWindow::~AccountChoiceWindow()
{
    delete ui;
    ui=nullptr;
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
