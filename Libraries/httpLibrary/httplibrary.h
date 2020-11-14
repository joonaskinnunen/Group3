#ifndef HTTPLIBRARY_H
#define HTTPLIBRARY_H

#include "httpLibrary_global.h"

#include <QJsonObject>
#include <QString>

class HTTPLIBRARY_EXPORT HttpLibrary
{
private:
    QString url = "https://www.students.oamk.fi/~t9tees00/ohjelmistoprojekti/Group3/atm-backend/index.php/api/";
    QString authenticate();
public:
    bool checkPin(QString loginCardId, QString loginPin);
    QJsonObject checkCard(QString loginCardId);
    bool postTransaction(int acc_id, int balance);
    bool updateCard(QJsonObject card);
    HttpLibrary();
    bool creditUpdate(int acc_id, double balance, int limit);
    bool debitUpdate(int acc_id, double balance);
    QJsonArray getTransactions(int acc_id);
    QJsonArray getCreditAccounts();
    QJsonArray getDebitAccounts();
    bool makeBankTransfer(int acc_1, int acc_2, double balance_1, double balance_2);
    bool checkAccount(int acc_id);
    bool updateAccount(int acc_id, double balance);

};

#endif // HTTPLIBRARY_H
