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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLabel *labelErrorMessage;
    QLineEdit *lineEditPin;
    QLabel *labelTest;
    QPushButton *pushButtonCheckPin;
    QLabel *labelTest_2;
    QLabel *labelCardId;

    void setupUi(QWidget *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QString::fromUtf8("Login"));
        Login->resize(800, 600);
        labelErrorMessage = new QLabel(Login);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(106, 320, 591, 20));
        labelErrorMessage->setAlignment(Qt::AlignCenter);
        lineEditPin = new QLineEdit(Login);
        lineEditPin->setObjectName(QString::fromUtf8("lineEditPin"));
        lineEditPin->setGeometry(QRect(300, 270, 191, 31));
        QFont font;
        font.setPointSize(13);
        lineEditPin->setFont(font);
        lineEditPin->setAlignment(Qt::AlignCenter);
        labelTest = new QLabel(Login);
        labelTest->setObjectName(QString::fromUtf8("labelTest"));
        labelTest->setGeometry(QRect(100, 220, 601, 41));
        QFont font1;
        font1.setPointSize(18);
        labelTest->setFont(font1);
        labelTest->setAlignment(Qt::AlignCenter);
        pushButtonCheckPin = new QPushButton(Login);
        pushButtonCheckPin->setObjectName(QString::fromUtf8("pushButtonCheckPin"));
        pushButtonCheckPin->setGeometry(QRect(330, 350, 130, 50));
        labelTest_2 = new QLabel(Login);
        labelTest_2->setObjectName(QString::fromUtf8("labelTest_2"));
        labelTest_2->setGeometry(QRect(100, 120, 601, 41));
        labelTest_2->setFont(font1);
        labelTest_2->setAlignment(Qt::AlignCenter);
        labelCardId = new QLabel(Login);
        labelCardId->setObjectName(QString::fromUtf8("labelCardId"));
        labelCardId->setGeometry(QRect(100, 170, 601, 41));
        labelCardId->setFont(font1);
        labelCardId->setAlignment(Qt::AlignCenter);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QWidget *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "Form", nullptr));
        labelErrorMessage->setText(QString());
        lineEditPin->setText(QString());
        labelTest->setText(QCoreApplication::translate("Login", "Sy\303\266t\303\244 PIN-koodi", nullptr));
        pushButtonCheckPin->setText(QCoreApplication::translate("Login", "CONTINUE", nullptr));
        labelTest_2->setText(QCoreApplication::translate("Login", "Tili", nullptr));
        labelCardId->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
