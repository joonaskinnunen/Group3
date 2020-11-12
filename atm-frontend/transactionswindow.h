#ifndef TRANSACTIONSWINDOW_H
#define TRANSACTIONSWINDOW_H

#include <QWidget>
#include "cardsingleton.h"

namespace Ui {
class TransactionsWindow;
}

class TransactionsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TransactionsWindow(QJsonArray arr, QWidget *parent = nullptr);
    ~TransactionsWindow();

private slots:
    void on_pushButtonExit_clicked();

private:
    Ui::TransactionsWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // TRANSACTIONSWINDOW_H
