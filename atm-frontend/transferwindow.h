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

    void on_pushButtonOne_clicked();

    void on_pushButtonTwo_clicked();

    void on_pushButtonThree_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonFour_clicked();

    void on_pushButtonFive_clicked();

    void on_pushButtonSix_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonSeven_clicked();

    void on_pushButtonEight_clicked();

    void on_pushButtonNine_clicked();

    void on_pushButtonEnter_clicked();

    void on_pushButtonZero_clicked();

private:
    Ui::TransferWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
    HttpLibrary *hl = new HttpLibrary;
    bool accountIdInputed = false;
};

#endif // TRANSFERWINDOW_H
