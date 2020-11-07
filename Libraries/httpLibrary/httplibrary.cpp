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

QJsonObject HttpLibrary::checkCard(QString loginCardId)
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
    QJsonArray jsarr = json_doc.array();

    QJsonObject jsob;
    foreach (const QJsonValue &value, jsarr) {
        QJsonObject jsob = value.toObject();
        if(jsob["card_id"].toString() == loginCardId){
            return jsob;
        }
    }
    return jsob;

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

bool HttpLibrary::postTransaction(int acc_id, int amount)
{
    QNetworkRequest request(QUrl(url + "transaction/transaction/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", this->authenticate().toLocal8Bit() );

    QJsonObject json;
    json.insert("acc_id",acc_id);
    json.insert("amount",amount);

    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
    while (!reply->isFinished()) { qApp->processEvents(); }

    QByteArray response_data = reply->readAll();

    // Debuggausta
    qDebug()<<response_data;

    return true;
}

bool HttpLibrary::creditUpdate(int acc_id, double balance, int limit)
{
    QNetworkRequest request(QUrl(url + "credit/credit/id/" + QString::number(acc_id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", this->authenticate().toLocal8Bit() );

    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.get(request);
    while (!reply->isFinished()) { qApp->processEvents(); }

    QByteArray response_data = reply->readAll();

    QJsonObject json;
    json.insert("c_balance",balance);
    json.insert("c_limit", limit);

    reply = nam.put(request, QJsonDocument(json).toJson());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    qDebug()<< "\n creditUpdate response data: " + response_data;

    // Debuggausta
    qDebug()<<response_data;

    reply->deleteLater();

    return true;
}

bool HttpLibrary::debitUpdate(int acc_id, double balance)
{
    // Debuggausta
    qDebug()<<"\n"<<"Debit account id:  " + QString::number(acc_id);

    QNetworkRequest request(QUrl(url + "debit/debit/id/"+ QString::number(acc_id)));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", this->authenticate().toLocal8Bit() );

    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.get(request);
    while (!reply->isFinished()) { qApp->processEvents(); }

    QByteArray response_data = reply->readAll();

    QJsonObject json;
    json.insert("d_balance",balance);

    reply = nam.put(request, QJsonDocument(json).toJson());
    while (!reply->isFinished())
    {
        qApp->processEvents();
    }
    response_data = reply->readAll();

    // Debuggausta
    qDebug()<< "\n debitUpdate response data: " + response_data;

    reply->deleteLater();

    return true;
}

QJsonObject HttpLibrary::getTransactions(QString acc_id)
{
    QNetworkRequest request(QUrl(url + "transaction/transaction/id/"+ acc_id));
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
    qDebug()<< "\n getTransactions response data: " + response_data + "\n";

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray jsarr = json_doc.array();
    QJsonArray filteredJsarr;

    QJsonObject jsob;
    foreach (const QJsonValue &value, jsarr) {
        QJsonObject jsob = value.toObject();
        if(jsob["acc_id"].toString() == acc_id){
            filteredJsarr.append(jsob);
        }
    }
    return jsob;

    reply->deleteLater();
}

bool HttpLibrary::updateCard(QJsonObject card)
{
    QNetworkRequest request(QUrl(url + "card/card/id/" + card["card_id"].toInt()));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader( "Authorization", this->authenticate().toLocal8Bit() );

    QNetworkAccessManager nam;
    QNetworkReply *reply = nam.put(request, QJsonDocument(card).toJson());
    while (!reply->isFinished()) { qApp->processEvents(); }

    return true;
}

HttpLibrary::HttpLibrary()
{
}
