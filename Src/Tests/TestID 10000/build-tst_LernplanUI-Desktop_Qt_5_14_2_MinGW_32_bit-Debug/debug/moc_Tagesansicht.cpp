/****************************************************************************
** Meta object code from reading C++ file 'Tagesansicht.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../team6/Produkt/Tests/TestID 10000/Test_Mainwindow/StartseiteStudikalender/Tagesansicht.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Tagesansicht.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tagesansicht_t {
    QByteArrayData data[15];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tagesansicht_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tagesansicht_t qt_meta_stringdata_Tagesansicht = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Tagesansicht"
QT_MOC_LITERAL(1, 13, 11), // "MyTimerSlot"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 23), // "on_neuer_Termin_clicked"
QT_MOC_LITERAL(4, 50, 22), // "on_tag_zurueck_clicked"
QT_MOC_LITERAL(5, 73, 18), // "on_tag_vor_clicked"
QT_MOC_LITERAL(6, 92, 18), // "on_faecher_clicked"
QT_MOC_LITERAL(7, 111, 17), // "on_profil_clicked"
QT_MOC_LITERAL(8, 129, 29), // "on_ansicht_currentTextChanged"
QT_MOC_LITERAL(9, 159, 26), // "on_tableView_doubleClicked"
QT_MOC_LITERAL(10, 186, 11), // "QModelIndex"
QT_MOC_LITERAL(11, 198, 5), // "index"
QT_MOC_LITERAL(12, 204, 19), // "on_Lernplan_clicked"
QT_MOC_LITERAL(13, 224, 15), // "on_exit_clicked"
QT_MOC_LITERAL(14, 240, 19) // "on_abmelden_clicked"

    },
    "Tagesansicht\0MyTimerSlot\0\0"
    "on_neuer_Termin_clicked\0on_tag_zurueck_clicked\0"
    "on_tag_vor_clicked\0on_faecher_clicked\0"
    "on_profil_clicked\0on_ansicht_currentTextChanged\0"
    "on_tableView_doubleClicked\0QModelIndex\0"
    "index\0on_Lernplan_clicked\0on_exit_clicked\0"
    "on_abmelden_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tagesansicht[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x0a /* Public */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,
      13,    0,   80,    2, 0x08 /* Private */,
      14,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Tagesansicht::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Tagesansicht *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->MyTimerSlot(); break;
        case 1: _t->on_neuer_Termin_clicked(); break;
        case 2: _t->on_tag_zurueck_clicked(); break;
        case 3: _t->on_tag_vor_clicked(); break;
        case 4: _t->on_faecher_clicked(); break;
        case 5: _t->on_profil_clicked(); break;
        case 6: _t->on_ansicht_currentTextChanged(); break;
        case 7: _t->on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_Lernplan_clicked(); break;
        case 9: _t->on_exit_clicked(); break;
        case 10: _t->on_abmelden_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tagesansicht::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Tagesansicht.data,
    qt_meta_data_Tagesansicht,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Tagesansicht::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tagesansicht::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tagesansicht.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Tagesansicht::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
