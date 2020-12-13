#include "accountchoicewindow.h"
#include "actionchoicewindow.h"
#include "exitwindow.h"
#include "ui_accountchoicewindow.h"

AccountChoiceWindow::AccountChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountChoiceWindow)
{
    ui->setupUi(this);

    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
    if (cs->getCaId() == 0) {
        this->ui->pushButtonCredit->hide();
        this->ui->label_2->hide();
    }
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

void AccountChoiceWindow::on_pushButtonExit_clicked()
{
    hide();
    ExitWindow *ew = new ExitWindow("");
    ew->show();
}
