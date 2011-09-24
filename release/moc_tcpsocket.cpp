/****************************************************************************
** Meta object code from reading C++ file 'tcpsocket.h'
**
** Created: Tue 8. Jun 13:24:50 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tcpsocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tcpsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TcpSocket[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   10,   10,   10, 0x08,
      56,   11,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TcpSocket[] = {
    "TcpSocket\0\0,,\0updateSocks(QString,int,int)\0"
    "readClient()\0updateOne(QString,int,int)\0"
};

const QMetaObject TcpSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_TcpSocket,
      qt_meta_data_TcpSocket, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TcpSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TcpSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TcpSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TcpSocket))
        return static_cast<void*>(const_cast< TcpSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int TcpSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: updateSocks((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: readClient(); break;
        case 2: updateOne((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void TcpSocket::updateSocks(QString _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
