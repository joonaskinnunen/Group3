#include "exitwindow.h"
#include "ui_exitwindow.h"

#include <QString>

ExitWindow::ExitWindow(QString message, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExitWindow)
{
    ui->setupUi(this);
    ui->labelMessage->setText(message);
}

ExitWindow::~ExitWindow()
{
    delete ui;
}

void ExitWindow::on_pushButtonExit_clicked()
{
    this->close();
}
