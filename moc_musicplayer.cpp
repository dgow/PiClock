/****************************************************************************
** Meta object code from reading C++ file 'musicplayer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "musicplayer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicplayer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicPlayer_t {
    QByteArrayData data[20];
    char stringdata0[262];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicPlayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicPlayer_t qt_meta_stringdata_MusicPlayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MusicPlayer"
QT_MOC_LITERAL(1, 12, 6), // "GoBack"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 11), // "SongChanged"
QT_MOC_LITERAL(4, 32, 12), // "StateChanged"
QT_MOC_LITERAL(5, 45, 19), // "on_okButton_clicked"
QT_MOC_LITERAL(6, 65, 25), // "on_chillOutButton_clicked"
QT_MOC_LITERAL(7, 91, 20), // "on_HDMButton_clicked"
QT_MOC_LITERAL(8, 112, 22), // "on_lightButton_clicked"
QT_MOC_LITERAL(9, 135, 8), // "VolumeUp"
QT_MOC_LITERAL(10, 144, 10), // "VolumeDown"
QT_MOC_LITERAL(11, 155, 4), // "Mute"
QT_MOC_LITERAL(12, 160, 4), // "Stop"
QT_MOC_LITERAL(13, 165, 8), // "NextSong"
QT_MOC_LITERAL(14, 174, 8), // "PrevSong"
QT_MOC_LITERAL(15, 183, 12), // "StartProcess"
QT_MOC_LITERAL(16, 196, 7), // "command"
QT_MOC_LITERAL(17, 204, 10), // "argsString"
QT_MOC_LITERAL(18, 215, 21), // "on_gongButton_clicked"
QT_MOC_LITERAL(19, 237, 24) // "on_mixTapeButton_clicked"

    },
    "MusicPlayer\0GoBack\0\0SongChanged\0"
    "StateChanged\0on_okButton_clicked\0"
    "on_chillOutButton_clicked\0"
    "on_HDMButton_clicked\0on_lightButton_clicked\0"
    "VolumeUp\0VolumeDown\0Mute\0Stop\0NextSong\0"
    "PrevSong\0StartProcess\0command\0argsString\0"
    "on_gongButton_clicked\0on_mixTapeButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicPlayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    0,   96,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    0,   99,    2, 0x0a /* Public */,
       8,    0,  100,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    0,  105,    2, 0x0a /* Public */,
      14,    0,  106,    2, 0x0a /* Public */,
      15,    2,  107,    2, 0x0a /* Public */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   17,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MusicPlayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicPlayer *_t = static_cast<MusicPlayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->GoBack(); break;
        case 1: _t->SongChanged(); break;
        case 2: _t->StateChanged(); break;
        case 3: _t->on_okButton_clicked(); break;
        case 4: _t->on_chillOutButton_clicked(); break;
        case 5: _t->on_HDMButton_clicked(); break;
        case 6: _t->on_lightButton_clicked(); break;
        case 7: _t->VolumeUp(); break;
        case 8: _t->VolumeDown(); break;
        case 9: _t->Mute(); break;
        case 10: _t->Stop(); break;
        case 11: _t->NextSong(); break;
        case 12: _t->PrevSong(); break;
        case 13: _t->StartProcess((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 14: _t->on_gongButton_clicked(); break;
        case 15: _t->on_mixTapeButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MusicPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::GoBack)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MusicPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::SongChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MusicPlayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MusicPlayer::StateChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject MusicPlayer::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MusicPlayer.data,
      qt_meta_data_MusicPlayer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MusicPlayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPlayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicPlayer.stringdata0))
        return static_cast<void*>(const_cast< MusicPlayer*>(this));
    return QWidget::qt_metacast(_clname);
}

int MusicPlayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MusicPlayer::GoBack()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicPlayer::SongChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MusicPlayer::StateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
