/****************************************************************************
** Meta object code from reading C++ file 'visualiser.h'
**
** Created: Tue Feb 26 23:24:43 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "visualiser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'visualiser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Visualiser[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,   11,   11,   11, 0x08,
      58,   11,   11,   11, 0x08,
      82,   11,   11,   11, 0x08,
     105,   11,   11,   11, 0x08,
     140,  129,   11,   11, 0x08,
     174,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Visualiser[] = {
    "Visualiser\0\0missing_process()\0"
    "on_priorityButton_clicked()\0"
    "on_stopButton_clicked()\0on_endButton_clicked()\0"
    "on_killButton_clicked()\0row,column\0"
    "on_infoTable_cellChanged(int,int)\0"
    "kill_confirm_accepted()\0process_not_found()\0"
};

const QMetaObject Visualiser::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Visualiser,
      qt_meta_data_Visualiser, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Visualiser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Visualiser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Visualiser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Visualiser))
        return static_cast<void*>(const_cast< Visualiser*>(this));
    return QDialog::qt_metacast(_clname);
}

int Visualiser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: missing_process(); break;
        case 1: on_priorityButton_clicked(); break;
        case 2: on_stopButton_clicked(); break;
        case 3: on_endButton_clicked(); break;
        case 4: on_killButton_clicked(); break;
        case 5: on_infoTable_cellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: kill_confirm_accepted(); break;
        case 7: process_not_found(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Visualiser::missing_process()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
