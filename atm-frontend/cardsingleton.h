#ifndef CARDSINGLETON_H
#define CARDSINGLETON_H

#include <qstring.h>

class CardSingleton
{
private:
    static CardSingleton* instance;
    int daId, caId, caLimit;
    float caBalance, daBalance;
    QString owner, cardId;
    bool isCreditSelected = false;


public:
    static CardSingleton* getInstance();
    int getDaId() const;
    void setDaId(int value);
    int getCaId() const;
    void setCaId(int value);
    QString getCardId() const;
    void setCardId(QString value);
    int getCaLimit() const;
    void setCaLimit(int value);
    float getCaBalance() const;
    void setCaBalance(float value);
    float getDaBalance() const;
    void setDaBalance(float value);
    QString getOwner() const;
    void setOwner(const QString &value);
    bool getIsCreditSelected() const;
    void setIsCreditSelected(bool value);
    QString makeWithdrawal(int amount);
};

#endif // CARDSINGLETON_H
