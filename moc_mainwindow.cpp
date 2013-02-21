/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Feb 21 20:08:07 2013
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
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
     627,   11,   11,   11, 0x08,
     667,   11,   11,   11, 0x08,

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
    "on_actionProcessor_Activity_triggered()\0"
    "kill_confirmed()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
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
        switch (_id) {
        case 0: updated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: on_actionSettings_triggered(); break;
        case 2: on_toggleUpdateButton_clicked(); break;
        case 3: on_procTable_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: on_actionSimulate_triggered(); break;
        case 5: on_actionDocumentation_triggered(); break;
        case 6: on_actionAbout_triggered(); break;
        case 7: on_actionQuit_triggered(); break;
        case 8: procTable_updated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: procTable_sorted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: on_actionView_triggered(); break;
        case 11: on_procTable_currentCellChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 12: on_actionStop_triggered(); break;
        case 13: on_actionResume_triggered(); break;
        case 14: on_actionTerminate_triggered(); break;
        case 15: on_actionKill_triggered(); break;
        case 16: on_actionSystem_Information_triggered(); break;
        case 17: on_actionRunning_Processes_triggered(); break;
        case 18: on_actionProcessor_Activity_triggered(); break;
        case 19: kill_confirmed(); break;
        default: ;
        }
        _id -= 20;
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
