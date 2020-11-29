#include "keypad.h"
#include "ui_keypad.h"
#include "mainwindow.h"

Keypad::Keypad(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Keypad)
{
    ui->setupUi(this);
}

Keypad::~Keypad()
{
    delete ui;
}

void Keypad::on_btn_1_clicked()
{
    emit this->newTextEntered("1");
}


void Keypad::on_btn_2_clicked()
{
    emit this->newTextEntered("2");
}

void Keypad::on_btn_3_clicked()
{
    emit this->newTextEntered("3");
}

void Keypad::on_btn_4_clicked()
{
    emit this->newTextEntered("4");
}

void Keypad::on_btn_5_clicked()
{
    emit this->newTextEntered("5");
}

void Keypad::on_btn_6_clicked()
{
    emit this->newTextEntered("6");
}

void Keypad::on_btn_7_clicked()
{
    emit this->newTextEntered("7");
}

void Keypad::on_btn_8_clicked()
{
    emit this->newTextEntered("8");
}

void Keypad::on_btn_9_clicked()
{
    emit this->newTextEntered("9");
}

void Keypad::on_btn_0_clicked()
{
    emit this->newTextEntered("0");
}

void Keypad::on_btn_cancel_clicked()
{
    emit this->newTextEntered("cancel");
}

void Keypad::on_btn_clear_clicked()
{
    emit this->newTextEntered("clear");
}

void Keypad::on_btn_ok_clicked()
{
    emit this->newTextEntered("ok");
}
