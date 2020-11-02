/********************************************************************************
** Form generated from reading UI file 'exitwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITWINDOW_H
#define UI_EXITWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExitWindow
{
public:
    QPushButton *pushButtonExit;
    QLabel *label;
    QLabel *labelMessage;

    void setupUi(QWidget *ExitWindow)
    {
        if (ExitWindow->objectName().isEmpty())
            ExitWindow->setObjectName(QString::fromUtf8("ExitWindow"));
        ExitWindow->resize(600, 500);
        pushButtonExit = new QPushButton(ExitWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(245, 391, 111, 41));
        label = new QLabel(ExitWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1, 59, 601, 28));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        labelMessage = new QLabel(ExitWindow);
        labelMessage->setObjectName(QString::fromUtf8("labelMessage"));
        labelMessage->setGeometry(QRect(10, 160, 582, 31));
        QFont font1;
        font1.setPointSize(15);
        labelMessage->setFont(font1);
        labelMessage->setAlignment(Qt::AlignCenter);

        retranslateUi(ExitWindow);

        QMetaObject::connectSlotsByName(ExitWindow);
    } // setupUi

    void retranslateUi(QWidget *ExitWindow)
    {
        ExitWindow->setWindowTitle(QCoreApplication::translate("ExitWindow", "Form", nullptr));
        pushButtonExit->setText(QCoreApplication::translate("ExitWindow", "LOPETA", nullptr));
        label->setText(QCoreApplication::translate("ExitWindow", "Kiitos automaatin k\303\244yt\303\266st\303\244!", nullptr));
        labelMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExitWindow: public Ui_ExitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITWINDOW_H
