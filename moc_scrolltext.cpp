/****************************************************************************
** Meta object code from reading C++ file 'scrolltext.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "scrolltext.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scrolltext.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ScrollText_t {
    QByteArrayData data[7];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ScrollText_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ScrollText_t qt_meta_stringdata_ScrollText = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ScrollText"
QT_MOC_LITERAL(1, 11, 4), // "text"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 7), // "setText"
QT_MOC_LITERAL(4, 25, 9), // "separator"
QT_MOC_LITERAL(5, 35, 12), // "setSeparator"
QT_MOC_LITERAL(6, 48, 13) // "timer_timeout"

    },
    "ScrollText\0text\0\0setText\0separator\0"
    "setSeparator\0timer_timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ScrollText[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    1,   40,    2, 0x0a /* Public */,
       4,    0,   43,    2, 0x0a /* Public */,
       5,    1,   44,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    1,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,

 // properties: name, type, flags
       1, QMetaType::QString, 0x00095103,
       4, QMetaType::QString, 0x00095103,

       0        // eod
};

void ScrollText::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ScrollText *_t = static_cast<ScrollText *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->text();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->setText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: { QString _r = _t->separator();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->setSeparator((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->timer_timeout(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        ScrollText *_t = static_cast<ScrollText *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->text(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->separator(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        ScrollText *_t = static_cast<ScrollText *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setText(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setSeparator(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

const QMetaObject ScrollText::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ScrollText.data,
      qt_meta_data_ScrollText,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ScrollText::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ScrollText::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ScrollText.stringdata0))
        return static_cast<void*>(const_cast< ScrollText*>(this));
    return QWidget::qt_metacast(_clname);
}

int ScrollText::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
