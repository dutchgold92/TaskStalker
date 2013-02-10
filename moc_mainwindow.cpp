/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Feb 10 21:18:57 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   11,   11,   11, 0x08,
      56,   11,   11,   11, 0x08,
      99,   88,   11,   11, 0x08,
     139,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     204,   11,   11,   11, 0x08,
     231,   11,   11,   11, 0x08,
     257,   11,   11,   11, 0x08,
     288,  281,   11,   11, 0x08,
     310,   11,   11,   11, 0x08,
     388,  336,   11,   11, 0x08,
     437,   11,   11,   11, 0x08,
     463,   11,   11,   11, 0x08,
     491,   11,   11,   11, 0x08,
     522,   11,   11,   11, 0x08,
     548,   11,   11,   11, 0x08,
     588,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0updated(bool)\0"
    "on_actionSettings_triggered()\0"
    "on_toggleUpdateButton_clicked()\0"
    "row,column\0on_procTable_cellDoubleClicked(int,int)\0"
    "on_actionSimulate_triggered()\0"
    "on_actionDocumentation_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_actionQuit_triggered()\0"
    "procTable_updated(bool)\0column\0"
    "procTable_sorted(int)\0on_actionView_triggered()\0"
    "currentRow,currentColumn,previousRow,previousColumn\0"
    "on_procTable_currentCellChanged(int,int,int,int)\0"
    "on_actionStop_triggered()\0"
    "on_actionResume_triggered()\0"
    "on_actionTerminate_triggered()\0"
    "on_actionKill_triggered()\0"
    "on_actionSystem_Information_triggered()\0"
    "on_actionRunning_Processes_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_actionSettings_triggered(); break;
        case 2: _t->on_toggleUpdateButton_clicked(); break;
        case 3: _t->on_procTable_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->on_actionSimulate_triggered(); break;
        case 5: _t->on_actionDocumentation_triggered(); break;
        case 6: _t->on_actionAbout_triggered(); break;
        case 7: _t->on_actionQuit_triggered(); break;
        case 8: _t->procTable_updated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->procTable_sorted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_actionView_triggered(); break;
        case 11: _t->on_procTable_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 12: _t->on_actionStop_triggered(); break;
        case 13: _t->on_actionResume_triggered(); break;
        case 14: _t->on_actionTerminate_triggered(); break;
        case 15: _t->on_actionKill_triggered(); break;
        case 16: _t->on_actionSystem_Information_triggered(); break;
        case 17: _t->on_actionRunning_Processes_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::updated(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
