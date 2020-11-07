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
    bool debitTransaction(QString amount, QString da_id);
    bool creditTransaction(QString amount, QString ca_id);
    bool postTransaction(int acc_id, int balance);
    bool updateCard(QJsonObject card);
    HttpLibrary();
    bool creditUpdate(int acc_id, double balance, int limit);
    bool debitUpdate(int acc_id, double balance);
};

#endif // HTTPLIBRARY_H
