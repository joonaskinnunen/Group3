#include "cardsingleton.h"

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

CardSingleton* CardSingleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CardSingleton();
    }

    return instance;
}
