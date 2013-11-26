/****************************************************************************
** Meta object code from reading C++ file 'debugwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Tracking/debugwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'debugwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DebugWindow_t {
    QByteArrayData data[18];
    char stringdata[447];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_DebugWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_DebugWindow_t qt_meta_stringdata_DebugWindow = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 25),
QT_MOC_LITERAL(2, 38, 0),
QT_MOC_LITERAL(3, 39, 5),
QT_MOC_LITERAL(4, 45, 25),
QT_MOC_LITERAL(5, 71, 25),
QT_MOC_LITERAL(6, 97, 29),
QT_MOC_LITERAL(7, 127, 23),
QT_MOC_LITERAL(8, 151, 22),
QT_MOC_LITERAL(9, 174, 34),
QT_MOC_LITERAL(10, 209, 26),
QT_MOC_LITERAL(11, 236, 26),
QT_MOC_LITERAL(12, 263, 30),
QT_MOC_LITERAL(13, 294, 27),
QT_MOC_LITERAL(14, 322, 25),
QT_MOC_LITERAL(15, 348, 37),
QT_MOC_LITERAL(16, 386, 24),
QT_MOC_LITERAL(17, 411, 34)
    },
    "DebugWindow\0on_sliMinima_valueChanged\0"
    "\0value\0on_sliMaxima_valueChanged\0"
    "on_sliFactor_valueChanged\0"
    "on_sliThreashold_valueChanged\0"
    "on_sliNear_valueChanged\0on_sliFar_valueChanged\0"
    "on_sliDepthThreashold_valueChanged\0"
    "on_sliMinSize_valueChanged\0"
    "on_sliArmSize_valueChanged\0"
    "on_actionDepth_Image_triggered\0"
    "on_actionVelocity_triggered\0"
    "on_actionBinary_triggered\0"
    "on_actionBinary_Depth_image_triggered\0"
    "on_actionColor_triggered\0"
    "on_actionPlayer_Overview_triggered\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DebugWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x08,
       4,    1,   92,    2, 0x08,
       5,    1,   95,    2, 0x08,
       6,    1,   98,    2, 0x08,
       7,    1,  101,    2, 0x08,
       8,    1,  104,    2, 0x08,
       9,    1,  107,    2, 0x08,
      10,    1,  110,    2, 0x08,
      11,    1,  113,    2, 0x08,
      12,    0,  116,    2, 0x08,
      13,    0,  117,    2, 0x08,
      14,    0,  118,    2, 0x08,
      15,    0,  119,    2, 0x08,
      16,    0,  120,    2, 0x08,
      17,    0,  121,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DebugWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DebugWindow *_t = static_cast<DebugWindow *>(_o);
        switch (_id) {
        case 0: _t->on_sliMinima_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_sliMaxima_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_sliFactor_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_sliThreashold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_sliNear_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_sliFar_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_sliDepthThreashold_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sliMinSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_sliArmSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_actionDepth_Image_triggered(); break;
        case 10: _t->on_actionVelocity_triggered(); break;
        case 11: _t->on_actionBinary_triggered(); break;
        case 12: _t->on_actionBinary_Depth_image_triggered(); break;
        case 13: _t->on_actionColor_triggered(); break;
        case 14: _t->on_actionPlayer_Overview_triggered(); break;
        default: ;
        }
    }
}

const QMetaObject DebugWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DebugWindow.data,
      qt_meta_data_DebugWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *DebugWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DebugWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DebugWindow.stringdata))
        return static_cast<void*>(const_cast< DebugWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DebugWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
