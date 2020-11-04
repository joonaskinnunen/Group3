#include "cardsingleton.h"

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

QString CardSingleton::getCardId() const
{
    return cardId;
}

void CardSingleton::setCardId(QString value)
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

float CardSingleton::getCaBalance() const
{
    return caBalance;
}

void CardSingleton::setCaBalance(float value)
{
    caBalance = value;
}

float CardSingleton::getDaBalance() const
{
    return daBalance;
}

void CardSingleton::setDaBalance(float value)
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
    if(this->isCreditSelected) {
        if(this->getCaBalance() > amount) {
            this->setCaBalance(this->caBalance - amount);
            return "Nosto onnistui! Tilillä käytettävissä: " + QString::number(this->getCaLimit() + this->caBalance) + "€";
        } else {
            return "Nosto epäonnistui! Tilin luottoraja ei riitä noston tekemiseen. Luottoa käytettävissä: " + QString::number(this->getCaBalance()) + "€";
        }
    }
    if(this->getDaBalance() > amount) {
        this->setDaBalance(this->daBalance - amount);
        return "Nosto onnistui! Tilin saldo: " + QString::number(this->getCaBalance()) + "€";
    } else {
        return "Nosto epäonnistui! Tilin saldo ei riitä noston tekemiseen. Tilillä käytettävissä: " + QString::number(this->getCaLimit() + this->caBalance) + "€";
    }
}

CardSingleton* CardSingleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CardSingleton();
    }

    return instance;
}
