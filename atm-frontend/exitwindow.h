#ifndef EXITWINDOW_H
#define EXITWINDOW_H

#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QWidget>

#include "cardsingleton.h"
#include "note.h"

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
    QList<int> getNoteCounts(int amount);
    QSequentialAnimationGroup *group;
    CardSingleton *cs = CardSingleton::getInstance();
};

#endif // EXITWINDOW_H
