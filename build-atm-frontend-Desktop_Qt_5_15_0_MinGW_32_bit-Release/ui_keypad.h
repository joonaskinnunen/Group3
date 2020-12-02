/********************************************************************************
** Form generated from reading UI file 'keypad.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYPAD_H
#define UI_KEYPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Keypad
{
public:
    QPushButton *btn_4;
    QPushButton *btn_7;
    QPushButton *btn_3;
    QPushButton *btn_8;
    QPushButton *btn_9;
    QPushButton *btn_2;
    QPushButton *btn_1;
    QPushButton *btn_5;
    QPushButton *btn_6;
    QPushButton *btn_0;
    QPushButton *btn_ok;
    QPushButton *btn_clear;
    QPushButton *btn_cancel;

    void setupUi(QWidget *Keypad)
    {
        if (Keypad->objectName().isEmpty())
            Keypad->setObjectName(QString::fromUtf8("Keypad"));
        Keypad->resize(193, 166);
        btn_4 = new QPushButton(Keypad);
        btn_4->setObjectName(QString::fromUtf8("btn_4"));
        btn_4->setGeometry(QRect(2, 28, 35, 33));
        btn_7 = new QPushButton(Keypad);
        btn_7->setObjectName(QString::fromUtf8("btn_7"));
        btn_7->setGeometry(QRect(2, 56, 35, 33));
        btn_3 = new QPushButton(Keypad);
        btn_3->setObjectName(QString::fromUtf8("btn_3"));
        btn_3->setGeometry(QRect(72, 0, 35, 33));
        btn_8 = new QPushButton(Keypad);
        btn_8->setObjectName(QString::fromUtf8("btn_8"));
        btn_8->setGeometry(QRect(36, 56, 35, 33));
        btn_9 = new QPushButton(Keypad);
        btn_9->setObjectName(QString::fromUtf8("btn_9"));
        btn_9->setGeometry(QRect(72, 56, 35, 33));
        btn_2 = new QPushButton(Keypad);
        btn_2->setObjectName(QString::fromUtf8("btn_2"));
        btn_2->setGeometry(QRect(36, 0, 35, 33));
        btn_1 = new QPushButton(Keypad);
        btn_1->setObjectName(QString::fromUtf8("btn_1"));
        btn_1->setGeometry(QRect(2, 0, 35, 33));
        btn_1->setCheckable(false);
        btn_5 = new QPushButton(Keypad);
        btn_5->setObjectName(QString::fromUtf8("btn_5"));
        btn_5->setGeometry(QRect(36, 28, 35, 33));
        btn_6 = new QPushButton(Keypad);
        btn_6->setObjectName(QString::fromUtf8("btn_6"));
        btn_6->setGeometry(QRect(72, 28, 35, 33));
        btn_0 = new QPushButton(Keypad);
        btn_0->setObjectName(QString::fromUtf8("btn_0"));
        btn_0->setGeometry(QRect(36, 86, 35, 33));
        btn_ok = new QPushButton(Keypad);
        btn_ok->setObjectName(QString::fromUtf8("btn_ok"));
        btn_ok->setGeometry(QRect(120, 56, 38, 33));
        btn_clear = new QPushButton(Keypad);
        btn_clear->setObjectName(QString::fromUtf8("btn_clear"));
        btn_clear->setGeometry(QRect(120, 28, 38, 33));
        btn_cancel = new QPushButton(Keypad);
        btn_cancel->setObjectName(QString::fromUtf8("btn_cancel"));
        btn_cancel->setGeometry(QRect(120, 0, 38, 33));

        retranslateUi(Keypad);

        QMetaObject::connectSlotsByName(Keypad);
    } // setupUi

    void retranslateUi(QWidget *Keypad)
    {
        Keypad->setWindowTitle(QCoreApplication::translate("Keypad", "Form", nullptr));
        btn_4->setText(QString());
        btn_7->setText(QString());
        btn_3->setText(QString());
        btn_8->setText(QString());
        btn_9->setText(QString());
        btn_2->setText(QString());
        btn_1->setText(QString());
        btn_5->setText(QString());
        btn_6->setText(QString());
        btn_0->setText(QString());
        btn_ok->setText(QString());
        btn_clear->setText(QString());
        btn_cancel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Keypad: public Ui_Keypad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYPAD_H
