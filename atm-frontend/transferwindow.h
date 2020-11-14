#ifndef TRANSFERWINDOW_H
#define TRANSFERWINDOW_H

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

private:
    Ui::TransferWindow *ui;
};

#endif // TRANSFERWINDOW_H
