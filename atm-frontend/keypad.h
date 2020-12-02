#ifndef KEYPAD_H
#define KEYPAD_H

#include "cardsingleton.h"

#include <QWidget>
#include <QDebug>

namespace Ui {
class Keypad;
}

class Keypad : public QWidget
{
    Q_OBJECT

public:
    explicit Keypad(QWidget *parent = nullptr);
    ~Keypad();

private slots:
    void on_btn_1_clicked();


    void on_btn_2_clicked();

    void on_btn_3_clicked();

    void on_btn_4_clicked();

    void on_btn_5_clicked();

    void on_btn_6_clicked();

    void on_btn_7_clicked();

    void on_btn_8_clicked();

    void on_btn_9_clicked();

    void on_btn_0_clicked();

    void on_btn_cancel_clicked();

    void on_btn_clear_clicked();

    void on_btn_ok_clicked();

signals:
    void keyPressed(const QString &text);

private:
    Ui::Keypad *ui;
};

#endif // KEYPAD_H
