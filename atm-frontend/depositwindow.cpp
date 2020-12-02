#include "depositwindow.h"
#include "exitwindow.h"
#include "ui_depositwindow.h"
#include "keypad.h"

DepositWindow::DepositWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepositWindow)
{
    ui->setupUi(this);

    Keypad *keypad = new Keypad(this);
    connect(keypad,SIGNAL(keyPressed(const QString &)), this, SLOT(onKeyPressed(const QString &)));
    ui->verticalLayout->addWidget(keypad);

    QPixmap pmbg(":/atm-frontend/bgwithkeypad.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

DepositWindow::~DepositWindow()
{
    delete ui;
    ui=nullptr;
}

void DepositWindow::onKeyPressed(const QString &text)
{
    qDebug() << "\n vastaanotto: " << text;
    if(text == "cancel") {
        this->on_pushButtonExit_clicked();
    } else if (text == "clear") {
        ui->lineEditDepositAmount->setText("");
    } else if (text == "ok") {

        this->on_pushButtonDepositCustomAmount_clicked();

    } else {
        ui->lineEditDepositAmount->insert(text);
    }
}


void DepositWindow::on_pushButtonExit_clicked()
{
    this->close();
}

void DepositWindow::on_pushButtonTwenty_clicked()
{
    QString message = cs->makeDeposit(20);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}

void DepositWindow::on_pushButtonFourty_clicked()
{
    QString message = cs->makeDeposit(40);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}

void DepositWindow::on_pushButtonFifty_clicked()
{
    QString message = cs->makeDeposit(50);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}

void DepositWindow::on_pushButtonHundred_clicked()
{
    QString message = cs->makeDeposit(100);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}


void DepositWindow::on_pushButtonDepositCustomAmount_clicked()
{
    int amount = ui->lineEditDepositAmount->text().toInt();
    QString message = cs->makeDeposit(amount);
    hide();
    ExitWindow *ewf = new ExitWindow(message);
    ewf->show();
}
