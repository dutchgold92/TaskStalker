/****************************************************************************
** Meta object code from reading C++ file 'errordialog.h'
**
** Created: Thu Feb 21 20:08:17 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "errordialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'errordialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ErrorDialog[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ErrorDialog[] = {
    "ErrorDialog\0\0on_dismissButton_clicked()\0"
};

const QMetaObject ErrorDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ErrorDialog,
      qt_meta_data_ErrorDialog, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ErrorDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ErrorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ErrorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ErrorDialog))
        return static_cast<void*>(const_cast< ErrorDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int ErrorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_dismissButton_clicked(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
