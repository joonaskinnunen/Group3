#ifndef HTTPLIBRARY_H
#define HTTPLIBRARY_H

#include "httpLibrary_global.h"

#include <QString>

class HTTPLIBRARY_EXPORT HttpLibrary
{
private:
    QString url = "https://www.students.oamk.fi/~t9tees00/ohjelmistoprojekti/Group3/atm-backend/index.php/api/";
    QString authenticate();
public:
    bool checkPin(QString loginCardId, QString loginPin);
    bool checkCard(QString loginCardId);
    bool debitTransaction(QString amount, QString da_id);
    bool creditTransaction(QString amount, QString ca_id);
    HttpLibrary();
};

#endif // HTTPLIBRARY_H
