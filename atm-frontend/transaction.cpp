#include "transaction.h"
#include "ui_transaction.h"
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <qjsondocument.h>

Transaction::Transaction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Transaction)
{
    ui->setupUi(this);
}

Transaction::~Transaction()
{
    delete ui;
}

void Transaction::on_btnShowDebitBalance_clicked()
{
    QString id = ui->lineEditDebitId->text();
    QNetworkRequest request(QUrl("http://192.168.64.2/ci_restapi/index.php/api/debit/debit/id/"+id));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        //Authenticate
        QString username="atm_user";
        QString password="atm_pass";
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

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject jsobj = json_doc.object();
        QJsonArray jsarr = json_doc.array();

        QString debit;
        foreach (const QJsonValue &value, jsarr) {
          QJsonObject jsob = value.toObject();
          debit+=jsob["balance"].toString()+" €"+"\r";
          ui->txtBalance->setText(debit);
        }

        reply->deleteLater();
}

void Transaction::on_btnClose_clicked()
{
    this->close();
}
