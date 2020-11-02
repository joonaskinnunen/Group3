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

    void setupUi(QWidget *BalanceWindow)
    {
        if (BalanceWindow->objectName().isEmpty())
            BalanceWindow->setObjectName(QString::fromUtf8("BalanceWindow"));
        BalanceWindow->resize(600, 500);
        labelBalance = new QLabel(BalanceWindow);
        labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
        labelBalance->setGeometry(QRect(0, 0, 601, 211));
        QFont font;
        font.setPointSize(23);
        labelBalance->setFont(font);
        labelBalance->setAlignment(Qt::AlignCenter);
        pushButtonExit = new QPushButton(BalanceWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(230, 360, 121, 41));

        retranslateUi(BalanceWindow);

        QMetaObject::connectSlotsByName(BalanceWindow);
    } // setupUi

    void retranslateUi(QWidget *BalanceWindow)
    {
        BalanceWindow->setWindowTitle(QCoreApplication::translate("BalanceWindow", "Form", nullptr));
        labelBalance->setText(QCoreApplication::translate("BalanceWindow", "Tilin saldo:", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("BalanceWindow", "LOPETA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BalanceWindow: public Ui_BalanceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCEWINDOW_H
