#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <QWidget>

namespace Ui {
class Transaction;
}

class Transaction : public QWidget
{
    Q_OBJECT

public:
    explicit Transaction(QWidget *parent = nullptr);
    ~Transaction();

private slots:
    void on_btnShowDebitBalance_clicked();

    void on_btnClose_clicked();

private:
    Ui::Transaction *ui;
};

#endif // TRANSACTION_H
