#include "cardsingleton.h"
#include<QDebug>

#include <QString>

CardSingleton* CardSingleton::instance = nullptr;

int CardSingleton::getDaId() const
{
    return daId;
}

void CardSingleton::setDaId(int value)
{
    daId = value;
}

int CardSingleton::getCaId() const
{
    return caId;
}

void CardSingleton::setCaId(int value)
{
    caId = value;
}

int CardSingleton::getCardId() const
{
    return cardId;
}

void CardSingleton::setCardId(int value)
{
    cardId = value;
}

int CardSingleton::getCaLimit() const
{
    return caLimit;
}

void CardSingleton::setCaLimit(int value)
{
    caLimit = value;
}

double CardSingleton::getCaBalance() const
{
    return caBalance;
}

void CardSingleton::setCaBalance(double value)
{
    caBalance = value;
}

double CardSingleton::getDaBalance() const
{
    return daBalance;
}

void CardSingleton::setDaBalance(double value)
{
    daBalance = value;
}

QString CardSingleton::getOwner() const
{
    return owner;
}

void CardSingleton::setOwner(const QString &value)
{
    owner = value;
}

bool CardSingleton::getIsCreditSelected() const
{
    return isCreditSelected;
}

void CardSingleton::setIsCreditSelected(bool value)
{
    isCreditSelected = value;
}

QString CardSingleton::makeWithdrawal(int amount)
{
    this->setAmount(amount);
    if(this->isCreditSelected) {
        if(this->getCaBalance() + this->getCaLimit() > amount) {
            this->setCaBalance(this->caBalance - amount);
            hl->creditUpdate(this->caId, this->getCaBalance(), this->getCaLimit());
            return "Nosto onnistui! Tilillä käytettävissä: " + QString::number(this->getCaLimit() + this->caBalance, 'f', 2) + "€" + "\nTilin luottoraja: " + this->getCaLimit() + "€";
        } else {
            return "Nosto epäonnistui! Tilin luottoraja ei riitä noston tekemiseen.\nLuottoa käytettävissä: " + QString::number(this->getCaBalance() + this->getCaLimit(), 'f', 2) + "€";
        }
    }
    if(this->getDaBalance() > amount) {
        this->setDaBalance(this->daBalance - amount);
        hl->debitUpdate(this->daId, this->getDaBalance());
        qDebug() << "QString::number(this->getDaBalance(), 'f', 2): " << QString::number(this->getDaBalance(), 'f', 2);
        return "Nosto onnistui! Tilin saldo: " + QString::number(this->getDaBalance(), 'f', 2) + "€";
    } else {
        return "Nosto epäonnistui! Tilin saldo ei riitä noston tekemiseen.\nTilillä käytettävissä: " + QString::number(this->daBalance, 'f', 2) + "€";
    }
}

QString CardSingleton::makeDeposit(int amount)
{
  if(this->isCreditSelected) {
      this->setCaBalance(this->caBalance + amount);
       hl->creditUpdate(this->caId, this->getCaBalance(), this->getCaLimit());
      return "Talletus onnistui!\nTilillä käytettävissä: " + QString::number(this->getCaLimit() + this->caBalance, 'f', 2) + "€";
  }
  else {
      this->setDaBalance(this->daBalance + amount);
       hl->debitUpdate(this->daId, this->getDaBalance());
      return "Talletus onnistui!\nTilillä käytettävissä: " + QString::number(this->daBalance, 'f', 2) + "€";

  }
}


QString CardSingleton::makeTransfer(int receiverId, double amount)
{
    if(this->isCreditSelected) {
        if(this->getCaBalance() + this->getCaLimit() > amount) {
            this->setCaBalance(this->caBalance - amount);
            hl->makeBankTransfer(this->caId, receiverId, amount);
            return "Tilisiirto onnistui! Tilillä käytettävissä: " + QString::number(this->getCaLimit() + this->caBalance, 'f', 2) + "€" + "\nTilin luottoraja: " + this->getCaLimit() + "€";
        } else {
            return "Tilisiirto epäonnistui! Tilin luottoraja ei riitä siirron tekemiseen.\nLuottoa käytettävissä: " + QString::number(this->getCaBalance() + this->getCaLimit(), 'f', 2) + "€";
        }
    }
    if(this->getDaBalance() > amount) {
        this->setDaBalance(this->daBalance - amount);
        hl->makeBankTransfer(this->daId, receiverId, amount);
        return "Tilisiirto onnistui! Tilin saldo: " + QString::number(this->getDaBalance(), 'f', 2) + "€";
    }
    return "Tilisiirto epäonnistui! Tilin saldo ei riitä siirron tekemiseen.\nTilillä käytettävissä: " + QString::number(this->daBalance, 'f', 2) + "€";
}

QJsonArray CardSingleton::getTransactions() const
{
    return transactions;
}

void CardSingleton::setTransactions(const QJsonArray &value)
{
    transactions = value;
}

int CardSingleton::getAmount() const
{
    return amount;
}

void CardSingleton::setAmount(int value)
{
    amount = value;
}

CardSingleton* CardSingleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CardSingleton();
    }

    return instance;
}

