#include "exitwindow.h"
#include "ui_exitwindow.h"

ExitWindow::ExitWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExitWindow)
{
    ui->setupUi(this);
}

ExitWindow::~ExitWindow()
{
    delete ui;
}
