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

public slots:
    void onKeyPressed(const QString &text);

private slots:
    void on_pushButtonExit_clicked();

private:
    Ui::DepositWindow *ui;
};

#endif // DEPOSITWINDOW_H
