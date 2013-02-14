/****************************************************************************
** Meta object code from reading C++ file 'simulatorinit.h'
**
** Created: Wed Feb 13 23:13:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simulatorinit.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulatorinit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimulatorInit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      41,   14,   14,   14, 0x08,
      69,   14,   14,   14, 0x08,
      95,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimulatorInit[] = {
    "SimulatorInit\0\0on_cancelButton_clicked()\0"
    "on_continueButton_clicked()\0"
    "on_browseButton_clicked()\0file_selected()\0"
};

void SimulatorInit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimulatorInit *_t = static_cast<SimulatorInit *>(_o);
        switch (_id) {
        case 0: _t->on_cancelButton_clicked(); break;
        case 1: _t->on_continueButton_clicked(); break;
        case 2: _t->on_browseButton_clicked(); break;
        case 3: _t->file_selected(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData SimulatorInit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimulatorInit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SimulatorInit,
      qt_meta_data_SimulatorInit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimulatorInit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimulatorInit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimulatorInit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimulatorInit))
        return static_cast<void*>(const_cast< SimulatorInit*>(this));
    return QDialog::qt_metacast(_clname);
}

int SimulatorInit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
