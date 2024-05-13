/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[40];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 13), // "onNextClicked"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 13), // "onPlayClicked"
QT_MOC_LITERAL(40, 13), // "onSkipClicked"
QT_MOC_LITERAL(54, 13), // "onCardClicked"
QT_MOC_LITERAL(68, 4), // "Card"
QT_MOC_LITERAL(73, 4), // "card"
QT_MOC_LITERAL(78, 12), // "CustomLabel*"
QT_MOC_LITERAL(91, 5), // "label"
QT_MOC_LITERAL(97, 16), // "onRestartClicked"
QT_MOC_LITERAL(114, 11), // "clearLayout"
QT_MOC_LITERAL(126, 8), // "QLayout*"
QT_MOC_LITERAL(135, 6), // "layout"
QT_MOC_LITERAL(142, 11), // "renderCards"
QT_MOC_LITERAL(154, 6), // "Player"
QT_MOC_LITERAL(161, 6), // "player"
QT_MOC_LITERAL(168, 13), // "onSwapClicked"
QT_MOC_LITERAL(182, 13), // "onSortByValue"
QT_MOC_LITERAL(196, 13) // "onSortByGroup"

    },
    "MainWindow\0onNextClicked\0\0onPlayClicked\0"
    "onSkipClicked\0onCardClicked\0Card\0card\0"
    "CustomLabel*\0label\0onRestartClicked\0"
    "clearLayout\0QLayout*\0layout\0renderCards\0"
    "Player\0player\0onSwapClicked\0onSortByValue\0"
    "onSortByGroup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   80,    2, 0x0a,    1 /* Public */,
       3,    0,   81,    2, 0x0a,    2 /* Public */,
       4,    0,   82,    2, 0x0a,    3 /* Public */,
       5,    2,   83,    2, 0x0a,    4 /* Public */,
      10,    0,   88,    2, 0x0a,    7 /* Public */,
      11,    1,   89,    2, 0x0a,    8 /* Public */,
      14,    0,   92,    2, 0x0a,   10 /* Public */,
      14,    1,   93,    2, 0x0a,   11 /* Public */,
      17,    0,   96,    2, 0x0a,   13 /* Public */,
      18,    0,   97,    2, 0x0a,   14 /* Public */,
      19,    0,   98,    2, 0x0a,   15 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6, 0x80000000 | 8,    7,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onNextClicked(); break;
        case 1: _t->onPlayClicked(); break;
        case 2: _t->onSkipClicked(); break;
        case 3: _t->onCardClicked((*reinterpret_cast< std::add_pointer_t<Card>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<CustomLabel*>>(_a[2]))); break;
        case 4: _t->onRestartClicked(); break;
        case 5: _t->clearLayout((*reinterpret_cast< std::add_pointer_t<QLayout*>>(_a[1]))); break;
        case 6: _t->renderCards(); break;
        case 7: _t->renderCards((*reinterpret_cast< std::add_pointer_t<Player>>(_a[1]))); break;
        case 8: _t->onSwapClicked(); break;
        case 9: _t->onSortByValue(); break;
        case 10: _t->onSortByGroup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< CustomLabel* >(); break;
            }
            break;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Card, std::false_type>, QtPrivate::TypeAndForceComplete<CustomLabel * const, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QLayout *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Player, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
