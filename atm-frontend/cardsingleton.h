#ifndef CARDSINGLETON_H
#define CARDSINGLETON_H

#include <QJsonArray>
#include <qstring.h>
#include "httplibrary.h"

class CardSingleton
{
private:
    static CardSingleton* instance;
    int daId, caId, caLimit, cardId;
    double caBalance, daBalance;
    QString owner;
    bool isCreditSelected = false;
    QJsonArray transactions;
    HttpLibrary *hl = new HttpLibrary;
    QJsonArray transactions;


public:
    static CardSingleton* getInstance();
    int getDaId() const;
    void setDaId(int value);
    int getCaId() const;
    void setCaId(int value);
    int getCardId() const;
    void setCardId(int value);
    int getCaLimit() const;
    void setCaLimit(int value);
    double getCaBalance() const;
    void setCaBalance(double value);
    double getDaBalance() const;
    void setDaBalance(double value);
    QString getOwner() const;
    void setOwner(const QString &value);
    bool getIsCreditSelected() const;
    void setIsCreditSelected(bool value);
    QString makeWithdrawal(int amount);
    QJsonArray getTransactions() const;
    void setTransactions(const QJsonArray &value);
};

#endif // CARDSINGLETON_H
