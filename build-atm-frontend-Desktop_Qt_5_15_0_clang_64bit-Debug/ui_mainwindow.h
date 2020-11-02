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
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEditId;
    QLabel *labelTest;
    QLabel *labelErrorMessage;
    QPushButton *pushButtonLogin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEditId = new QLineEdit(centralwidget);
        lineEditId->setObjectName(QString::fromUtf8("lineEditId"));
        lineEditId->setGeometry(QRect(290, 230, 191, 31));
        QFont font;
        font.setPointSize(13);
        lineEditId->setFont(font);
        lineEditId->setAlignment(Qt::AlignCenter);
        labelTest = new QLabel(centralwidget);
        labelTest->setObjectName(QString::fromUtf8("labelTest"));
        labelTest->setGeometry(QRect(90, 180, 601, 41));
        QFont font1;
        font1.setPointSize(18);
        labelTest->setFont(font1);
        labelTest->setAlignment(Qt::AlignCenter);
        labelErrorMessage = new QLabel(centralwidget);
        labelErrorMessage->setObjectName(QString::fromUtf8("labelErrorMessage"));
        labelErrorMessage->setGeometry(QRect(96, 280, 591, 20));
        labelErrorMessage->setAlignment(Qt::AlignCenter);
        pushButtonLogin = new QPushButton(centralwidget);
        pushButtonLogin->setObjectName(QString::fromUtf8("pushButtonLogin"));
        pushButtonLogin->setGeometry(QRect(320, 310, 130, 50));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEditId->setText(QString());
        labelTest->setText(QCoreApplication::translate("MainWindow", "Sy\303\266t\303\244 kortin numero", nullptr));
        labelErrorMessage->setText(QString());
        pushButtonLogin->setText(QCoreApplication::translate("MainWindow", "CONTINUE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
