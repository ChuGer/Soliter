/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 8. Jun 13:24:46 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   12,   11,   11, 0x08,
      50,   43,   11,   11, 0x08,
     124,   11,   11,   11, 0x08,
     141,   11,   11,   11, 0x08,
     154,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     171,   11,   11,   11, 0x08,
     188,   11,   11,   11, 0x08,
     197,   11,   11,   11, 0x08,
     203,   11,   11,   11, 0x08,
     213,   11,   11,   11, 0x08,
     227,   11,   11,   11, 0x08,
     243,   12,   11,   11, 0x08,
     271,   12,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0,,\0createNewField(int,int,int)\0"
    "mat,,,\0"
    "createNewField(QList<QList<int> >,int,QStringList,QList<QPair<int,int>"
    " >)\0"
    "createNewField()\0createGame()\0GameOver()\0"
    "Win()\0updateMines(int)\0center()\0res()\0"
    "newGame()\0startServer()\0connectServer()\0"
    "sendClient(QString,int,int)\0"
    "doClick(QString,int,int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: createNewField((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: createNewField((*reinterpret_cast< QList<QList<int> >(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])),(*reinterpret_cast< QList<QPair<int,int> >(*)>(_a[4]))); break;
        case 2: createNewField(); break;
        case 3: createGame(); break;
        case 4: GameOver(); break;
        case 5: Win(); break;
        case 6: updateMines((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: center(); break;
        case 8: res(); break;
        case 9: newGame(); break;
        case 10: startServer(); break;
        case 11: connectServer(); break;
        case 12: sendClient((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: doClick((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
