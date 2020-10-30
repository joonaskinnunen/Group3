#ifndef BALANCEWINDOW_H
#define BALANCEWINDOW_H

#include <QWidget>

namespace Ui {
class BalanceWindow;
}

class BalanceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BalanceWindow(QWidget *parent = nullptr);
    ~BalanceWindow();

private:
    Ui::BalanceWindow *ui;
};

#endif // BALANCEWINDOW_H
