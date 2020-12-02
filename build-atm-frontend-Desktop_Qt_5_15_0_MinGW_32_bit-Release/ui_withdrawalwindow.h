/********************************************************************************
** Form generated from reading UI file 'withdrawalwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAWALWINDOW_H
#define UI_WITHDRAWALWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WithdrawalWindow
{
public:
    QPushButton *pushButtonTwenty;
    QPushButton *pushButtonHundred;
    QPushButton *pushButtonFifty;
    QLabel *labelErrorMessage;
    QLabel *label_2;
    QPushButton *pushButtonFourty;
    QPushButton *pushButtonWdCustomAmount;
    QLabel *label;
    QLineEdit *lineEditWithDrawalAmount;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButtonExit;
    QLabel *label_7;
    QPushButton *pushButtonFive;
    QPushButton *pushButtonThree;
    QPushButton *pushButtonOne;
    QPushButton *pushButtonTwo;
    QPushButton *pushButtonZero;
    QPushButton *pushButtonSeven;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonEnter;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonEight;
    QPushButton *pushButtonFour;
    QPushButton *pushButtonNine;
    QPushButton *pushButtonSix;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *WithdrawalWindow)
    {
        if (WithdrawalWindow->objectName().isEmpty())
            WithdrawalWindow->setObjectName(QString::fromUtf8("WithdrawalWindow"));
        WithdrawalWindow->resize(700, 700);
        WithdrawalWindow->setMinimumSize(QSize(700, 700));
        QFont font;
        font.setPointSize(10);
        WithdrawalWindow->setFont(font);
        WithdrawalWindow->setStyleSheet(QString::fromUtf8("#WithdrawalWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}\n"
"QPushButton { border: none;}"));
        pushButtonTwenty = new QPushButton(WithdrawalWindow);
        pushButtonTwenty->setObjectName(QString::fromUtf8("pushButtonTwenty"));
        pushButtonTwenty->setGeometry(QRect(114, 236, 39, 33));
        pushButtonHundred = new QPushButton(WithdrawalWindow);
        pushButtonHundred->setObjectName(QString::fromUtf8("pushButtonHundred"));
        pushButtonHundred->setGeometry(QRect(546, 278, 39, 33));
        pushButtonFifty = new QPushButton(WithdrawalWindow);
        pushButtonFifty->setObjectName(QString::fromUtf8("pushButtonFifty"));
        pushButtonFifty->setGeometry(QRect(546, 234, 39, 33));
        labelErrorMessage = new QLabel(WithdrawalWindow);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(202, 180, 297, 20));
        labelErrorMessage->setFont(font);
        labelErrorMessage->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(WithdrawalWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 156, 299, 20));
        QFont font1;
        font1.setPointSize(20);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        pushButtonFourty = new QPushButton(WithdrawalWindow);
        pushButtonFourty->setObjectName(QString::fromUtf8("pushButtonFourty"));
        pushButtonFourty->setGeometry(QRect(114, 276, 39, 33));
        pushButtonWdCustomAmount = new QPushButton(WithdrawalWindow);
        pushButtonWdCustomAmount->setObjectName(QString::fromUtf8("pushButtonWdCustomAmount"));
        pushButtonWdCustomAmount->setGeometry(QRect(114, 360, 39, 33));
        label = new QLabel(WithdrawalWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(202, 126, 297, 31));
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(true);
        font2.setWeight(75);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);
        lineEditWithDrawalAmount = new QLineEdit(WithdrawalWindow);
        lineEditWithDrawalAmount->setObjectName(QString::fromUtf8("lineEditWithDrawalAmount"));
        lineEditWithDrawalAmount->setEnabled(false);
        lineEditWithDrawalAmount->setGeometry(QRect(182, 364, 121, 21));
        lineEditWithDrawalAmount->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color:white;\n"
""));
        label_3 = new QLabel(WithdrawalWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(186, 241, 41, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setWeight(50);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
        label_4 = new QLabel(WithdrawalWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(186, 282, 33, 21));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        label_5 = new QLabel(WithdrawalWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(470, 244, 41, 21));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: white;"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_6 = new QLabel(WithdrawalWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(420, 282, 91, 21));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: white;"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonExit = new QPushButton(WithdrawalWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(546, 358, 39, 33));
        label_7 = new QLabel(WithdrawalWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(422, 364, 91, 21));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: white;"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonFive = new QPushButton(WithdrawalWindow);
        pushButtonFive->setObjectName(QString::fromUtf8("pushButtonFive"));
        pushButtonFive->setGeometry(QRect(355, 620, 51, 35));
        pushButtonThree = new QPushButton(WithdrawalWindow);
        pushButtonThree->setObjectName(QString::fromUtf8("pushButtonThree"));
        pushButtonThree->setGeometry(QRect(395, 585, 51, 41));
        pushButtonOne = new QPushButton(WithdrawalWindow);
        pushButtonOne->setObjectName(QString::fromUtf8("pushButtonOne"));
        pushButtonOne->setGeometry(QRect(315, 585, 51, 41));
        pushButtonTwo = new QPushButton(WithdrawalWindow);
        pushButtonTwo->setObjectName(QString::fromUtf8("pushButtonTwo"));
        pushButtonTwo->setGeometry(QRect(355, 585, 51, 41));
        pushButtonZero = new QPushButton(WithdrawalWindow);
        pushButtonZero->setObjectName(QString::fromUtf8("pushButtonZero"));
        pushButtonZero->setGeometry(QRect(345, 685, 61, 41));
        pushButtonSeven = new QPushButton(WithdrawalWindow);
        pushButtonSeven->setObjectName(QString::fromUtf8("pushButtonSeven"));
        pushButtonSeven->setGeometry(QRect(315, 650, 51, 41));
        pushButtonClear = new QPushButton(WithdrawalWindow);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(440, 620, 61, 41));
        pushButtonEnter = new QPushButton(WithdrawalWindow);
        pushButtonEnter->setObjectName(QString::fromUtf8("pushButtonEnter"));
        pushButtonEnter->setGeometry(QRect(440, 650, 61, 41));
        pushButtonCancel = new QPushButton(WithdrawalWindow);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(440, 585, 61, 41));
        pushButtonEight = new QPushButton(WithdrawalWindow);
        pushButtonEight->setObjectName(QString::fromUtf8("pushButtonEight"));
        pushButtonEight->setGeometry(QRect(355, 650, 51, 41));
        pushButtonFour = new QPushButton(WithdrawalWindow);
        pushButtonFour->setObjectName(QString::fromUtf8("pushButtonFour"));
        pushButtonFour->setGeometry(QRect(315, 620, 51, 35));
        pushButtonNine = new QPushButton(WithdrawalWindow);
        pushButtonNine->setObjectName(QString::fromUtf8("pushButtonNine"));
        pushButtonNine->setGeometry(QRect(395, 650, 51, 41));
        pushButtonSix = new QPushButton(WithdrawalWindow);
        pushButtonSix->setObjectName(QString::fromUtf8("pushButtonSix"));
        pushButtonSix->setGeometry(QRect(395, 620, 51, 35));
        verticalLayoutWidget = new QWidget(WithdrawalWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 424, 161, 117));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_hole_shadow = new QLabel(WithdrawalWindow);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(WithdrawalWindow);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(WithdrawalWindow);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));

        retranslateUi(WithdrawalWindow);

        QMetaObject::connectSlotsByName(WithdrawalWindow);
    } // setupUi

    void retranslateUi(QWidget *WithdrawalWindow)
    {
        WithdrawalWindow->setWindowTitle(QCoreApplication::translate("WithdrawalWindow", "Form", nullptr));
        pushButtonTwenty->setText(QString());
        pushButtonHundred->setText(QString());
        pushButtonFifty->setText(QString());
        labelErrorMessage->setText(QString());
        label_2->setText(QCoreApplication::translate("WithdrawalWindow", "Valitse summa", nullptr));
        pushButtonFourty->setText(QString());
        pushButtonWdCustomAmount->setText(QString());
        label->setText(QCoreApplication::translate("WithdrawalWindow", "NOSTO", nullptr));
        lineEditWithDrawalAmount->setText(QString());
        lineEditWithDrawalAmount->setPlaceholderText(QCoreApplication::translate("WithdrawalWindow", "Sy\303\266t\303\244 muu summa", nullptr));
        label_3->setText(QCoreApplication::translate("WithdrawalWindow", "20\342\202\254", nullptr));
        label_4->setText(QCoreApplication::translate("WithdrawalWindow", "40\342\202\254", nullptr));
        label_5->setText(QCoreApplication::translate("WithdrawalWindow", "50\342\202\254", nullptr));
        label_6->setText(QCoreApplication::translate("WithdrawalWindow", "100\342\202\254", nullptr));
        pushButtonExit->setText(QString());
        label_7->setText(QCoreApplication::translate("WithdrawalWindow", "LOPETA", nullptr));
        pushButtonFive->setText(QString());
        pushButtonThree->setText(QString());
        pushButtonOne->setText(QString());
        pushButtonTwo->setText(QString());
        pushButtonZero->setText(QString());
        pushButtonSeven->setText(QString());
        pushButtonClear->setText(QString());
        pushButtonEnter->setText(QString());
        pushButtonCancel->setText(QString());
        pushButtonEight->setText(QString());
        pushButtonFour->setText(QString());
        pushButtonNine->setText(QString());
        pushButtonSix->setText(QString());
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WithdrawalWindow: public Ui_WithdrawalWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAWALWINDOW_H
