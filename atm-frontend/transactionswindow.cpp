#include "transactionswindow.h"
#include "ui_transactionswindow.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QStandardItemModel>

TransactionsWindow::TransactionsWindow(QJsonArray arr, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TransactionsWindow)
{
    ui->setupUi(this);

    QStandardItemModel *table_model = new QStandardItemModel(arr.size(),5);
    table_model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    table_model->setHeaderData(1, Qt::Horizontal, QObject::tr("Tili"));
    table_model->setHeaderData(2, Qt::Horizontal, QObject::tr("Summa"));
    table_model->setHeaderData(3, Qt::Horizontal, QObject::tr("Aika"));
    table_model->setHeaderData(4, Qt::Horizontal, QObject::tr("Tyyppi"));

    QJsonObject jsob;
    int row = arr.size() - 1;
    foreach(const QJsonValue &value, arr) {
        jsob = value.toObject();
        QStandardItem *id = new QStandardItem(jsob["tr_id"].toString());
        table_model->setItem(row, 0, id);
        QStandardItem *acc = new QStandardItem(jsob["acc_id"].toString());
        table_model->setItem(row, 1, acc);
        QStandardItem *amount = new QStandardItem(jsob["amount"].toString());
        table_model->setItem(row, 2, amount);
        QDateTime timestamp;
        timestamp.setTime_t(jsob["time"].toString().toInt());
        qDebug() << "\n jsob time: " << jsob["time"].toString().toInt() << "\n";
        QStandardItem *time = new QStandardItem(timestamp.toString(Qt::SystemLocaleShortDate));
        table_model->setItem(row, 3, time);
        QStandardItem *type = new QStandardItem(jsob["action"].toString());
        table_model->setItem(row, 4, type);
        row -= 1;
    }

    QString labelText;
    if(cs->getIsCreditSelected()){
        labelText = QString::number(cs->getCaId());
    } else {
        labelText = QString::number(cs->getDaId());
    }
    ui->labelCardId->setText("Tili: " + labelText);

    ui->tableViewTransactions->setModel(table_model);

    QPixmap pmbg(":/atm-frontend/bg.png");
    pmbg = pmbg.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, pmbg);
    this->setPalette(palette);
}

TransactionsWindow::~TransactionsWindow()
{
    delete ui;
    ui=nullptr;
}

void TransactionsWindow::on_pushButtonExit_clicked()
{
    this->close();
}
