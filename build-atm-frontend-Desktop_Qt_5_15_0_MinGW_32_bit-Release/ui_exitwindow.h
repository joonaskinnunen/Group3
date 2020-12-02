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
    QLabel *label_7;
    QLabel *label_ten;
    QLabel *label_twenty;
    QLabel *label_money_2;
    QLabel *label_twohundred;
    QLabel *label_hundred;
    QLabel *label_fifty;
    QLabel *label_hole_shadow;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;

    void setupUi(QWidget *ExitWindow)
    {
        if (ExitWindow->objectName().isEmpty())
            ExitWindow->setObjectName(QString::fromUtf8("ExitWindow"));
        ExitWindow->resize(700, 700);
        ExitWindow->setMinimumSize(QSize(700, 700));
        ExitWindow->setStyleSheet(QString::fromUtf8("#ExitWindow {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QWidget { color: white;}"));
        pushButtonExit = new QPushButton(ExitWindow);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(546, 360, 39, 33));
        pushButtonExit->setSizeIncrement(QSize(0, 0));
        pushButtonExit->setStyleSheet(QString::fromUtf8("border: none;"));
        label = new QLabel(ExitWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(172, 138, 359, 28));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        labelMessage = new QLabel(ExitWindow);
        labelMessage->setObjectName(QString::fromUtf8("labelMessage"));
        labelMessage->setGeometry(QRect(202, 186, 299, 39));
        QFont font1;
        font1.setPointSize(13);
        labelMessage->setFont(font1);
        labelMessage->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(ExitWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(432, 364, 81, 21));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setWeight(50);
        label_7->setFont(font2);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_ten = new QLabel(ExitWindow);
        label_ten->setObjectName(QString::fromUtf8("label_ten"));
        label_ten->setGeometry(QRect(252, 564, 190, 16));
        label_ten->setMinimumSize(QSize(151, 0));
        label_ten->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/10-euro-banknote.jpg")));
        label_ten->setScaledContents(false);
        label_twenty = new QLabel(ExitWindow);
        label_twenty->setObjectName(QString::fromUtf8("label_twenty"));
        label_twenty->setGeometry(QRect(252, 564, 190, 16));
        label_twenty->setMinimumSize(QSize(151, 0));
        label_twenty->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/20-euro-banknote.jpg")));
        label_twenty->setScaledContents(false);
        label_money_2 = new QLabel(ExitWindow);
        label_money_2->setObjectName(QString::fromUtf8("label_money_2"));
        label_money_2->setGeometry(QRect(252, 564, 190, 16));
        label_money_2->setMinimumSize(QSize(151, 0));
        label_money_2->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/20-euro-banknote.jpg")));
        label_money_2->setScaledContents(false);
        label_twohundred = new QLabel(ExitWindow);
        label_twohundred->setObjectName(QString::fromUtf8("label_twohundred"));
        label_twohundred->setGeometry(QRect(252, 564, 190, 16));
        label_twohundred->setMinimumSize(QSize(151, 0));
        label_twohundred->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/200-euro-banknote.jpg")));
        label_twohundred->setScaledContents(false);
        label_hundred = new QLabel(ExitWindow);
        label_hundred->setObjectName(QString::fromUtf8("label_hundred"));
        label_hundred->setGeometry(QRect(252, 564, 190, 16));
        label_hundred->setMinimumSize(QSize(151, 0));
        label_hundred->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/100-euro-banknote.png")));
        label_hundred->setScaledContents(false);
        label_fifty = new QLabel(ExitWindow);
        label_fifty->setObjectName(QString::fromUtf8("label_fifty"));
        label_fifty->setGeometry(QRect(252, 564, 190, 16));
        label_fifty->setMinimumSize(QSize(151, 0));
        label_fifty->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/50-euro-banknote.png")));
        label_fifty->setScaledContents(false);
        label_hole_shadow = new QLabel(ExitWindow);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        label_money_hole = new QLabel(ExitWindow);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(ExitWindow);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));
        label_money_hole->raise();
        pushButtonExit->raise();
        label->raise();
        labelMessage->raise();
        label_7->raise();
        label_twohundred->raise();
        label_hundred->raise();
        label_fifty->raise();
        label_twenty->raise();
        label_ten->raise();
        label_money_2->raise();
        label_hole_shadow->raise();
        label_hole_cover->raise();

        retranslateUi(ExitWindow);

        QMetaObject::connectSlotsByName(ExitWindow);
    } // setupUi

    void retranslateUi(QWidget *ExitWindow)
    {
        ExitWindow->setWindowTitle(QCoreApplication::translate("ExitWindow", "Form", nullptr));
        pushButtonExit->setText(QString());
        label->setText(QCoreApplication::translate("ExitWindow", "Kiitos automaatin k\303\244yt\303\266st\303\244!", nullptr));
        labelMessage->setText(QString());
        label_7->setText(QCoreApplication::translate("ExitWindow", "LOPETA", nullptr));
        label_ten->setText(QString());
        label_twenty->setText(QString());
        label_money_2->setText(QString());
        label_twohundred->setText(QString());
        label_hundred->setText(QString());
        label_fifty->setText(QString());
        label_hole_shadow->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ExitWindow: public Ui_ExitWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITWINDOW_H
