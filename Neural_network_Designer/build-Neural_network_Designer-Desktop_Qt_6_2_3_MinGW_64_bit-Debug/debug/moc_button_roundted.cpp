/****************************************************************************
** Meta object code from reading C++ file 'button_roundted.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Neural_network_Designer/button_roundted.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'button_roundted.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Button_roundted_t {
    const uint offsetsAndSize[14];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Button_roundted_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Button_roundted_t qt_meta_stringdata_Button_roundted = {
    {
QT_MOC_LITERAL(0, 15), // "Button_roundted"
QT_MOC_LITERAL(16, 21), // "double_clicked_signal"
QT_MOC_LITERAL(38, 0), // ""
QT_MOC_LITERAL(39, 10), // "get_redraw"
QT_MOC_LITERAL(50, 6), // "redraw"
QT_MOC_LITERAL(57, 10), // "set_redraw"
QT_MOC_LITERAL(68, 8) // "diameter"

    },
    "Button_roundted\0double_clicked_signal\0"
    "\0get_redraw\0redraw\0set_redraw\0diameter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Button_roundted[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   39,    2, 0x0a,    2 /* Public */,
       4,    0,   40,    2, 0x0a,    3 /* Public */,
       5,    1,   41,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void Button_roundted::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Button_roundted *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->double_clicked_signal(); break;
        case 1: { int _r = _t->get_redraw();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->redraw(); break;
        case 3: _t->set_redraw((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Button_roundted::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Button_roundted::double_clicked_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Button_roundted::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Button_roundted.offsetsAndSize,
    qt_meta_data_Button_roundted,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Button_roundted_t
, QtPrivate::TypeAndForceComplete<Button_roundted, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Button_roundted::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Button_roundted::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Button_roundted.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Button_roundted::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Button_roundted::double_clicked_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
