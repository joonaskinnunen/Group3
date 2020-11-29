#ifndef DEPOSITWINDOW_H
#define DEPOSITWINDOW_H

#include <QWidget>

namespace Ui {
class DepositWindow;
}

class DepositWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DepositWindow(QWidget *parent = nullptr);
    ~DepositWindow();

private slots:
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

    void on_pushButtonExit_clicked();

private:
    Ui::DepositWindow *ui;
};

#endif // DEPOSITWINDOW_H
