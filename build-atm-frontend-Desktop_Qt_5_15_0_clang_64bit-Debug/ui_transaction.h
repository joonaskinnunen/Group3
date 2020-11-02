/********************************************************************************
** Form generated from reading UI file 'transaction.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTION_H
#define UI_TRANSACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Transaction
{
public:
    QLabel *label;
    QLineEdit *lineEditDebitId;
    QLabel *label_2;
    QLabel *txtBalance;
    QPushButton *btnShowDebitBalance;
    QPushButton *btnClose;

    void setupUi(QWidget *Transaction)
    {
        if (Transaction->objectName().isEmpty())
            Transaction->setObjectName(QString::fromUtf8("Transaction"));
        Transaction->resize(662, 316);
        label = new QLabel(Transaction);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 20, 211, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        lineEditDebitId = new QLineEdit(Transaction);
        lineEditDebitId->setObjectName(QString::fromUtf8("lineEditDebitId"));
        lineEditDebitId->setGeometry(QRect(212, 60, 211, 31));
        label_2 = new QLabel(Transaction);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(210, 160, 211, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        txtBalance = new QLabel(Transaction);
        txtBalance->setObjectName(QString::fromUtf8("txtBalance"));
        txtBalance->setGeometry(QRect(210, 210, 211, 31));
        txtBalance->setFont(font);
        txtBalance->setAlignment(Qt::AlignCenter);
        btnShowDebitBalance = new QPushButton(Transaction);
        btnShowDebitBalance->setObjectName(QString::fromUtf8("btnShowDebitBalance"));
        btnShowDebitBalance->setGeometry(QRect(210, 100, 211, 41));
        btnShowDebitBalance->setFont(font);
        btnClose = new QPushButton(Transaction);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(210, 270, 211, 41));
        btnClose->setFont(font);

        retranslateUi(Transaction);

        QMetaObject::connectSlotsByName(Transaction);
    } // setupUi

    void retranslateUi(QWidget *Transaction)
    {
        Transaction->setWindowTitle(QCoreApplication::translate("Transaction", "Form", nullptr));
        label->setText(QCoreApplication::translate("Transaction", "Sy\303\266t\303\244 debit-tilin numero", nullptr));
        label_2->setText(QCoreApplication::translate("Transaction", "Tilin saldo", nullptr));
        txtBalance->setText(QString());
        btnShowDebitBalance->setText(QCoreApplication::translate("Transaction", "N\303\244yt\303\244 saldo", nullptr));
        btnClose->setText(QCoreApplication::translate("Transaction", "Poistu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Transaction: public Ui_Transaction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTION_H
