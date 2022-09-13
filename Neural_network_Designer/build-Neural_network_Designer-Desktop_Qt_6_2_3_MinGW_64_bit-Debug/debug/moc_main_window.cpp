/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Neural_network_Designer/main_window.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Main_window_t {
    const uint offsetsAndSize[16];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Main_window_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Main_window_t qt_meta_stringdata_Main_window = {
    {
QT_MOC_LITERAL(0, 11), // "Main_window"
QT_MOC_LITERAL(12, 8), // "maximize"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 8), // "minimize"
QT_MOC_LITERAL(31, 7), // "new_tab"
QT_MOC_LITERAL(39, 5), // "index"
QT_MOC_LITERAL(45, 16), // "new_tab_left_bar"
QT_MOC_LITERAL(62, 10) // "remove_tab"

    },
    "Main_window\0maximize\0\0minimize\0new_tab\0"
    "index\0new_tab_left_bar\0remove_tab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_window[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x08,    1 /* Private */,
       3,    0,   45,    2, 0x08,    2 /* Private */,
       4,    1,   46,    2, 0x08,    3 /* Private */,
       6,    0,   49,    2, 0x08,    5 /* Private */,
       7,    1,   50,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

       0        // eod
};

void Main_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Main_window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->maximize(); break;
        case 1: _t->minimize(); break;
        case 2: _t->new_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->new_tab_left_bar(); break;
        case 4: _t->remove_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Main_window::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_Main_window.offsetsAndSize,
    qt_meta_data_Main_window,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Main_window_t
, QtPrivate::TypeAndForceComplete<Main_window, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Main_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Main_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Main_window.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Main_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
