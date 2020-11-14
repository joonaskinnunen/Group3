#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

#include "cardsingleton.h"
#include "httplibrary.h"

#include <QWidget>

namespace Ui {
class TransferWindow;
}

class TransferWindow : public QWidget
{
    Q_OBJECT

public:
    explicit TransferWindow(QWidget *parent = nullptr);
    ~TransferWindow();

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonOk_clicked();

private:
    Ui::TransferWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
    HttpLibrary *hl = new HttpLibrary;
};

#endif // TRANSFERWINDOW_H
