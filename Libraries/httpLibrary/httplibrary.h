#ifndef HTTPLIBRARY_H
#define HTTPLIBRARY_H

#include "httpLibrary_global.h"

#include <QString>

class HTTPLIBRARY_EXPORT HttpLibrary
{
private:
    QString url = "http://192.168.64.2/ci_restapi/index.php/api/";
    QString authenticate();
public:
    bool checkPin(QString loginCardId, QString loginPin);
    bool checkCard(QString loginCardId);
    HttpLibrary();
};

#endif // HTTPLIBRARY_H
