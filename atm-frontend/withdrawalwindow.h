#ifndef WITHDRAWALWINDOW_H
#define WITHDRAWALWINDOW_H

#include <QWidget>

namespace Ui {
class WithdrawalWindow;
}

class WithdrawalWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WithdrawalWindow(QWidget *parent = nullptr);
    ~WithdrawalWindow();

private:
    Ui::WithdrawalWindow *ui;
};

#endif // WITHDRAWALWINDOW_H
