/********************************************************************************
** Form generated from reading UI file 'actionchoicewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIONCHOICEWINDOW_H
#define UI_ACTIONCHOICEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ActionChoiceWindow
{
public:
    QPushButton *pushButtonBalance;
    QPushButton *pushButtonTransactions;
    QPushButton *pushButtonWithdrawal;
    QPushButton *pushButtonDeposit;
    QPushButton *pushButtonTransfer;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButtonExit;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *ActionChoiceWindow)
    {
        if (ActionChoiceWindow->objectName().isEmpty())
            ActionChoiceWindow->setObjectName(QString::fromUtf8("ActionChoiceWindow"));
        ActionChoiceWindow->resize(700, 700);
        ActionChoiceWindow->setMinimumSize(QSize(700, 700));
        ActionChoiceWindow->setStyleSheet(QString::fromUtf8("#ActionChoiceWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}"));
        pushButtonBalance = new QPushButton(ActionChoiceWindow);
        pushButtonBalance->setObjectName(QString::fromUtf8("pushButtonBalance"));
        pushButtonBalance->setGeometry(QRect(114, 358, 39, 33));
        pushButtonBalance->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        pushButtonTransactions = new QPushButton(ActionChoiceWindow);
        pushButtonTransactions->setObjectName(QString::fromUtf8("pushButtonTransactions"));
        pushButtonTransactions->setGeometry(QRect(548, 276, 39, 33));
        pushButtonTransactions->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        pushButtonWithdrawal = new QPushButton(ActionChoiceWindow);
        pushButtonWithdrawal->setObjectName(QString::fromUtf8("pushButtonWithdrawal"));
        pushButtonWithdrawal->setGeometry(QRect(114, 234, 39, 33));
        pushButtonWithdrawal->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        pushButtonDeposit = new QPushButton(ActionChoiceWindow);
        pushButtonDeposit->setObjectName(QString::fromUtf8("pushButtonDeposit"));
        pushButtonDeposit->setGeometry(QRect(114, 276, 39, 33));
        pushButtonDeposit->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        pushButtonTransfer = new QPushButton(ActionChoiceWindow);
        pushButtonTransfer->setObjectName(QString::fromUtf8("pushButtonTransfer"));
        pushButtonTransfer->setGeometry(QRect(548, 236, 39, 33));
        pushButtonTransfer->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        label_3 = new QLabel(ActionChoiceWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(168, 132, 361, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label = new QLabel(ActionChoiceWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(184, 242, 71, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label->setFont(font1);
        label_2 = new QLabel(ActionChoiceWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(184, 282, 101, 21));
        label_2->setFont(font1);
        label_4 = new QLabel(ActionChoiceWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(184, 364, 71, 21));
        label_4->setFont(font1);
        label_5 = new QLabel(ActionChoiceWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(414, 242, 101, 21));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(ActionChoiceWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(374, 282, 141, 21));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_7 = new QLabel(ActionChoiceWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(432, 364, 81, 21));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonExit = new QPushButton(ActionChoiceWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(548, 360, 39, 33));
        pushButtonExit->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        label_hole_shadow = new QLabel(ActionChoiceWindow);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(ActionChoiceWindow);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(ActionChoiceWindow);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));

        retranslateUi(ActionChoiceWindow);

        QMetaObject::connectSlotsByName(ActionChoiceWindow);
    } // setupUi

    void retranslateUi(QWidget *ActionChoiceWindow)
    {
        ActionChoiceWindow->setWindowTitle(QCoreApplication::translate("ActionChoiceWindow", "Form", nullptr));
        pushButtonBalance->setText(QString());
        pushButtonTransactions->setText(QString());
        pushButtonWithdrawal->setText(QString());
        pushButtonDeposit->setText(QString());
        pushButtonTransfer->setText(QString());
        label_3->setText(QCoreApplication::translate("ActionChoiceWindow", "VALITSE TOIMINTO", nullptr));
        label->setText(QCoreApplication::translate("ActionChoiceWindow", "NOSTO", nullptr));
        label_2->setText(QCoreApplication::translate("ActionChoiceWindow", "TALLETUS", nullptr));
        label_4->setText(QCoreApplication::translate("ActionChoiceWindow", "SALDO", nullptr));
        label_5->setText(QCoreApplication::translate("ActionChoiceWindow", "TILISIIRTO", nullptr));
        label_6->setText(QCoreApplication::translate("ActionChoiceWindow", "TAPAHTUMAT", nullptr));
        label_7->setText(QCoreApplication::translate("ActionChoiceWindow", "LOPETA", nullptr));
        pushButtonExit->setText(QString());
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ActionChoiceWindow: public Ui_ActionChoiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONCHOICEWINDOW_H
