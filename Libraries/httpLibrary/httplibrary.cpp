#include "httplibrary.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>
#include <QDebug>

QString HttpLibrary::authenticate()
{
    //Authenticate
    QString headerData;
    QString username="atm_user";
    QString password="atm_pass";
    QString concatenatedCredentials = username + ":" + password;
       QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
       return headerData = "Basic " + data;
}

bool HttpLibrary::checkPin(QString loginCardId, QString loginPin)
{
    QNetworkRequest request(QUrl(url + "login/check_login/?card_id="+loginCardId+"&pin="+loginPin));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader( "Authorization", authenticate().toLocal8Bit() );

        //Debuggausta
        qDebug()<<"request URL: "+ url + "login/check_login/?card_id="+loginCardId+"&pin="+loginPin;

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();

        //Debuggausta
        qDebug()<<"DATATA:"+response_data;

        reply->deleteLater();

        if(response_data.compare("true")==0){
            return true;
        }
        else {
            return false;
        }
}

bool HttpLibrary::checkCard(QString loginCardId)
{
    QNetworkRequest request(QUrl(url + "card/card"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader( "Authorization", authenticate().toLocal8Bit() );

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();

        // Debuggausta
        qDebug()<<response_data;

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject jsobj = json_doc.object();
        QJsonArray jsarr = json_doc.array();

        QString cardId;
        foreach (const QJsonValue &value, jsarr) {
          QJsonObject jsob = value.toObject();
          if(jsob["card_id"].toString() == loginCardId){
              return true;
          }
        }
        return false;

        reply->deleteLater();
}

bool HttpLibrary::debitTransaction(QString amount, QString da_id)
{
    int newBalance, balance;

    QNetworkRequest request(QUrl(url + "debit/debit/id/"+da_id));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader( "Authorization", this->authenticate().toLocal8Bit() );

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while (!reply->isFinished()) { qApp->processEvents(); }

        QByteArray response_data = reply->readAll();

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject jsobj = json_doc.object();
        QJsonArray jsarr = json_doc.array();

        foreach (const QJsonValue &value, jsarr) {
          jsobj = value.toObject();
          }
        balance = jsobj["d_balance"].toInt();

        if(amount.toInt() > balance) { return false; }

        newBalance = balance - amount.toInt();

        QJsonObject json;
        json.insert("d_balance",newBalance);

        reply = nam.put(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        response_data = reply->readAll();

        // Debuggausta
        qDebug()<<response_data;

        reply->deleteLater();

        return true;

}

bool HttpLibrary::creditTransaction(QString amount, QString ca_id)
{
    int newBalance, balance, limit;

    QNetworkRequest request(QUrl(url + "credit/credit/id/"+ca_id));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader( "Authorization", this->authenticate().toLocal8Bit() );

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while (!reply->isFinished()) { qApp->processEvents(); }

        QByteArray response_data = reply->readAll();

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject jsobj = json_doc.object();
        QJsonArray jsarr = json_doc.array();

        foreach (const QJsonValue &value, jsarr) {
          jsobj = value.toObject();
          }
        balance = jsobj["c_balance"].toInt();
        limit = jsobj["c_limit"].toInt();

        if(balance - amount.toInt() < 0 - limit) { return false; }

        newBalance = balance - amount.toInt();

        QJsonObject json;
        json.insert("c_balance",newBalance);

        reply = nam.put(request, QJsonDocument(json).toJson());
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        response_data = reply->readAll();

        // Debuggausta
        qDebug()<<response_data;

        reply->deleteLater();

        return true;
}

HttpLibrary::HttpLibrary()
{
}
