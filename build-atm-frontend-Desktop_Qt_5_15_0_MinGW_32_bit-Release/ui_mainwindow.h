/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditId;
    QLabel *labelTitle;
    QLabel *labelErrorMessage;
    QPushButton *pushButtonLogin;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButtonExit;
    QLabel *label_money_hole;
    QLabel *label_hole_cover;
    QLabel *label_hole_shadow;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(700, 700);
        MainWindow->setMinimumSize(QSize(700, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget {border-image: url(:atm-frontend/bgwithkeypad.png) 0 0 0 0 stretch stretch;}\n"
"QPushButton {border: none;}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEditId = new QLineEdit(centralwidget);
        lineEditId->setObjectName(QString::fromUtf8("lineEditId"));
        lineEditId->setEnabled(false);
        lineEditId->setGeometry(QRect(276, 184, 161, 25));
        QFont font;
        font.setPointSize(13);
        lineEditId->setFont(font);
        lineEditId->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"    color: black;"));
        lineEditId->setAlignment(Qt::AlignCenter);
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setGeometry(QRect(202, 148, 301, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        labelTitle->setFont(font1);
        labelTitle->setStyleSheet(QString::fromUtf8("color:white;"));
        labelTitle->setAlignment(Qt::AlignCenter);
        labelErrorMessage = new QLabel(centralwidget);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(260, 220, 191, 20));
        labelErrorMessage->setAlignment(Qt::AlignCenter);
        pushButtonLogin = new QPushButton(centralwidget);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(546, 236, 37, 33));
        pushButtonLogin->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(442, 242, 71, 21));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setWeight(50);
        label->setFont(font2);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 366, 81, 21));
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButtonExit = new QPushButton(centralwidget);
        pushButtonExit->setObjectName(QString::fromUtf8("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(548, 360, 37, 33));
        pushButtonExit->setStyleSheet(QString::fromUtf8(""));
        label_money_hole = new QLabel(centralwidget);
        label_money_hole->setObjectName(QString::fromUtf8("label_money_hole"));
        label_money_hole->setGeometry(QRect(246, 562, 203, 30));
        label_money_hole->setStyleSheet(QString::fromUtf8("background-color:black;\n"
"border-radius:5px;\n"
""));
        label_hole_cover = new QLabel(centralwidget);
        label_hole_cover->setObjectName(QString::fromUtf8("label_hole_cover"));
        label_hole_cover->setGeometry(QRect(232, 562, 229, 21));
        label_hole_cover->setStyleSheet(QString::fromUtf8("background-color:#363940;\n"
"border-radius:5px;"));
        label_hole_cover->setFrameShape(QFrame::NoFrame);
        label_hole_cover->setPixmap(QPixmap(QString::fromUtf8(":/atm-frontend/hole_cover.png")));
        label_hole_shadow = new QLabel(centralwidget);
        label_hole_shadow->setObjectName(QString::fromUtf8("label_hole_shadow"));
        label_hole_shadow->setGeometry(QRect(246, 576, 204, 16));
        label_hole_shadow->setStyleSheet(QString::fromUtf8("background-color:rgba(0,0,0,50);"));
        label_hole_shadow->setFrameShape(QFrame::NoFrame);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 424, 161, 119));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MainWindow->setCentralWidget(centralwidget);
        lineEditId->raise();
        labelTitle->raise();
        labelErrorMessage->raise();
        pushButtonLogin->raise();
        label->raise();
        label_2->raise();
        pushButtonExit->raise();
        verticalLayoutWidget->raise();
        label_money_hole->raise();
        label_hole_shadow->raise();
        label_hole_cover->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEditId->setText(QString());
        labelTitle->setText(QCoreApplication::translate("MainWindow", "Sy\303\266t\303\244 kortin numero", nullptr));
        labelErrorMessage->setText(QString());
        pushButtonLogin->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "JATKA", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "LOPETA", nullptr));
        pushButtonExit->setText(QString());
        label_money_hole->setText(QString());
        label_hole_cover->setText(QString());
        label_hole_shadow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
