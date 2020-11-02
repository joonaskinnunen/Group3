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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AccountChoiceWindow
{
public:
    QPushButton *pushButtonDebit;
    QPushButton *pushButtonCredit;

    void setupUi(QWidget *AccountChoiceWindow)
    {
        if (AccountChoiceWindow->objectName().isEmpty())
            AccountChoiceWindow->setObjectName(QString::fromUtf8("AccountChoiceWindow"));
        AccountChoiceWindow->resize(600, 500);
        pushButtonDebit = new QPushButton(AccountChoiceWindow);
        pushButtonDebit->setObjectName(QString::fromUtf8("pushButtonDebit"));
        pushButtonDebit->setGeometry(QRect(230, 160, 130, 50));
        pushButtonCredit = new QPushButton(AccountChoiceWindow);
        pushButtonCredit->setObjectName(QString::fromUtf8("pushButtonCredit"));
        pushButtonCredit->setGeometry(QRect(230, 240, 130, 50));

        retranslateUi(AccountChoiceWindow);

        QMetaObject::connectSlotsByName(AccountChoiceWindow);
    } // setupUi

    void retranslateUi(QWidget *AccountChoiceWindow)
    {
        AccountChoiceWindow->setWindowTitle(QCoreApplication::translate("AccountChoiceWindow", "Form", nullptr));
        pushButtonDebit->setText(QCoreApplication::translate("AccountChoiceWindow", "DEBIT", nullptr));
        pushButtonCredit->setText(QCoreApplication::translate("AccountChoiceWindow", "CREDIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AccountChoiceWindow: public Ui_AccountChoiceWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTCHOICEWINDOW_H
