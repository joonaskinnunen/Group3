#ifndef ACCOUNTCHOICEWINDOW_H
#define ACCOUNTCHOICEWINDOW_H

#include <QWidget>

namespace Ui {
class AccountChoiceWindow;
}

class AccountChoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AccountChoiceWindow(QWidget *parent = nullptr);
    ~AccountChoiceWindow();

private:
    Ui::AccountChoiceWindow *ui;
};

#endif // ACCOUNTCHOICEWINDOW_H
