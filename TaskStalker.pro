# -------------------------------------------------
# Project created by QtCreator 2012-11-13T19:29:10
# -------------------------------------------------

TARGET = TaskStalker
TEMPLATE = app
QT += svg widgets
DESTDIR = bin
OBJECTS_DIR = bin/out/objects
MOC_DIR = bin/out/moc
RCC_DIR = bin/out/rcc
UI_DIR = bin/out/ui

SOURCES += \
    src/main/cpp/main.cpp \
    src/main/cpp/core/proc.cpp \
    src/main/cpp/core/sys.cpp \
    src/main/cpp/gui/confirmdialog.cpp \
    src/main/cpp/gui/errordialog.cpp \
    src/main/cpp/gui/info.cpp \
    src/main/cpp/gui/mainwindow.cpp \
    src/main/cpp/gui/selectrecording.cpp \
    src/main/cpp/gui/settings.cpp \
    src/main/cpp/gui/simulatorinit.cpp \
    src/main/cpp/gui/systeminfo.cpp \
    src/main/cpp/gui/qgraphicsprocessitem.cpp \
    src/main/cpp/gui/qtablewidgetcpuusageitem.cpp \
    src/main/cpp/gui/viewprocessor.cpp \
    src/main/cpp/gui/viewprocessorinit.cpp \
    src/main/cpp/gui/viewrunning.cpp \
    src/main/cpp/gui/visualiser.cpp

HEADERS += \
    include/main/cpp/core/proc.h \
    include/main/cpp/core/sys.h \
    include/main/cpp/gui/confirmdialog.h \
    include/main/cpp/gui/errordialog.h \
    include/main/cpp/gui/info.h \
    include/main/cpp/gui/mainwindow.h \
    include/main/cpp/gui/qgraphicsprocessitem.h \
    include/main/cpp/gui/qtablewidgetcpuusageitem.h \
    include/main/cpp/gui/selectrecording.h \
    include/main/cpp/gui/settings.h \
    include/main/cpp/gui/simulatorinit.h \
    include/main/cpp/gui/systeminfo.h \
    include/main/cpp/gui/viewprocessor.h \
    include/main/cpp/gui/viewprocessorinit.h \
    include/main/cpp/gui/viewrunning.h \
    include/main/cpp/gui/visualiser.h

FORMS += \
    ui/confirmdialog.ui \
    ui/errordialog.ui \
    ui/info.ui \
    ui/mainwindow.ui \
    ui/selectrecording.ui \
    ui/settings.ui \
    ui/simulator.ui \
    ui/simulatorinit.ui \
    ui/systeminfo.ui \
    ui/viewprocessor.ui \
    ui/viewprocessorinit.ui \
    ui/viewrunning.ui \
    ui/visualiser.ui

RESOURCES = \
    resources/help.qrc \
    resources/images.qrc
