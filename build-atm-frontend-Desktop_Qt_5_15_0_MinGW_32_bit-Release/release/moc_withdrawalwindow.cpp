/****************************************************************************
** Meta object code from reading C++ file 'withdrawalwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../atm-frontend/withdrawalwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'withdrawalwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WithdrawalWindow_t {
    QByteArrayData data[10];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_WithdrawalWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_WithdrawalWindow_t qt_meta_stringdata_WithdrawalWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "WithdrawalWindow"
QT_MOC_LITERAL(1, 17, 12), // "onKeyPressed"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 4), // "text"
QT_MOC_LITERAL(4, 36, 27), // "on_pushButtonTwenty_clicked"
QT_MOC_LITERAL(5, 64, 27), // "on_pushButtonFourty_clicked"
QT_MOC_LITERAL(6, 92, 26), // "on_pushButtonFifty_clicked"
QT_MOC_LITERAL(7, 119, 28), // "on_pushButtonHundred_clicked"
QT_MOC_LITERAL(8, 148, 35), // "on_pushButtonWdCustomAmount_c..."
QT_MOC_LITERAL(9, 184, 25) // "on_pushButtonExit_clicked"

    },
    "WithdrawalWindow\0onKeyPressed\0\0text\0"
    "on_pushButtonTwenty_clicked\0"
    "on_pushButtonFourty_clicked\0"
    "on_pushButtonFifty_clicked\0"
    "on_pushButtonHundred_clicked\0"
    "on_pushButtonWdCustomAmount_clicked\0"
    "on_pushButtonExit_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WithdrawalWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    0,   52,    2, 0x08 /* Private */,
       5,    0,   53,    2, 0x08 /* Private */,
       6,    0,   54,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WithdrawalWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WithdrawalWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onKeyPressed((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_pushButtonTwenty_clicked(); break;
        case 2: _t->on_pushButtonFourty_clicked(); break;
        case 3: _t->on_pushButtonFifty_clicked(); break;
        case 4: _t->on_pushButtonHundred_clicked(); break;
        case 5: _t->on_pushButtonWdCustomAmount_clicked(); break;
        case 6: _t->on_pushButtonExit_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject WithdrawalWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_WithdrawalWindow.data,
    qt_meta_data_WithdrawalWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *WithdrawalWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WithdrawalWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WithdrawalWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int WithdrawalWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
