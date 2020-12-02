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
    QLabel *label_7;

    void setupUi(QWidget *TransactionsWindow)
    {
        if (TransactionsWindow->objectName().isEmpty())
            TransactionsWindow->setObjectName(QString::fromUtf8("TransactionsWindow"));
        TransactionsWindow->resize(700, 700);
        TransactionsWindow->setMinimumSize(QSize(700, 700));
        TransactionsWindow->setStyleSheet(QString::fromUtf8("#TransactionsWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}"));
        labelTransactionsTitle = new QLabel(TransactionsWindow);
        labelTransactionsTitle->setObjectName(QString::fromUtf8("labelTransactionsTitle"));
        labelTransactionsTitle->setGeometry(QRect(204, 128, 293, 25));
        QFont font;
        font.setPointSize(22);
        font.setBold(true);
        font.setWeight(75);
        labelTransactionsTitle->setFont(font);
        labelTransactionsTitle->setAlignment(Qt::AlignCenter);
        pushButtonExit = new QPushButton(TransactionsWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(548, 360, 35, 33));
        pushButtonExit->setStyleSheet(QString::fromUtf8("border: none;"));
        tableViewTransactions = new QTableView(TransactionsWindow);
        tableViewTransactions->setObjectName(QString::fromUtf8("tableViewTransactions"));
        tableViewTransactions->setGeometry(QRect(180, 182, 343, 177));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableViewTransactions->sizePolicy().hasHeightForWidth());
        tableViewTransactions->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        tableViewTransactions->setFont(font1);
        tableViewTransactions->setStyleSheet(QString::fromUtf8("border: none;\n"
"background: transparent;\n"
""));
        tableViewTransactions->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableViewTransactions->setAlternatingRowColors(false);
        tableViewTransactions->horizontalHeader()->setDefaultSectionSize(70);
        tableViewTransactions->verticalHeader()->setVisible(false);
        labelCardId = new QLabel(TransactionsWindow);
        labelCardId->setObjectName(QString::fromUtf8("labelCardId"));
        labelCardId->setGeometry(QRect(204, 158, 293, 20));
        QFont font2;
        font2.setPointSize(14);
        labelCardId->setFont(font2);
        labelCardId->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(TransactionsWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(432, 366, 81, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setWeight(50);
        label_7->setFont(font3);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(TransactionsWindow);

        QMetaObject::connectSlotsByName(TransactionsWindow);
    } // setupUi

    void retranslateUi(QWidget *TransactionsWindow)
    {
        TransactionsWindow->setWindowTitle(QCoreApplication::translate("TransactionsWindow", "Form", nullptr));
        labelTransactionsTitle->setText(QCoreApplication::translate("TransactionsWindow", "Tilitapahtumat", nullptr));
        pushButtonExit->setText(QString());
        labelCardId->setText(QCoreApplication::translate("TransactionsWindow", "Kortti ID:", nullptr));
        label_7->setText(QCoreApplication::translate("TransactionsWindow", "LOPETA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TransactionsWindow: public Ui_TransactionsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSACTIONSWINDOW_H
