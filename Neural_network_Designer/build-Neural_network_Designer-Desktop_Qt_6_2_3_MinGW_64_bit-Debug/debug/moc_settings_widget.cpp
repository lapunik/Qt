/****************************************************************************
** Meta object code from reading C++ file 'settings_widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Neural_network_Designer/settings_widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settings_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Settings_widget_t {
    const uint offsetsAndSize[20];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Settings_widget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Settings_widget_t qt_meta_stringdata_Settings_widget = {
    {
QT_MOC_LITERAL(0, 15), // "Settings_widget"
QT_MOC_LITERAL(16, 9), // "calculate"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 25), // "input_data_button_clicked"
QT_MOC_LITERAL(53, 24), // "stochastic_check_clicked"
QT_MOC_LITERAL(78, 5), // "state"
QT_MOC_LITERAL(84, 28), // "max_iterations_check_clicked"
QT_MOC_LITERAL(113, 23), // "tolerance_check_clicked"
QT_MOC_LITERAL(137, 28), // "regularization_check_clicked"
QT_MOC_LITERAL(166, 24) // "calculate_button_clicked"

    },
    "Settings_widget\0calculate\0\0"
    "input_data_button_clicked\0"
    "stochastic_check_clicked\0state\0"
    "max_iterations_check_clicked\0"
    "tolerance_check_clicked\0"
    "regularization_check_clicked\0"
    "calculate_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Settings_widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   57,    2, 0x08,    2 /* Private */,
       4,    1,   58,    2, 0x08,    3 /* Private */,
       6,    1,   61,    2, 0x08,    5 /* Private */,
       7,    1,   64,    2, 0x08,    7 /* Private */,
       8,    1,   67,    2, 0x08,    9 /* Private */,
       9,    0,   70,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void Settings_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Settings_widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->calculate(); break;
        case 1: _t->input_data_button_clicked(); break;
        case 2: _t->stochastic_check_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->max_iterations_check_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->tolerance_check_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->regularization_check_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->calculate_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Settings_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Settings_widget::calculate)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Settings_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Settings_widget.offsetsAndSize,
    qt_meta_data_Settings_widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Settings_widget_t
, QtPrivate::TypeAndForceComplete<Settings_widget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Settings_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Settings_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Settings_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Settings_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void Settings_widget::calculate()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
