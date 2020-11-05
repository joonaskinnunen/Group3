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
    explicit ExitWindow(QString message, QWidget *parent = nullptr);
    ~ExitWindow();

private slots:
    void on_pushButtonExit_clicked();

private:
    Ui::ExitWindow *ui;
};

#endif // EXITWINDOW_H
