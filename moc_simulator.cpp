/****************************************************************************
** Meta object code from reading C++ file 'simulator.h'
**
** Created: Wed Jan 9 22:01:54 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simulator.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Simulator[] = {

 // content:
       6,       // revision
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

void Simulator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Simulator *_t = static_cast<Simulator *>(_o);
        switch (_id) {
        case 0: _t->missing_process(); break;
        case 1: _t->start_program(); break;
        case 2: _t->on_endButton_clicked(); break;
        case 3: _t->on_infoTable_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_priorityButton_clicked(); break;
        case 5: _t->on_stopButton_clicked(); break;
        case 6: _t->on_killButton_clicked(); break;
        case 7: _t->on_closeButton_clicked(); break;
        case 8: _t->process_not_found(); break;
        case 9: _t->program_started(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Simulator::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Simulator::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Simulator,
      qt_meta_data_Simulator, &staticMetaObjectExtraData }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
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
