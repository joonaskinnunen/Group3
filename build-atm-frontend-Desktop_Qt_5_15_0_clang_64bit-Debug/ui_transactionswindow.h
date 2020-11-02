/********************************************************************************
** Form generated from reading UI file 'transactionswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSACTIONSWINDOW_H
#define UI_TRANSACTIONSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransactionsWindow
{
public:
    QLabel *labelTransactionsTitle;
    QPushButton *pushButtonExit;
    QTableView *tableViewTransactions;
    QLabel *labelCardId;

    void setupUi(QWidget *TransactionsWindow)
    {
        if (TransactionsWindow->objectName().isEmpty())
            TransactionsWindow->setObjectName(QString::fromUtf8("TransactionsWindow"));
        TransactionsWindow->resize(600, 500);
        labelTransactionsTitle = new QLabel(TransactionsWindow);
        labelTransactionsTitle->setObjectName(QString::fromUtf8("labelTransactionsTitle"));
        labelTransactionsTitle->setGeometry(QRect(170, 39, 251, 41));
        QFont font;
        font.setPointSize(19);
        font.setBold(true);
        font.setWeight(75);
        labelTransactionsTitle->setFont(font);
        labelTransactionsTitle->setAlignment(Qt::AlignCenter);
        pushButtonExit = new QPushButton(TransactionsWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(240, 390, 101, 41));
        tableViewTransactions = new QTableView(TransactionsWindow);
        tableViewTransactions->setObjectName(QString::fromUtf8("tableViewTransactions"));
        tableViewTransactions->setGeometry(QRect(0, 110, 600, 251));
        tableViewTransactions->horizontalHeader()->setDefaultSectionSize(180);
        labelCardId = new QLabel(TransactionsWindow);
        labelCardId->setObjectName(QString::fromUtf8("labelCardId"));
        labelCardId->setGeometry(QRect(170, 90, 261, 20));
        labelCardId->setAlignment(Qt::AlignCenter);

        retranslateUi(TransactionsWindow);

        QMetaObject::connectSlotsByName(TransactionsWindow);
    } // setupUi

    void retranslateUi(QWidget *TransactionsWindow)
    {
        TransactionsWindow->setWindowTitle(QCoreApplication::translate("TransactionsWindow", "Form", nullptr));
        labelTransactionsTitle->setText(QCoreApplication::translate("TransactionsWindow", "Tilitapahtumat", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("TransactionsWindow", "LOPETA", nullptr));
        labelCardId->setText(QCoreApplication::translate("TransactionsWindow", "Kortti ID:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransactionsWindow: public Ui_TransactionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONSWINDOW_H
