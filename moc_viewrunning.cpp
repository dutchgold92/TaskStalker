/****************************************************************************
** Meta object code from reading C++ file 'viewrunning.h'
**
** Created: Wed Feb 6 22:39:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "viewrunning.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewrunning.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewRunning[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,   12,   12,   12, 0x08,
      69,   12,   12,   12, 0x08,
      89,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ViewRunning[] = {
    "ViewRunning\0\0update_string_updated()\0"
    "on_toggleUpdateButton_clicked()\0"
    "update_outputArea()\0on_closeButton_clicked()\0"
};

void ViewRunning::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewRunning *_t = static_cast<ViewRunning *>(_o);
        switch (_id) {
        case 0: _t->update_string_updated(); break;
        case 1: _t->on_toggleUpdateButton_clicked(); break;
        case 2: _t->update_outputArea(); break;
        case 3: _t->on_closeButton_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ViewRunning::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewRunning::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ViewRunning,
      qt_meta_data_ViewRunning, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewRunning::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewRunning::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewRunning::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewRunning))
        return static_cast<void*>(const_cast< ViewRunning*>(this));
    return QDialog::qt_metacast(_clname);
}

int ViewRunning::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void ViewRunning::update_string_updated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
