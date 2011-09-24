/****************************************************************************
** Meta object code from reading C++ file 'tgbutton.h'
**
** Created: Mon 7. Jun 22:47:42 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tgbutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tgbutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TGbutton[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x05,
      25,    9,    9,    9, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_TGbutton[] = {
    "TGbutton\0\0rightClicked()\0doubleClicked()\0"
};

const QMetaObject TGbutton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_TGbutton,
      qt_meta_data_TGbutton, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TGbutton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TGbutton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TGbutton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TGbutton))
        return static_cast<void*>(const_cast< TGbutton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int TGbutton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: rightClicked(); break;
        case 1: doubleClicked(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void TGbutton::rightClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void TGbutton::doubleClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
