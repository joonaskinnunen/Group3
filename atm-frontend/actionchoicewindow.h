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

private:
    Ui::ActionChoiceWindow *ui;
};

#endif // ACTIONCHOICEWINDOW_H
