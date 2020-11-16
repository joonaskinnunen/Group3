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
    qDebug() << "\n getCards response data: \n "  << response_data;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray jsarr = json_doc.array();

    QJsonObject jsob;
    foreach (const QJsonValue &value, jsarr) {
        QJsonObject jsob = value.toObject();
        if(jsob["card_id"].toString() == loginCardId){
            return jsob;
        }
    }
    QJsonDocument doc(jsob);
    qDebug() << "\n Login cardId: \n" << loginCardId << "\n JSobject card: \n" << QString (doc.toJson(QJsonDocument::Compact)) << "\n";
    return jsob;

    reply->deleteLater();
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
    json.insert("d_balance", balance);

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

QJsonArray HttpLibrary::getTransactions(int acc_id)

{
    QNetworkRequest request(QUrl(url + "transaction/transaction"));
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
    //qDebug()<< "\n getTransactions response data: " + response_data + "\n";
    qDebug() << "\n account id: " << acc_id;

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray jsarr = json_doc.array();
    QJsonArray filteredJsarr;

    QJsonObject jsob;
    foreach (const QJsonValue &value, jsarr) {
        jsob = value.toObject();
        if(jsob["acc_id"].toString() == QString::number(acc_id)){
            filteredJsarr.prepend(jsob);
        }
    }

    QJsonDocument doc;
    doc.setArray(filteredJsarr);
    qDebug() << QString (doc.toJson(QJsonDocument::Compact));

    return filteredJsarr;

    reply->deleteLater();
}

QJsonArray HttpLibrary::getCreditAccounts()
{
    QNetworkRequest request(QUrl(url + "credit/credit"));
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
    //qDebug()<< "\n getTransactions response data: " + response_data + "\n";

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray jsarr = json_doc.array();
    QJsonArray filteredJsarr;
    QJsonDocument doc;

    qDebug() << "\n credit accounts doc: " << QString (json_doc.toJson(QJsonDocument::Compact)) << "\n";

    return jsarr;

    reply->deleteLater();

}

QJsonArray HttpLibrary::getDebitAccounts()
{
    QNetworkRequest request(QUrl(url + "debit/debit"));
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
    //qDebug()<< "\n getTransactions response data: " + response_data + "\n";

    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray jsarr = json_doc.array();
    QJsonArray filteredJsarr;
    QJsonDocument doc;

    qDebug() << "\n debit accounts doc: " << QString (json_doc.toJson(QJsonDocument::Compact)) << "\n";

    return jsarr;

    reply->deleteLater();

}

bool HttpLibrary::makeBankTransfer(int acc_1, int acc_2, double amount)
{
    // acc_1 is the sender and acc_2 receiver
    // update accounts
    QJsonArray debitAccounts = this->getDebitAccounts();
    QJsonArray creditAccounts = this->getCreditAccounts();
    QJsonObject jsob;

    qDebug() << "debitAccounts before transfer: " << debitAccounts;
    qDebug() << "creditAccounts before transfer: " << creditAccounts;

    foreach (const QJsonValue &value, debitAccounts) {
        jsob = value.toObject();
        if(jsob["da_id"].toString() == QString::number(acc_1)) updateAccount(acc_1, jsob["d_balance"].toString().toDouble() - amount);
        if(jsob["da_id"].toString() == QString::number(acc_2)) updateAccount(acc_2, jsob["d_balance"].toString().toDouble() + amount);
    }

    foreach (const QJsonValue &value, creditAccounts) {
        jsob = value.toObject();
        if(jsob["ca_id"].toString() == QString::number(acc_1)) updateAccount(acc_1, jsob["c_balance"].toString().toDouble() - amount);
        if(jsob["ca_id"].toString() == QString::number(acc_2)) updateAccount(acc_2, jsob["c_balance"].toString().toDouble() + amount);
    }
    qDebug() << "debitAccounts after transfer: " << debitAccounts;
    qDebug() << "creditAccounts after transfer: " << creditAccounts;
    return true;
}



bool HttpLibrary::checkAccount(int acc_id)
{
    QJsonArray debitAccounts = this->getDebitAccounts();
    QJsonArray creditAccounts = this->getCreditAccounts();
    QJsonObject jsob;
        foreach (const QJsonValue &value, debitAccounts) {
            jsob = value.toObject();
            if(jsob["da_id"].toString() == QString::number(acc_id)){
                return true;
            }
        }
        foreach (const QJsonValue &value, creditAccounts) {
            jsob = value.toObject();
            qDebug() << "jsob[id]: " << jsob;
            if(jsob["ca_id"].toString() == QString::number(acc_id)){
                return true;
            }
        }
    return false;
}

bool HttpLibrary::updateAccount(int acc_id, double balance)
{
    QJsonArray arr = this->getCreditAccounts();
    QJsonObject jsob;
    foreach (const QJsonValue &value, arr) {
        jsob = value.toObject();
        if(jsob["ca_id"].toString() == QString::number(acc_id)){
            return this->creditUpdate(acc_id, balance, jsob["c_limit"].toInt());
        }
    }
    return this->debitUpdate(acc_id, balance);
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
