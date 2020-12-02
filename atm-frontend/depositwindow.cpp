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

        // Vaihda tähän oikea toiminto
        this->close();

    } else {
        ui->lineEditDepositAmount->insert(text);
    }
}


void DepositWindow::on_pushButtonExit_clicked()
{
    this->close();
}
