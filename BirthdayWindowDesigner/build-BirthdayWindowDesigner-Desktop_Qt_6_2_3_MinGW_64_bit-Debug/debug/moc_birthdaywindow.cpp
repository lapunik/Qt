/****************************************************************************
** Meta object code from reading C++ file 'birthdaywindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../BirthdayWindowDesigner/birthdaywindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'birthdaywindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BirthdayWindow_t {
    const uint offsetsAndSize[18];
    char stringdata0[236];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BirthdayWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BirthdayWindow_t qt_meta_stringdata_BirthdayWindow = {
    {
QT_MOC_LITERAL(0, 14), // "BirthdayWindow"
QT_MOC_LITERAL(15, 35), // "on_mp_action_pridat_osobu_tri..."
QT_MOC_LITERAL(51, 0), // ""
QT_MOC_LITERAL(52, 33), // "on_action_upravit_osobu_trigg..."
QT_MOC_LITERAL(86, 24), // "on_action_exit_triggered"
QT_MOC_LITERAL(111, 34), // "on_action_panel_nastroju_trig..."
QT_MOC_LITERAL(146, 33), // "on_action_stavovy_radek_trigg..."
QT_MOC_LITERAL(180, 24), // "on_action_o_Qt_triggered"
QT_MOC_LITERAL(205, 30) // "on_action_o_programu_triggered"

    },
    "BirthdayWindow\0on_mp_action_pridat_osobu_triggered\0"
    "\0on_action_upravit_osobu_triggered\0"
    "on_action_exit_triggered\0"
    "on_action_panel_nastroju_triggered\0"
    "on_action_stavovy_radek_triggered\0"
    "on_action_o_Qt_triggered\0"
    "on_action_o_programu_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BirthdayWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x08,    1 /* Private */,
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    0,   58,    2, 0x08,    3 /* Private */,
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x08,    7 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BirthdayWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BirthdayWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_mp_action_pridat_osobu_triggered(); break;
        case 1: _t->on_action_upravit_osobu_triggered(); break;
        case 2: _t->on_action_exit_triggered(); break;
        case 3: _t->on_action_panel_nastroju_triggered(); break;
        case 4: _t->on_action_stavovy_radek_triggered(); break;
        case 5: _t->on_action_o_Qt_triggered(); break;
        case 6: _t->on_action_o_programu_triggered(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject BirthdayWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_BirthdayWindow.offsetsAndSize,
    qt_meta_data_BirthdayWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BirthdayWindow_t
, QtPrivate::TypeAndForceComplete<BirthdayWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *BirthdayWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BirthdayWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BirthdayWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int BirthdayWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
