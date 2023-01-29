/****************************************************************************
** Meta object code from reading C++ file 'result_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Neural_network_Designer/result_widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'result_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Result_widget_t {
    const uint offsetsAndSize[28];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Result_widget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Result_widget_t qt_meta_stringdata_Result_widget = {
    {
QT_MOC_LITERAL(0, 13), // "Result_widget"
QT_MOC_LITERAL(14, 11), // "change_name"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 2), // "id"
QT_MOC_LITERAL(30, 4), // "name"
QT_MOC_LITERAL(35, 6), // "redraw"
QT_MOC_LITERAL(42, 18), // "change_block_state"
QT_MOC_LITERAL(61, 5), // "state"
QT_MOC_LITERAL(67, 9), // "calculate"
QT_MOC_LITERAL(77, 8), // "download"
QT_MOC_LITERAL(86, 12), // "save_process"
QT_MOC_LITERAL(99, 2), // "as"
QT_MOC_LITERAL(102, 5), // "index"
QT_MOC_LITERAL(108, 16) // "change_blockator"

    },
    "Result_widget\0change_name\0\0id\0name\0"
    "redraw\0change_block_state\0state\0"
    "calculate\0download\0save_process\0as\0"
    "index\0change_blockator"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Result_widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   56,    2, 0x06,    1 /* Public */,
       5,    0,   61,    2, 0x06,    4 /* Public */,
       6,    1,   62,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,   65,    2, 0x08,    7 /* Private */,
       9,    0,   66,    2, 0x08,    8 /* Private */,
      10,    2,   67,    2, 0x08,    9 /* Private */,
      13,    1,   72,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int,   11,   12,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void Result_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Result_widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->change_name((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->redraw(); break;
        case 2: _t->change_block_state((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->calculate(); break;
        case 4: _t->download(); break;
        case 5: _t->save_process((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->change_blockator((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Result_widget::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Result_widget::change_name)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Result_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Result_widget::redraw)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Result_widget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Result_widget::change_block_state)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Result_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Result_widget.offsetsAndSize,
    qt_meta_data_Result_widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Result_widget_t
, QtPrivate::TypeAndForceComplete<Result_widget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Result_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Result_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Result_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Result_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Result_widget::change_name(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Result_widget::redraw()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Result_widget::change_block_state(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
