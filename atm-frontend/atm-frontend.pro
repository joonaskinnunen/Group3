QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accountchoicewindow.cpp \
    actionchoicewindow.cpp \
    balancewindow.cpp \
    cardsingleton.cpp \
    exitwindow.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    transactionswindow.cpp \
    withdrawalwindow.cpp

HEADERS += \
    accountchoicewindow.h \
    actionchoicewindow.h \
    balancewindow.h \
    cardsingleton.h \
    exitwindow.h \
    login.h \
    mainwindow.h \
    transactionswindow.h \
    withdrawalwindow.h

FORMS += \
    accountchoicewindow.ui \
    actionchoicewindow.ui \
    balancewindow.ui \
    exitwindow.ui \
    login.ui \
    mainwindow.ui \
    transactionswindow.ui \
    withdrawalwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#macx: LIBS += -L$$PWD/../Libraries/build-httpLibrary-Desktop_Qt_5_15_0_clang_64bit-Debug/ -lhttpLibrary.1.0.0

#INCLUDEPATH += $$PWD/../Libraries/build-httpLibrary-Desktop_Qt_5_15_0_clang_64bit-Debug
#DEPENDPATH += $$PWD/../Libraries/build-httpLibrary-Desktop_Qt_5_15_0_clang_64bit-Debug

win32: LIBS += -L$$PWD/../Libraries/build-httpLibrary-Desktop_Qt_5_15_0_clang_64bit-Debug/ -lhttpLibrary.1.0.0

INCLUDEPATH += $$PWD/../Libraries/httpLibrary
DEPENDPATH += $$PWD/../Libraries/httpLibrary

macx: LIBS += -L$$PWD/../Libraries/build-httpLibrary-Desktop_Qt_5_15_0_clang_64bit-Debug/ -lhttpLibrary.1.0.0

INCLUDEPATH += $$PWD/../Libraries/httpLibrary
DEPENDPATH += $$PWD/../Libraries/httpLibrary
