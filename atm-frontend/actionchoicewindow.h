#ifndef ACTIONCHOICEWINDOW_H
#define ACTIONCHOICEWINDOW_H

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

private:
    Ui::ActionChoiceWindow *ui;
};

#endif // ACTIONCHOICEWINDOW_H
