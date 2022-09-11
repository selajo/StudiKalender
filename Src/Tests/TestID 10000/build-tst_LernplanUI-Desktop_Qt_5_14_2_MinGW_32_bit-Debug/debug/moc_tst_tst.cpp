/****************************************************************************
** Meta object code from reading C++ file 'tst_tst.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../team6/Produkt/Tests/TestID 10000/Test_Mainwindow/tst_tst.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tst_tst.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_tst_t {
    QByteArrayData data[10];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tst_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tst_t qt_meta_stringdata_tst = {
    {
QT_MOC_LITERAL(0, 0, 3), // "tst"
QT_MOC_LITERAL(1, 4, 16), // "Felder_Leer10067"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 16), // "Felder_Leer10068"
QT_MOC_LITERAL(4, 39, 16), // "Felder_Leer10069"
QT_MOC_LITERAL(5, 56, 16), // "Felder_Leer10070"
QT_MOC_LITERAL(6, 73, 16), // "Felder_Leer10071"
QT_MOC_LITERAL(7, 90, 16), // "Felder_Leer10072"
QT_MOC_LITERAL(8, 107, 23), // "Felder_ausgefuellt10066"
QT_MOC_LITERAL(9, 131, 7) // "TimeOut"

    },
    "tst\0Felder_Leer10067\0\0Felder_Leer10068\0"
    "Felder_Leer10069\0Felder_Leer10070\0"
    "Felder_Leer10071\0Felder_Leer10072\0"
    "Felder_ausgefuellt10066\0TimeOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tst[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void tst::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tst *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Felder_Leer10067(); break;
        case 1: _t->Felder_Leer10068(); break;
        case 2: _t->Felder_Leer10069(); break;
        case 3: _t->Felder_Leer10070(); break;
        case 4: _t->Felder_Leer10071(); break;
        case 5: _t->Felder_Leer10072(); break;
        case 6: _t->Felder_ausgefuellt10066(); break;
        case 7: _t->TimeOut(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject tst::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_tst.data,
    qt_meta_data_tst,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tst::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tst::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tst.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int tst::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
