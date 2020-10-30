#include "accountchoicewindow.h"
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
