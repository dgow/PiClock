/****************************************************************************
** Meta object code from reading C++ file 'mopidyreader.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mopidyreader.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mopidyreader.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MopidyReader_t {
    QByteArrayData data[19];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MopidyReader_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MopidyReader_t qt_meta_stringdata_MopidyReader = {
    {
QT_MOC_LITERAL(0, 0, 12), // "MopidyReader"
QT_MOC_LITERAL(1, 13, 11), // "DataChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10), // "UpdateSong"
QT_MOC_LITERAL(4, 37, 11), // "UpdateState"
QT_MOC_LITERAL(5, 49, 14), // "UpdatePosition"
QT_MOC_LITERAL(6, 64, 12), // "onDisconnect"
QT_MOC_LITERAL(7, 77, 7), // "Connect"
QT_MOC_LITERAL(8, 85, 7), // "onError"
QT_MOC_LITERAL(9, 93, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(10, 122, 5), // "error"
QT_MOC_LITERAL(11, 128, 7), // "openUrl"
QT_MOC_LITERAL(12, 136, 9), // "MessageId"
QT_MOC_LITERAL(13, 146, 4), // "Play"
QT_MOC_LITERAL(14, 151, 4), // "Next"
QT_MOC_LITERAL(15, 156, 4), // "Prev"
QT_MOC_LITERAL(16, 161, 8), // "Position"
QT_MOC_LITERAL(17, 170, 13), // "ClearPlaylist"
QT_MOC_LITERAL(18, 184, 6) // "Random"

    },
    "MopidyReader\0DataChanged\0\0UpdateSong\0"
    "UpdateState\0UpdatePosition\0onDisconnect\0"
    "Connect\0onError\0QAbstractSocket::SocketError\0"
    "error\0openUrl\0MessageId\0Play\0Next\0"
    "Prev\0Position\0ClearPlaylist\0Random"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MopidyReader[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       1,   64, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   55,    2, 0x0a /* Public */,
       4,    0,   56,    2, 0x0a /* Public */,
       5,    0,   57,    2, 0x0a /* Public */,
       6,    0,   58,    2, 0x0a /* Public */,
       7,    0,   59,    2, 0x0a /* Public */,
       8,    1,   60,    2, 0x0a /* Public */,
      11,    0,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

 // enums: name, flags, count, data
      12, 0x0,    6,   68,

 // enum data: key, value
      13, uint(MopidyReader::Play),
      14, uint(MopidyReader::Next),
      15, uint(MopidyReader::Prev),
      16, uint(MopidyReader::Position),
      17, uint(MopidyReader::ClearPlaylist),
      18, uint(MopidyReader::Random),

       0        // eod
};

void MopidyReader::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MopidyReader *_t = static_cast<MopidyReader *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->DataChanged(); break;
        case 1: _t->UpdateSong(); break;
        case 2: _t->UpdateState(); break;
        case 3: _t->UpdatePosition(); break;
        case 4: _t->onDisconnect(); break;
        case 5: _t->Connect(); break;
        case 6: _t->onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->openUrl(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MopidyReader::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MopidyReader::DataChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MopidyReader::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MopidyReader.data,
      qt_meta_data_MopidyReader,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MopidyReader::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MopidyReader::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MopidyReader.stringdata0))
        return static_cast<void*>(const_cast< MopidyReader*>(this));
    return QObject::qt_metacast(_clname);
}

int MopidyReader::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MopidyReader::DataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
