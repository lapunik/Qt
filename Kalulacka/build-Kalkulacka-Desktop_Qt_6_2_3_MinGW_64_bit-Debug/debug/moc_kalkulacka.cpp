/****************************************************************************
** Meta object code from reading C++ file 'kalkulacka.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Kalkulacka/kalkulacka.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'kalkulacka.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Kalkulacka_t {
    const uint offsetsAndSize[30];
    char stringdata0[145];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Kalkulacka_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Kalkulacka_t qt_meta_stringdata_Kalkulacka = {
    {
QT_MOC_LITERAL(0, 10), // "Kalkulacka"
QT_MOC_LITERAL(11, 14), // "number_too_big"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 7), // "set_add"
QT_MOC_LITERAL(35, 7), // "set_sub"
QT_MOC_LITERAL(43, 7), // "set_mlp"
QT_MOC_LITERAL(51, 7), // "set_div"
QT_MOC_LITERAL(59, 7), // "set_dec"
QT_MOC_LITERAL(67, 7), // "set_bin"
QT_MOC_LITERAL(75, 7), // "set_hex"
QT_MOC_LITERAL(83, 7), // "set_oct"
QT_MOC_LITERAL(91, 13), // "get_false_num"
QT_MOC_LITERAL(105, 13), // "Model::number"
QT_MOC_LITERAL(119, 15), // "get_zero_divide"
QT_MOC_LITERAL(135, 9) // "calculate"

    },
    "Kalkulacka\0number_too_big\0\0set_add\0"
    "set_sub\0set_mlp\0set_div\0set_dec\0set_bin\0"
    "set_hex\0set_oct\0get_false_num\0"
    "Model::number\0get_zero_divide\0calculate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Kalkulacka[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x0a,    1 /* Public */,
       3,    0,   87,    2, 0x0a,    2 /* Public */,
       4,    0,   88,    2, 0x0a,    3 /* Public */,
       5,    0,   89,    2, 0x0a,    4 /* Public */,
       6,    0,   90,    2, 0x0a,    5 /* Public */,
       7,    0,   91,    2, 0x0a,    6 /* Public */,
       8,    0,   92,    2, 0x0a,    7 /* Public */,
       9,    0,   93,    2, 0x0a,    8 /* Public */,
      10,    0,   94,    2, 0x0a,    9 /* Public */,
      11,    1,   95,    2, 0x0a,   10 /* Public */,
      13,    0,   98,    2, 0x0a,   12 /* Public */,
      14,    0,   99,    2, 0x0a,   13 /* Public */,

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
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Kalkulacka::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Kalkulacka *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->number_too_big(); break;
        case 1: _t->set_add(); break;
        case 2: _t->set_sub(); break;
        case 3: _t->set_mlp(); break;
        case 4: _t->set_div(); break;
        case 5: _t->set_dec(); break;
        case 6: _t->set_bin(); break;
        case 7: _t->set_hex(); break;
        case 8: _t->set_oct(); break;
        case 9: _t->get_false_num((*reinterpret_cast< Model::number(*)>(_a[1]))); break;
        case 10: _t->get_zero_divide(); break;
        case 11: _t->calculate(); break;
        default: ;
        }
    }
}

const QMetaObject Kalkulacka::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Kalkulacka.offsetsAndSize,
    qt_meta_data_Kalkulacka,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Kalkulacka_t
, QtPrivate::TypeAndForceComplete<Kalkulacka, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Model::number, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Kalkulacka::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Kalkulacka::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Kalkulacka.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Kalkulacka::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
