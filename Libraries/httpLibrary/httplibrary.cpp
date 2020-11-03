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
    QString username="ci_user";
    QString password="ci_pass";
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
