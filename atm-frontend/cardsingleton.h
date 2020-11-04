#ifndef CARDSINGLETON_H
#define CARDSINGLETON_H

#include <qstring.h>

class CardSingleton
{
private:
    static CardSingleton* instance;
    int daId, caId, cardId, caLimit;
    float caBalance, daBalance;
    QString owner;


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
    float getCaBalance() const;
    void setCaBalance(float value);
    float getDaBalance() const;
    void setDaBalance(float value);
    QString getOwner() const;
    void setOwner(const QString &value);
};

#endif // CARDSINGLETON_H
