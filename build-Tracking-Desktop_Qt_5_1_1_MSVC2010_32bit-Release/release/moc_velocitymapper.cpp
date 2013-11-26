/****************************************************************************
** Meta object code from reading C++ file 'velocitymapper.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tracking/velocitymapper.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'velocitymapper.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_VelocityMapper_t {
    QByteArrayData data[12];
    char stringdata[106];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_VelocityMapper_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_VelocityMapper_t qt_meta_stringdata_VelocityMapper = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 9),
QT_MOC_LITERAL(2, 25, 0),
QT_MOC_LITERAL(3, 26, 6),
QT_MOC_LITERAL(4, 33, 9),
QT_MOC_LITERAL(5, 43, 6),
QT_MOC_LITERAL(6, 50, 9),
QT_MOC_LITERAL(7, 60, 6),
QT_MOC_LITERAL(8, 67, 14),
QT_MOC_LITERAL(9, 82, 6),
QT_MOC_LITERAL(10, 89, 13),
QT_MOC_LITERAL(11, 103, 1)
    },
    "VelocityMapper\0setMinima\0\0minima\0"
    "setMaxima\0maxima\0setFactor\0factor\0"
    "setForwardOnly\0fwOnly\0setThreashold\0"
    "t\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_VelocityMapper[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a,
       4,    1,   42,    2, 0x0a,
       6,    1,   45,    2, 0x0a,
       8,    1,   48,    2, 0x0a,
      10,    1,   51,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Float,   11,

       0        // eod
};

void VelocityMapper::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        VelocityMapper *_t = static_cast<VelocityMapper *>(_o);
        switch (_id) {
        case 0: _t->setMinima((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->setMaxima((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->setFactor((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->setForwardOnly((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setThreashold((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject VelocityMapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_VelocityMapper.data,
      qt_meta_data_VelocityMapper,  qt_static_metacall, 0, 0}
};


const QMetaObject *VelocityMapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *VelocityMapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VelocityMapper.stringdata))
        return static_cast<void*>(const_cast< VelocityMapper*>(this));
    return QObject::qt_metacast(_clname);
}

int VelocityMapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
