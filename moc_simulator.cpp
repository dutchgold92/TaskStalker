/****************************************************************************
** Meta object code from reading C++ file 'simulator.h'
**
** Created: Sun Feb 10 20:10:39 2013
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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      29,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   10,   10,   10, 0x08,
      79,   68,   10,   10, 0x08,
     113,   10,   10,   10, 0x08,
     141,   10,   10,   10, 0x08,
     165,   10,   10,   10, 0x08,
     189,   10,   10,   10, 0x08,
     214,   10,   10,   10, 0x08,
     234,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Simulator[] = {
    "Simulator\0\0missing_process()\0"
    "start_program()\0on_endButton_clicked()\0"
    "row,column\0on_infoTable_cellChanged(int,int)\0"
    "on_priorityButton_clicked()\0"
    "on_stopButton_clicked()\0on_killButton_clicked()\0"
    "on_closeButton_clicked()\0process_not_found()\0"
    "program_started()\0"
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
        case 0: missing_process(); break;
        case 1: start_program(); break;
        case 2: on_endButton_clicked(); break;
        case 3: on_infoTable_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: on_priorityButton_clicked(); break;
        case 5: on_stopButton_clicked(); break;
        case 6: on_killButton_clicked(); break;
        case 7: on_closeButton_clicked(); break;
        case 8: process_not_found(); break;
        case 9: program_started(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Simulator::missing_process()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Simulator::start_program()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
