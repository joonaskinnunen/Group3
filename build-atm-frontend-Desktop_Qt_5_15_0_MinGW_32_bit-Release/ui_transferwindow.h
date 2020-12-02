/********************************************************************************
** Form generated from reading UI file 'transferwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERWINDOW_H
#define UI_TRANSFERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TransferWindow
{
public:
    QLabel *labelTransferTitle;
    QLabel *labelAccountId;
    QLabel *labelBalance;
    QLabel *labelReceiverId;
    QLineEdit *lineEditReceiverId;
    QLabel *labelAmount;
    QLineEdit *lineEditAmount;
    QPushButton *pushButtonExit;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *pushButtonOk;
    QLabel *labelErrorMessage;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *TransferWindow)
    {
        if (TransferWindow->objectName().isEmpty())
            TransferWindow->setObjectName(QString::fromUtf8("TransferWindow"));
        TransferWindow->resize(700, 700);
        TransferWindow->setMinimumSize(QSize(700, 700));
        TransferWindow->setStyleSheet(QString::fromUtf8("#TransferWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}\n"
"QPushButton { border: none;}"));
        labelTransferTitle = new QLabel(TransferWindow);
        labelTransferTitle->setObjectName(QString::fromUtf8("labelTransferTitle"));
        labelTransferTitle->setGeometry(QRect(202, 130, 295, 23));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        labelTransferTitle->setFont(font);
        labelTransferTitle->setAlignment(Qt::AlignCenter);
        labelAccountId = new QLabel(TransferWindow);
        labelAccountId->setObjectName(QString::fromUtf8("labelAccountId"));
        labelAccountId->setGeometry(QRect(220, 150, 261, 20));
        QFont font1;
        font1.setPointSize(14);
        labelAccountId->setFont(font1);
        labelAccountId->setAlignment(Qt::AlignCenter);
        labelBalance = new QLabel(TransferWindow);
        labelBalance->setObjectName(QString::fromUtf8("labelBalance"));
        labelBalance->setGeometry(QRect(222, 170, 261, 20));
        labelBalance->setFont(font1);
        labelBalance->setAlignment(Qt::AlignCenter);
        labelReceiverId = new QLabel(TransferWindow);
        labelReceiverId->setObjectName(QString::fromUtf8("labelReceiverId"));
        labelReceiverId->setGeometry(QRect(220, 210, 261, 20));
        labelReceiverId->setFont(font1);
        labelReceiverId->setAlignment(Qt::AlignCenter);
        lineEditReceiverId = new QLineEdit(TransferWindow);
        lineEditReceiverId->setObjectName(QString::fromUtf8("lineEditReceiverId"));
        lineEditReceiverId->setEnabled(false);
        lineEditReceiverId->setGeometry(QRect(280, 234, 141, 23));
        lineEditReceiverId->setStyleSheet(QString::fromUtf8("color: black;"));
        labelAmount = new QLabel(TransferWindow);
        labelAmount->setObjectName(QString::fromUtf8("labelAmount"));
        labelAmount->setGeometry(QRect(220, 262, 261, 20));
        labelAmount->setFont(font1);
        labelAmount->setAlignment(Qt::AlignCenter);
        lineEditAmount = new QLineEdit(TransferWindow);
        lineEditAmount->setObjectName(QString::fromUtf8("lineEditAmount"));
        lineEditAmount->setEnabled(false);
        lineEditAmount->setGeometry(QRect(280, 284, 141, 23));
        lineEditAmount->setStyleSheet(QString::fromUtf8("color: black;"));
        pushButtonExit = new QPushButton(TransferWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(548, 360, 39, 33));
        pushButtonExit->setStyleSheet(QString::fromUtf8("border: none;"));
        label_7 = new QLabel(TransferWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(432, 364, 81, 21));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setWeight(50);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_8 = new QLabel(TransferWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(188, 366, 91, 21));
        label_8->setFont(font2);
        pushButtonOk = new QPushButton(TransferWindow);
        pushButtonOk->setObjectName(QString::fromUtf8("pushButtonOk"));
        pushButtonOk->setGeometry(QRect(114, 360, 39, 33));
        pushButtonOk->setStyleSheet(QString::fromUtf8("border: none;"));
        labelErrorMessage = new QLabel(TransferWindow);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(220, 192, 261, 20));
        labelErrorMessage->setFont(font1);
        labelErrorMessage->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget = new QWidget(TransferWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 422, 159, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_hole_shadow = new QLabel(TransferWindow);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(232, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(TransferWindow);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(232, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(TransferWindow);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(218, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));

        retranslateUi(TransferWindow);

        QMetaObject::connectSlotsByName(TransferWindow);
    } // setupUi

    void retranslateUi(QWidget *TransferWindow)
    {
        TransferWindow->setWindowTitle(QCoreApplication::translate("TransferWindow", "Form", nullptr));
        labelTransferTitle->setText(QCoreApplication::translate("TransferWindow", "Tilisiirto", nullptr));
        labelAccountId->setText(QCoreApplication::translate("TransferWindow", "Tili ID:", nullptr));
        labelBalance->setText(QCoreApplication::translate("TransferWindow", "K\303\244ytett\303\244viss\303\244:", nullptr));
        labelReceiverId->setText(QCoreApplication::translate("TransferWindow", "Vastaanottajan tilinumero:", nullptr));
        lineEditReceiverId->setText(QString());
        lineEditReceiverId->setPlaceholderText(QString());
        labelAmount->setText(QCoreApplication::translate("TransferWindow", "Summa:", nullptr));
        lineEditAmount->setText(QString());
        lineEditAmount->setPlaceholderText(QString());
        pushButtonExit->setText(QString());
        label_7->setText(QCoreApplication::translate("TransferWindow", "LOPETA", nullptr));
        label_8->setText(QCoreApplication::translate("TransferWindow", "HYV\303\204KSY", nullptr));
        pushButtonOk->setText(QString());
        labelErrorMessage->setText(QString());
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TransferWindow: public Ui_TransferWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERWINDOW_H
