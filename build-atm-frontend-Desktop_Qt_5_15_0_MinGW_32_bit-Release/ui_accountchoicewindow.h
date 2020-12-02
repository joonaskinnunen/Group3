/********************************************************************************
** Form generated from reading UI file 'accountchoicewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTCHOICEWINDOW_H
#define UI_ACCOUNTCHOICEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountChoiceWindow
{
public:
    QPushButton *pushButtonDebit;
    QPushButton *pushButtonCredit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *AccountChoiceWindow)
    {
        if (AccountChoiceWindow->objectName().isEmpty())
            AccountChoiceWindow->setObjectName(QString::fromUtf8("AccountChoiceWindow"));
        AccountChoiceWindow->resize(700, 700);
        AccountChoiceWindow->setMinimumSize(QSize(700, 700));
        AccountChoiceWindow->setStyleSheet(QString::fromUtf8("#AccountChoiceWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}"));
        pushButtonDebit = new QPushButton(AccountChoiceWindow);
        pushButtonDebit->setObjectName(QString::fromUtf8("pushButtonDebit"));
        pushButtonDebit->setGeometry(QRect(113, 235, 40, 37));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        pushButtonDebit->setFont(font);
        pushButtonDebit->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        pushButtonCredit = new QPushButton(AccountChoiceWindow);
        pushButtonCredit->setObjectName(QString::fromUtf8("pushButtonCredit"));
        pushButtonCredit->setGeometry(QRect(113, 280, 40, 33));
        pushButtonCredit->setFont(font);
        pushButtonCredit->setStyleSheet(QString::fromUtf8("border: none;"));
        label = new QLabel(AccountChoiceWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(188, 246, 61, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label_2 = new QLabel(AccountChoiceWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(188, 280, 81, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(AccountChoiceWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 134, 357, 21));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        label_hole_shadow = new QLabel(AccountChoiceWindow);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(AccountChoiceWindow);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(AccountChoiceWindow);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));

        retranslateUi(AccountChoiceWindow);

        QMetaObject::connectSlotsByName(AccountChoiceWindow);
    } // setupUi

    void retranslateUi(QWidget *AccountChoiceWindow)
    {
        AccountChoiceWindow->setWindowTitle(QCoreApplication::translate("AccountChoiceWindow", "Form", nullptr));
        pushButtonDebit->setText(QString());
        pushButtonCredit->setText(QString());
        label->setText(QCoreApplication::translate("AccountChoiceWindow", "DEBIT", nullptr));
        label_2->setText(QCoreApplication::translate("AccountChoiceWindow", "CREDIT", nullptr));
        label_3->setText(QCoreApplication::translate("AccountChoiceWindow", "VALITSE TILI", nullptr));
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AccountChoiceWindow: public Ui_AccountChoiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTCHOICEWINDOW_H
