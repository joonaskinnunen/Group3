#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cardsingleton.h"
#include "note.h"

#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonLogin_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonOne_clicked();

    void on_pushButtonTwo_clicked();

    void on_pushButtonThree_clicked();

    void on_pushButtonZero_clicked();

    void on_pushButtonFour_clicked();

    void on_pushButtonFive_clicked();

    void on_pushButtonSix_clicked();

    void on_pushButtonSeven_clicked();

    void on_pushButtonEight_clicked();

    void on_pushButtonNine_clicked();

    void on_pushButtonCancel_clicked();

    void on_pushButtonClear_clicked();

    void on_pushButtonEnter_clicked();

private:
    Ui::MainWindow *ui;
    CardSingleton *cs = CardSingleton::getInstance();
    QSequentialAnimationGroup *group;
    QList<int> getNotes(int amount);
};
#endif // MAINWINDOW_H
