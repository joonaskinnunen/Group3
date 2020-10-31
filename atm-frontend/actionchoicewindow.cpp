#include "actionchoicewindow.h"
#include "ui_actionchoicewindow.h"

ActionChoiceWindow::ActionChoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ActionChoiceWindow)
{
    ui->setupUi(this);
}

ActionChoiceWindow::~ActionChoiceWindow()
{
    delete ui;
}
