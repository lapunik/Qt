/****************************************************************************
** Meta object code from reading C++ file 'new_person_dialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../BirthdayWindowDesigner/new_person_dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'new_person_dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_New_person_dialog_t {
    const uint offsetsAndSize[22];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_New_person_dialog_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_New_person_dialog_t qt_meta_stringdata_New_person_dialog = {
    {
QT_MOC_LITERAL(0, 17), // "New_person_dialog"
QT_MOC_LITERAL(18, 34), // "on_calendarWidget_selectionCh..."
QT_MOC_LITERAL(53, 0), // ""
QT_MOC_LITERAL(54, 23), // "on_dateEdit_dateChanged"
QT_MOC_LITERAL(78, 4), // "date"
QT_MOC_LITERAL(83, 23), // "on_button_close_clicked"
QT_MOC_LITERAL(107, 20), // "on_button_OK_clicked"
QT_MOC_LITERAL(128, 23), // "on_edit_day_textChanged"
QT_MOC_LITERAL(152, 4), // "arg1"
QT_MOC_LITERAL(157, 25), // "on_edit_month_textChanged"
QT_MOC_LITERAL(183, 24) // "on_edit_year_textChanged"

    },
    "New_person_dialog\0on_calendarWidget_selectionChanged\0"
    "\0on_dateEdit_dateChanged\0date\0"
    "on_button_close_clicked\0on_button_OK_clicked\0"
    "on_edit_day_textChanged\0arg1\0"
    "on_edit_month_textChanged\0"
    "on_edit_year_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_New_person_dialog[] = {

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
       3,    1,   57,    2, 0x08,    2 /* Private */,
       5,    0,   60,    2, 0x08,    4 /* Private */,
       6,    0,   61,    2, 0x08,    5 /* Private */,
       7,    1,   62,    2, 0x08,    6 /* Private */,
       9,    1,   65,    2, 0x08,    8 /* Private */,
      10,    1,   68,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDate,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void New_person_dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<New_person_dialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_calendarWidget_selectionChanged(); break;
        case 1: _t->on_dateEdit_dateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: _t->on_button_close_clicked(); break;
        case 3: _t->on_button_OK_clicked(); break;
        case 4: _t->on_edit_day_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_edit_month_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_edit_year_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject New_person_dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_New_person_dialog.offsetsAndSize,
    qt_meta_data_New_person_dialog,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_New_person_dialog_t
, QtPrivate::TypeAndForceComplete<New_person_dialog, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *New_person_dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *New_person_dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_New_person_dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int New_person_dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
