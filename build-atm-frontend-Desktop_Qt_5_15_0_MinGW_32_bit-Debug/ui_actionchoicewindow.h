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

    void setupUi(QWidget *ActionChoiceWindow)
    {
        if (ActionChoiceWindow->objectName().isEmpty())
            ActionChoiceWindow->setObjectName(QString::fromUtf8("ActionChoiceWindow"));
        ActionChoiceWindow->resize(600, 500);
        pushButtonBalance = new QPushButton(ActionChoiceWindow);
        pushButtonBalance->setObjectName(QString::fromUtf8("pushButtonBalance"));
        pushButtonBalance->setGeometry(QRect(220, 260, 130, 50));
        pushButtonTransactions = new QPushButton(ActionChoiceWindow);
        pushButtonTransactions->setObjectName(QString::fromUtf8("pushButtonTransactions"));
        pushButtonTransactions->setGeometry(QRect(220, 330, 130, 50));
        pushButtonWithdrawal = new QPushButton(ActionChoiceWindow);
        pushButtonWithdrawal->setObjectName(QString::fromUtf8("pushButtonWithdrawal"));
        pushButtonWithdrawal->setGeometry(QRect(220, 50, 130, 50));
        pushButtonDeposit = new QPushButton(ActionChoiceWindow);
        pushButtonDeposit->setObjectName(QString::fromUtf8("pushButtonDeposit"));
        pushButtonDeposit->setGeometry(QRect(220, 120, 130, 50));
        pushButtonTransfer = new QPushButton(ActionChoiceWindow);
        pushButtonTransfer->setObjectName(QString::fromUtf8("pushButtonTransfer"));
        pushButtonTransfer->setGeometry(QRect(220, 190, 130, 50));

        retranslateUi(ActionChoiceWindow);

        QMetaObject::connectSlotsByName(ActionChoiceWindow);
    } // setupUi

    void retranslateUi(QWidget *ActionChoiceWindow)
    {
        ActionChoiceWindow->setWindowTitle(QCoreApplication::translate("ActionChoiceWindow", "Form", nullptr));
        pushButtonBalance->setText(QCoreApplication::translate("ActionChoiceWindow", "SALDO", nullptr));
        pushButtonTransactions->setText(QCoreApplication::translate("ActionChoiceWindow", "TILITAPAHTUMAT", nullptr));
        pushButtonWithdrawal->setText(QCoreApplication::translate("ActionChoiceWindow", "NOSTO", nullptr));
        pushButtonDeposit->setText(QCoreApplication::translate("ActionChoiceWindow", "TALLETUS", nullptr));
        pushButtonTransfer->setText(QCoreApplication::translate("ActionChoiceWindow", "TILISIIRTO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActionChoiceWindow: public Ui_ActionChoiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIONCHOICEWINDOW_H
