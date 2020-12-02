/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *labelErrorMessage;
    QLineEdit *lineEditPin;
    QLabel *labelTitle;
    QPushButton *pushButtonCheckPin;
    QLabel *labelCardId;
    QLabel *labelWelcomeMsg;
    QLabel *label;
    QPushButton *pushButtonExit;
    QLabel *label_2;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonEnter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(700, 700);
        Login->setMinimumSize(QSize(700, 700));
        Login->setStyleSheet(QString::fromUtf8("#Login {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QPushButton {border: none;}"));
        labelErrorMessage = new QLabel(Login);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(270, 242, 181, 20));
        labelErrorMessage->setAlignment(Qt::AlignCenter);
        lineEditPin = new QLineEdit(Login);
        lineEditPin->setObjectName(QString::fromUtf8("lineEditPin"));
        lineEditPin->setEnabled(false);
        lineEditPin->setGeometry(QRect(264, 202, 191, 31));
        QFont font;
        font.setPointSize(13);
        lineEditPin->setFont(font);
        lineEditPin->setStyleSheet(QString::fromUtf8("color: black;"));
        lineEditPin->setAlignment(Qt::AlignCenter);
        labelTitle = new QLabel(Login);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(204, 174, 299, 27));
        QFont font1;
        font1.setPointSize(15);
        labelTitle->setFont(font1);
        labelTitle->setStyleSheet(QString::fromUtf8("color:white"));
        labelTitle->setAlignment(Qt::AlignCenter);
        pushButtonCheckPin = new QPushButton(Login);
        pushButtonCheckPin->setObjectName(QString::fromUtf8("pushButtonCheckPin"));
        pushButtonCheckPin->setGeometry(QRect(114, 360, 41, 33));
        pushButtonCheckPin->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        labelCardId = new QLabel(Login);
        labelCardId->setObjectName(QString::fromUtf8("labelCardId"));
        labelCardId->setGeometry(QRect(204, 154, 299, 27));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        labelCardId->setFont(font2);
        labelCardId->setStyleSheet(QString::fromUtf8("color:white"));
        labelCardId->setAlignment(Qt::AlignCenter);
        labelWelcomeMsg = new QLabel(Login);
        labelWelcomeMsg->setObjectName(QString::fromUtf8("labelWelcomeMsg"));
        labelWelcomeMsg->setGeometry(QRect(208, 134, 293, 23));
        labelWelcomeMsg->setFont(font);
        labelWelcomeMsg->setStyleSheet(QString::fromUtf8("color:white;"));
        labelWelcomeMsg->setAlignment(Qt::AlignCenter);
        label = new QLabel(Login);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(188, 366, 111, 21));
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(false);
        font3.setWeight(50);
        label->setFont(font3);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        pushButtonExit = new QPushButton(Login);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(546, 360, 43, 33));
        pushButtonExit->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(430, 364, 81, 21));
        label_2->setFont(font3);
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonCancel = new QPushButton(Login);
        pushButtonCancel->setObjectName(QString::fromUtf8("pushButtonCancel"));
        pushButtonCancel->setGeometry(QRect(445, 585, 61, 41));
        pushButtonClear = new QPushButton(Login);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(445, 620, 61, 41));
        pushButtonEnter = new QPushButton(Login);
        pushButtonEnter->setObjectName(QString::fromUtf8("pushButtonEnter"));
        pushButtonEnter->setGeometry(QRect(445, 650, 61, 41));
        verticalLayoutWidget = new QWidget(Login);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 424, 159, 119));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label_hole_shadow = new QLabel(Login);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(Login);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(Login);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        labelErrorMessage->setText(QString());
        lineEditPin->setText(QString());
        labelTitle->setText(QCoreApplication::translate("Login", "Sy\303\266t\303\244 PIN-koodi", nullptr));
        pushButtonCheckPin->setText(QString());
        labelCardId->setText(QCoreApplication::translate("Login", "Tili", nullptr));
        labelWelcomeMsg->setText(QString());
        label->setText(QCoreApplication::translate("Login", "KIRJAUDU", nullptr));
        pushButtonExit->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "LOPETA", nullptr));
        pushButtonCancel->setText(QString());
        pushButtonClear->setText(QString());
        pushButtonEnter->setText(QString());
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
