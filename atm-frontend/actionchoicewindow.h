#ifndef ACTIONCHOICEWINDOW_H
#define ACTIONCHOICEWINDOW_H

#include "cardsingleton.h"

#include <QWidget>

namespace Ui {
class ActionChoiceWindow;
}

class ActionChoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ActionChoiceWindow(QWidget *parent = nullptr);
    ~ActionChoiceWindow();

private slots:
    void on_pushButtonWithdrawal_clicked();
    void on_pushButtonBalance_clicked();
    void on_pushButtonTransactions_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonTransfer_clicked();

private:
    Ui::ActionChoiceWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();

};

#endif // ACTIONCHOICEWINDOW_H
