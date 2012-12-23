/****************************************************************************
** Meta object code from reading C++ file 'simulator.h'
**
** Created: Thu Dec 20 23:41:55 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simulator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Simulator[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   11,   10,   10, 0x08,
      56,   10,   10,   10, 0x08,
      84,   10,   10,   10, 0x08,
     108,   10,   10,   10, 0x08,
     132,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Simulator[] = {
    "Simulator\0\0row,column\0"
    "on_infoTable_cellChanged(int,int)\0"
    "on_priorityButton_clicked()\0"
    "on_stopButton_clicked()\0on_killButton_clicked()\0"
    "on_closeButton_clicked()\0"
};

const QMetaObject Simulator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Simulator,
      qt_meta_data_Simulator, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Simulator::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Simulator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Simulator::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Simulator))
        return static_cast<void*>(const_cast< Simulator*>(this));
    return QDialog::qt_metacast(_clname);
}

int Simulator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_infoTable_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: on_priorityButton_clicked(); break;
        case 2: on_stopButton_clicked(); break;
        case 3: on_killButton_clicked(); break;
        case 4: on_closeButton_clicked(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
