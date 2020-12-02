/********************************************************************************
** Form generated from reading UI file 'depositwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPOSITWINDOW_H
#define UI_DEPOSITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DepositWindow
{
public:
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *pushButtonFifty;
    QPushButton *pushButtonExit;
    QLineEdit *lineEditDepositAmount;
    QPushButton *pushButtonFourty;
    QLabel *label;
    QPushButton *pushButtonTwenty;
    QLabel *label_6;
    QLabel *labelErrorMessage;
    QLabel *label_7;
    QPushButton *pushButtonHundred;
    QPushButton *pushButtonWdCustomAmount;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *DepositWindow)
    {
        if (DepositWindow->objectName().isEmpty())
            DepositWindow->setObjectName(QString::fromUtf8("DepositWindow"));
        DepositWindow->resize(700, 700);
        DepositWindow->setMinimumSize(QSize(700, 700));
        DepositWindow->setStyleSheet(QString::fromUtf8("#DepositWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}\n"
"QPushButton { border: none;}"));
        label_2 = new QLabel(DepositWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(172, 156, 355, 31));
        QFont font;
        font.setPointSize(15);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(DepositWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(474, 242, 41, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(false);
        font1.setWeight(50);
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: white;"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonFifty = new QPushButton(DepositWindow);
        pushButtonFifty->setObjectName(QString::fromUtf8("pushButtonFifty"));
        pushButtonFifty->setGeometry(QRect(546, 236, 39, 33));
        pushButtonExit = new QPushButton(DepositWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(544, 358, 39, 33));
        lineEditDepositAmount = new QLineEdit(DepositWindow);
        lineEditDepositAmount->setObjectName(QString::fromUtf8("lineEditDepositAmount"));
        lineEditDepositAmount->setEnabled(false);
        lineEditDepositAmount->setGeometry(QRect(184, 366, 121, 23));
        QFont font2;
        font2.setPointSize(10);
        lineEditDepositAmount->setFont(font2);
        lineEditDepositAmount->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color:white;"));
        pushButtonFourty = new QPushButton(DepositWindow);
        pushButtonFourty->setObjectName(QString::fromUtf8("pushButtonFourty"));
        pushButtonFourty->setGeometry(QRect(113, 276, 39, 33));
        label = new QLabel(DepositWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 130, 359, 31));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        pushButtonTwenty = new QPushButton(DepositWindow);
        pushButtonTwenty->setObjectName(QString::fromUtf8("pushButtonTwenty"));
        pushButtonTwenty->setGeometry(QRect(115, 236, 41, 31));
        label_6 = new QLabel(DepositWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(424, 284, 91, 21));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: white;"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        labelErrorMessage = new QLabel(DepositWindow);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(174, 188, 353, 33));
        labelErrorMessage->setFont(font2);
        labelErrorMessage->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(DepositWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(416, 364, 101, 21));
        label_7->setFont(font1);
        label_7->setStyleSheet(QString::fromUtf8("color: white;"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonHundred = new QPushButton(DepositWindow);
        pushButtonHundred->setObjectName(QString::fromUtf8("pushButtonHundred"));
        pushButtonHundred->setGeometry(QRect(544, 278, 39, 33));
        pushButtonWdCustomAmount = new QPushButton(DepositWindow);
        pushButtonWdCustomAmount->setObjectName(QString::fromUtf8("pushButtonWdCustomAmount"));
        pushButtonWdCustomAmount->setGeometry(QRect(108, 360, 51, 33));
        label_4 = new QLabel(DepositWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(184, 282, 37, 21));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        label_3 = new QLabel(DepositWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(186, 240, 41, 21));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
        verticalLayoutWidget = new QWidget(DepositWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 424, 159, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_hole_shadow = new QLabel(DepositWindow);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(DepositWindow);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(DepositWindow);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));

        retranslateUi(DepositWindow);

        QMetaObject::connectSlotsByName(DepositWindow);
    } // setupUi

    void retranslateUi(QWidget *DepositWindow)
    {
        DepositWindow->setWindowTitle(QCoreApplication::translate("DepositWindow", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("DepositWindow", "Valitse summa", nullptr));
        label_5->setText(QCoreApplication::translate("DepositWindow", "50\342\202\254", nullptr));
        pushButtonFifty->setText(QString());
        pushButtonExit->setText(QString());
        lineEditDepositAmount->setText(QString());
        lineEditDepositAmount->setPlaceholderText(QCoreApplication::translate("DepositWindow", "Sy\303\266t\303\244 muu summa", nullptr));
        pushButtonFourty->setText(QString());
        label->setText(QCoreApplication::translate("DepositWindow", "TALLETUS", nullptr));
        pushButtonTwenty->setText(QString());
        label_6->setText(QCoreApplication::translate("DepositWindow", "100\342\202\254", nullptr));
        labelErrorMessage->setText(QString());
        label_7->setText(QCoreApplication::translate("DepositWindow", "LOPETA", nullptr));
        pushButtonHundred->setText(QString());
        pushButtonWdCustomAmount->setText(QString());
        label_4->setText(QCoreApplication::translate("DepositWindow", "40\342\202\254", nullptr));
        label_3->setText(QCoreApplication::translate("DepositWindow", "20\342\202\254", nullptr));
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class DepositWindow: public Ui_DepositWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPOSITWINDOW_H
