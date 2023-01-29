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
    const uint offsetsAndSize[36];
    char stringdata0[167];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Main_window_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Main_window_t qt_meta_stringdata_Main_window = {
    {
QT_MOC_LITERAL(0, 11), // "Main_window"
QT_MOC_LITERAL(12, 4), // "save"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 1), // "b"
QT_MOC_LITERAL(20, 5), // "index"
QT_MOC_LITERAL(26, 18), // "change_block_state"
QT_MOC_LITERAL(45, 5), // "state"
QT_MOC_LITERAL(51, 8), // "maximize"
QT_MOC_LITERAL(60, 8), // "minimize"
QT_MOC_LITERAL(69, 12), // "save_clicked"
QT_MOC_LITERAL(82, 12), // "load_clicked"
QT_MOC_LITERAL(95, 15), // "save_as_clicked"
QT_MOC_LITERAL(111, 7), // "new_tab"
QT_MOC_LITERAL(119, 16), // "new_tab_left_bar"
QT_MOC_LITERAL(136, 11), // "change_name"
QT_MOC_LITERAL(148, 2), // "id"
QT_MOC_LITERAL(151, 4), // "name"
QT_MOC_LITERAL(156, 10) // "remove_tab"

    },
    "Main_window\0save\0\0b\0index\0change_block_state\0"
    "state\0maximize\0minimize\0save_clicked\0"
    "load_clicked\0save_as_clicked\0new_tab\0"
    "new_tab_left_bar\0change_name\0id\0name\0"
    "remove_tab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Main_window[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   80,    2, 0x06,    1 /* Public */,
       5,    1,   85,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   88,    2, 0x08,    6 /* Private */,
       8,    0,   89,    2, 0x08,    7 /* Private */,
       9,    0,   90,    2, 0x08,    8 /* Private */,
      10,    0,   91,    2, 0x08,    9 /* Private */,
      11,    0,   92,    2, 0x08,   10 /* Private */,
      12,    1,   93,    2, 0x08,   11 /* Private */,
      13,    0,   96,    2, 0x08,   13 /* Private */,
      14,    2,   97,    2, 0x08,   14 /* Private */,
      17,    1,  102,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Bool,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   15,   16,
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void Main_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Main_window *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->save((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->change_block_state((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->maximize(); break;
        case 3: _t->minimize(); break;
        case 4: _t->save_clicked(); break;
        case 5: _t->load_clicked(); break;
        case 6: _t->save_as_clicked(); break;
        case 7: _t->new_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->new_tab_left_bar(); break;
        case 9: _t->change_name((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 10: _t->remove_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Main_window::*)(bool , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_window::save)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Main_window::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Main_window::change_block_state)) {
                *result = 1;
                return;
            }
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
, QtPrivate::TypeAndForceComplete<Main_window, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Main_window::save(bool _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Main_window::change_block_state(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
