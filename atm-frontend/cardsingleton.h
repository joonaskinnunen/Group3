#ifndef CARDSINGLETON_H
#define CARDSINGLETON_H

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
    HttpLibrary *hl = new HttpLibrary;


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
};

#endif // CARDSINGLETON_H
