#include "httplibrary.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

bool HttpLibrary::checkPin(QString loginCardId, QString loginPin)
{
    QNetworkRequest request(QUrl(url + "login/check_login/?card_id="+loginCardId+"&pin="+loginPin));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="ci_user";
        QString password="ci_pass";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();

        qDebug()<<"DATA:"+response_data;

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
        //Authenticate
        QString username="ci_user";
        QString password="ci_pass";
        QString concatenatedCredentials = username + ":" + password;
           QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );

        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while (!reply->isFinished())
        {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();
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

HttpLibrary::HttpLibrary()
{
}
