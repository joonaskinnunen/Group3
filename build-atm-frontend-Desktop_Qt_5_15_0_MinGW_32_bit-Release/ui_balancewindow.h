/********************************************************************************
** Form generated from reading UI file 'balancewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCEWINDOW_H
#define UI_BALANCEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BalanceWindow
{
public:
    QLabel *labelBalance;
    QPushButton *pushButtonExit;
    QLabel *label_7;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *BalanceWindow)
    {
        if (BalanceWindow->objectName().isEmpty())
            BalanceWindow->setObjectName(QString::fromUtf8("BalanceWindow"));
        BalanceWindow->resize(700, 700);
        BalanceWindow->setMinimumSize(QSize(700, 700));
        BalanceWindow->setStyleSheet(QString::fromUtf8("#BalanceWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}"));
        labelBalance = new QLabel(BalanceWindow);
        labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
        labelBalance->setGeometry(QRect(176, 162, 347, 145));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        labelBalance->setFont(font);
        labelBalance->setAlignment(Qt::AlignCenter);
        pushButtonExit = new QPushButton(BalanceWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(544, 358, 43, 33));
        pushButtonExit->setStyleSheet(QString::fromUtf8("border:none;"));
        label_7 = new QLabel(BalanceWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(434, 364, 81, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_hole_shadow = new QLabel(BalanceWindow);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(BalanceWindow);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(BalanceWindow);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));

        retranslateUi(BalanceWindow);

        QMetaObject::connectSlotsByName(BalanceWindow);
    } // setupUi

    void retranslateUi(QWidget *BalanceWindow)
    {
        BalanceWindow->setWindowTitle(QCoreApplication::translate("BalanceWindow", "Form", nullptr));
        labelBalance->setText(QCoreApplication::translate("BalanceWindow", "Tilin saldo:", nullptr));
        pushButtonExit->setText(QString());
        label_7->setText(QCoreApplication::translate("BalanceWindow", "LOPETA", nullptr));
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BalanceWindow: public Ui_BalanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCEWINDOW_H
