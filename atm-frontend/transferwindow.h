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

public slots:
    void onKeyPressed(const QString &text);

private slots:
    void on_pushButtonExit_clicked();

    void on_pushButtonOk_clicked();

    void on_pushButtonEnter_clicked();

private:
    Ui::TransferWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
    HttpLibrary *hl = new HttpLibrary;
    bool accountIdInputed = false;
};

#endif // TRANSFERWINDOW_H
