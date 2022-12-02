/****************************************************************************
** Meta object code from reading C++ file 'results_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Neural_network_Designer/results_widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'results_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Results_widget_t {
    const uint offsetsAndSize[38];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Results_widget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Results_widget_t qt_meta_stringdata_Results_widget = {
    {
QT_MOC_LITERAL(0, 14), // "Results_widget"
QT_MOC_LITERAL(15, 4), // "save"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 16), // "download_clicked"
QT_MOC_LITERAL(38, 11), // "all_clicked"
QT_MOC_LITERAL(50, 12), // "best_clicked"
QT_MOC_LITERAL(63, 14), // "parret_clicked"
QT_MOC_LITERAL(78, 15), // "reg_mse_clicked"
QT_MOC_LITERAL(94, 17), // "reg_NonZC_clicked"
QT_MOC_LITERAL(112, 13), // "arrow_clicked"
QT_MOC_LITERAL(126, 14), // "arrowl_clicked"
QT_MOC_LITERAL(141, 19), // "arrow_input_clicked"
QT_MOC_LITERAL(161, 20), // "arrowl_input_clicked"
QT_MOC_LITERAL(182, 19), // "best_button_clicked"
QT_MOC_LITERAL(202, 10), // "load_model"
QT_MOC_LITERAL(213, 21), // "Neural_network_model*"
QT_MOC_LITERAL(235, 8), // "nn_model"
QT_MOC_LITERAL(244, 16), // "change_blockator"
QT_MOC_LITERAL(261, 5) // "state"

    },
    "Results_widget\0save\0\0download_clicked\0"
    "all_clicked\0best_clicked\0parret_clicked\0"
    "reg_mse_clicked\0reg_NonZC_clicked\0"
    "arrow_clicked\0arrowl_clicked\0"
    "arrow_input_clicked\0arrowl_input_clicked\0"
    "best_button_clicked\0load_model\0"
    "Neural_network_model*\0nn_model\0"
    "change_blockator\0state"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Results_widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   99,    2, 0x08,    2 /* Private */,
       4,    0,  100,    2, 0x08,    3 /* Private */,
       5,    0,  101,    2, 0x08,    4 /* Private */,
       6,    0,  102,    2, 0x08,    5 /* Private */,
       7,    0,  103,    2, 0x08,    6 /* Private */,
       8,    0,  104,    2, 0x08,    7 /* Private */,
       9,    0,  105,    2, 0x08,    8 /* Private */,
      10,    0,  106,    2, 0x08,    9 /* Private */,
      11,    0,  107,    2, 0x08,   10 /* Private */,
      12,    0,  108,    2, 0x08,   11 /* Private */,
      13,    0,  109,    2, 0x08,   12 /* Private */,
      14,    1,  110,    2, 0x0a,   13 /* Public */,
      17,    1,  113,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void Results_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Results_widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->save(); break;
        case 1: _t->download_clicked(); break;
        case 2: _t->all_clicked(); break;
        case 3: _t->best_clicked(); break;
        case 4: _t->parret_clicked(); break;
        case 5: _t->reg_mse_clicked(); break;
        case 6: _t->reg_NonZC_clicked(); break;
        case 7: _t->arrow_clicked(); break;
        case 8: _t->arrowl_clicked(); break;
        case 9: _t->arrow_input_clicked(); break;
        case 10: _t->arrowl_input_clicked(); break;
        case 11: _t->best_button_clicked(); break;
        case 12: _t->load_model((*reinterpret_cast< Neural_network_model*(*)>(_a[1]))); break;
        case 13: _t->change_blockator((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 12:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Neural_network_model* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Results_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Results_widget::save)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Results_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Results_widget.offsetsAndSize,
    qt_meta_data_Results_widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Results_widget_t
, QtPrivate::TypeAndForceComplete<Results_widget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Neural_network_model *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>


>,
    nullptr
} };


const QMetaObject *Results_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Results_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Results_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Results_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Results_widget::save()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
