#ifndef EXITWINDOW_H
#define EXITWINDOW_H

#include <QWidget>

namespace Ui {
class ExitWindow;
}

class ExitWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ExitWindow(QWidget *parent = nullptr);
    ~ExitWindow();

private:
    Ui::ExitWindow *ui;
};

#endif // EXITWINDOW_H
