#############################################################################
# Makefile for building: bin/TaskStalker
# Generated by qmake (2.01a) (Qt 4.8.6) on: Sat Mar 12 16:39:32 2016
# Project:  TaskStalker.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -o Makefile TaskStalker.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_SVG_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4/QtSvg -I/usr/include/qt4 -Ibin/out/moc -Ibin/out/ui
LINK          = g++
LFLAGS        = -m64
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtSvg -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = bin/out/objects/

####### Files

SOURCES       = src/main/cpp/main.cpp \
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
		src/main/cpp/gui/visualiser.cpp bin/out/moc/moc_confirmdialog.cpp \
		bin/out/moc/moc_errordialog.cpp \
		bin/out/moc/moc_info.cpp \
		bin/out/moc/moc_mainwindow.cpp \
		bin/out/moc/moc_selectrecording.cpp \
		bin/out/moc/moc_settings.cpp \
		bin/out/moc/moc_simulatorinit.cpp \
		bin/out/moc/moc_systeminfo.cpp \
		bin/out/moc/moc_viewprocessor.cpp \
		bin/out/moc/moc_viewprocessorinit.cpp \
		bin/out/moc/moc_viewrunning.cpp \
		bin/out/moc/moc_visualiser.cpp \
		bin/out/rcc/qrc_help.cpp \
		bin/out/rcc/qrc_images.cpp
OBJECTS       = bin/out/objects/main.o \
		bin/out/objects/proc.o \
		bin/out/objects/sys.o \
		bin/out/objects/confirmdialog.o \
		bin/out/objects/errordialog.o \
		bin/out/objects/info.o \
		bin/out/objects/mainwindow.o \
		bin/out/objects/selectrecording.o \
		bin/out/objects/settings.o \
		bin/out/objects/simulatorinit.o \
		bin/out/objects/systeminfo.o \
		bin/out/objects/qgraphicsprocessitem.o \
		bin/out/objects/qtablewidgetcpuusageitem.o \
		bin/out/objects/viewprocessor.o \
		bin/out/objects/viewprocessorinit.o \
		bin/out/objects/viewrunning.o \
		bin/out/objects/visualiser.o \
		bin/out/objects/moc_confirmdialog.o \
		bin/out/objects/moc_errordialog.o \
		bin/out/objects/moc_info.o \
		bin/out/objects/moc_mainwindow.o \
		bin/out/objects/moc_selectrecording.o \
		bin/out/objects/moc_settings.o \
		bin/out/objects/moc_simulatorinit.o \
		bin/out/objects/moc_systeminfo.o \
		bin/out/objects/moc_viewprocessor.o \
		bin/out/objects/moc_viewprocessorinit.o \
		bin/out/objects/moc_viewrunning.o \
		bin/out/objects/moc_visualiser.o \
		bin/out/objects/qrc_help.o \
		bin/out/objects/qrc_images.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		TaskStalker.pro
QMAKE_TARGET  = TaskStalker
DESTDIR       = bin/
TARGET        = bin/TaskStalker

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): bin/out/ui/ui_confirmdialog.h bin/out/ui/ui_errordialog.h bin/out/ui/ui_info.h bin/out/ui/ui_mainwindow.h bin/out/ui/ui_selectrecording.h bin/out/ui/ui_settings.h bin/out/ui/ui_simulator.h bin/out/ui/ui_simulatorinit.h bin/out/ui/ui_systeminfo.h bin/out/ui/ui_viewprocessor.h bin/out/ui/ui_viewprocessorinit.h bin/out/ui/ui_viewrunning.h bin/out/ui/ui_visualiser.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9][^0-9]*\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: TaskStalker.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/x86_64-linux-gnu/libQtSvg.prl \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -o Makefile TaskStalker.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/x86_64-linux-gnu/libQtSvg.prl:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++-64 CONFIG+=debug -o Makefile TaskStalker.pro

dist: 
	@$(CHK_DIR_EXISTS) bin/out/objects/TaskStalker1.0.0 || $(MKDIR) bin/out/objects/TaskStalker1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) bin/out/objects/TaskStalker1.0.0/ && $(COPY_FILE) --parents include/main/cpp/core/proc.h include/main/cpp/core/sys.h include/main/cpp/gui/confirmdialog.h include/main/cpp/gui/errordialog.h include/main/cpp/gui/info.h include/main/cpp/gui/mainwindow.h include/main/cpp/gui/qgraphicsprocessitem.h include/main/cpp/gui/qtablewidgetcpuusageitem.h include/main/cpp/gui/selectrecording.h include/main/cpp/gui/settings.h include/main/cpp/gui/simulatorinit.h include/main/cpp/gui/systeminfo.h include/main/cpp/gui/viewprocessor.h include/main/cpp/gui/viewprocessorinit.h include/main/cpp/gui/viewrunning.h include/main/cpp/gui/visualiser.h bin/out/objects/TaskStalker1.0.0/ && $(COPY_FILE) --parents resources/help.qrc resources/images.qrc bin/out/objects/TaskStalker1.0.0/ && $(COPY_FILE) --parents src/main/cpp/main.cpp src/main/cpp/core/proc.cpp src/main/cpp/core/sys.cpp src/main/cpp/gui/confirmdialog.cpp src/main/cpp/gui/errordialog.cpp src/main/cpp/gui/info.cpp src/main/cpp/gui/mainwindow.cpp src/main/cpp/gui/selectrecording.cpp src/main/cpp/gui/settings.cpp src/main/cpp/gui/simulatorinit.cpp src/main/cpp/gui/systeminfo.cpp src/main/cpp/gui/qgraphicsprocessitem.cpp src/main/cpp/gui/qtablewidgetcpuusageitem.cpp src/main/cpp/gui/viewprocessor.cpp src/main/cpp/gui/viewprocessorinit.cpp src/main/cpp/gui/viewrunning.cpp src/main/cpp/gui/visualiser.cpp bin/out/objects/TaskStalker1.0.0/ && $(COPY_FILE) --parents ui/confirmdialog.ui ui/errordialog.ui ui/info.ui ui/mainwindow.ui ui/selectrecording.ui ui/settings.ui ui/simulator.ui ui/simulatorinit.ui ui/systeminfo.ui ui/viewprocessor.ui ui/viewprocessorinit.ui ui/viewrunning.ui ui/visualiser.ui bin/out/objects/TaskStalker1.0.0/ && (cd `dirname bin/out/objects/TaskStalker1.0.0` && $(TAR) TaskStalker1.0.0.tar TaskStalker1.0.0 && $(COMPRESS) TaskStalker1.0.0.tar) && $(MOVE) `dirname bin/out/objects/TaskStalker1.0.0`/TaskStalker1.0.0.tar.gz . && $(DEL_FILE) -r bin/out/objects/TaskStalker1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: bin/out/moc/moc_confirmdialog.cpp bin/out/moc/moc_errordialog.cpp bin/out/moc/moc_info.cpp bin/out/moc/moc_mainwindow.cpp bin/out/moc/moc_selectrecording.cpp bin/out/moc/moc_settings.cpp bin/out/moc/moc_simulatorinit.cpp bin/out/moc/moc_systeminfo.cpp bin/out/moc/moc_viewprocessor.cpp bin/out/moc/moc_viewprocessorinit.cpp bin/out/moc/moc_viewrunning.cpp bin/out/moc/moc_visualiser.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) bin/out/moc/moc_confirmdialog.cpp bin/out/moc/moc_errordialog.cpp bin/out/moc/moc_info.cpp bin/out/moc/moc_mainwindow.cpp bin/out/moc/moc_selectrecording.cpp bin/out/moc/moc_settings.cpp bin/out/moc/moc_simulatorinit.cpp bin/out/moc/moc_systeminfo.cpp bin/out/moc/moc_viewprocessor.cpp bin/out/moc/moc_viewprocessorinit.cpp bin/out/moc/moc_viewrunning.cpp bin/out/moc/moc_visualiser.cpp
bin/out/moc/moc_confirmdialog.cpp: include/main/cpp/gui/confirmdialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/confirmdialog.h -o bin/out/moc/moc_confirmdialog.cpp

bin/out/moc/moc_errordialog.cpp: include/main/cpp/gui/errordialog.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/errordialog.h -o bin/out/moc/moc_errordialog.cpp

bin/out/moc/moc_info.cpp: include/main/cpp/gui/info.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/info.h -o bin/out/moc/moc_info.cpp

bin/out/moc/moc_mainwindow.cpp: include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/info.h \
		include/main/cpp/gui/simulatorinit.h \
		include/main/cpp/gui/settings.h \
		include/main/cpp/gui/viewrunning.h \
		include/main/cpp/gui/systeminfo.h \
		include/main/cpp/gui/viewprocessorinit.h \
		include/main/cpp/gui/viewprocessor.h \
		include/main/cpp/gui/qgraphicsprocessitem.h \
		include/main/cpp/gui/selectrecording.h \
		include/main/cpp/gui/mainwindow.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/mainwindow.h -o bin/out/moc/moc_mainwindow.cpp

bin/out/moc/moc_selectrecording.cpp: include/main/cpp/gui/visualiser.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/selectrecording.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/selectrecording.h -o bin/out/moc/moc_selectrecording.cpp

bin/out/moc/moc_settings.cpp: include/main/cpp/core/sys.h \
		include/main/cpp/gui/settings.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/settings.h -o bin/out/moc/moc_settings.cpp

bin/out/moc/moc_simulatorinit.cpp: include/main/cpp/gui/visualiser.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/simulatorinit.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/simulatorinit.h -o bin/out/moc/moc_simulatorinit.cpp

bin/out/moc/moc_systeminfo.cpp: include/main/cpp/core/proc.h \
		include/main/cpp/gui/systeminfo.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/systeminfo.h -o bin/out/moc/moc_systeminfo.cpp

bin/out/moc/moc_viewprocessor.cpp: include/main/cpp/core/sys.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/qgraphicsprocessitem.h \
		include/main/cpp/gui/viewprocessor.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/viewprocessor.h -o bin/out/moc/moc_viewprocessor.cpp

bin/out/moc/moc_viewprocessorinit.cpp: include/main/cpp/gui/viewprocessor.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/qgraphicsprocessitem.h \
		include/main/cpp/gui/viewprocessorinit.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/viewprocessorinit.h -o bin/out/moc/moc_viewprocessorinit.cpp

bin/out/moc/moc_viewrunning.cpp: include/main/cpp/core/sys.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/viewrunning.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/viewrunning.h -o bin/out/moc/moc_viewrunning.cpp

bin/out/moc/moc_visualiser.cpp: include/main/cpp/core/proc.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/visualiser.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) include/main/cpp/gui/visualiser.h -o bin/out/moc/moc_visualiser.cpp

compiler_rcc_make_all: bin/out/rcc/qrc_help.cpp bin/out/rcc/qrc_images.cpp
compiler_rcc_clean:
	-$(DEL_FILE) bin/out/rcc/qrc_help.cpp bin/out/rcc/qrc_images.cpp
bin/out/rcc/qrc_help.cpp: resources/help.qrc \
		resources/doc/collection.qhc \
		resources/doc/viewprocessorinit.png \
		resources/doc/viswindow.png \
		resources/doc/viewprocessor.png \
		resources/doc/recording.png \
		resources/doc/info.html \
		resources/doc/viewprocessor.html \
		resources/doc/style.css \
		resources/doc/index.html \
		resources/doc/main.html \
		resources/doc/recording.html \
		resources/doc/runningprocs.png \
		resources/doc/sysinfo.png \
		resources/doc/settings.png \
		resources/doc/simulator.html \
		resources/doc/settings.html \
		resources/doc/help.qch \
		resources/doc/simulatorinit.png \
		resources/doc/runningprocs.html \
		resources/doc/initrecording.png \
		resources/doc/sysinfo.html \
		resources/doc/visualisation.html \
		resources/doc/mainwindow.png
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name help resources/help.qrc -o bin/out/rcc/qrc_help.cpp

bin/out/rcc/qrc_images.cpp: resources/images.qrc \
		resources/img/button_pause.png \
		resources/img/button_play.png \
		resources/img/stop.png \
		resources/img/logo.png \
		resources/img/resume.png \
		resources/img/ready.svg \
		resources/img/icon.png \
		resources/img/kill.png \
		resources/img/running.svg \
		resources/img/executing.svg \
		resources/img/unknown.svg \
		resources/img/view.png \
		resources/img/uninterruptible.svg \
		resources/img/stopped.svg \
		resources/img/terminate.png \
		resources/img/interruptible.svg \
		resources/img/zombie.svg
	/usr/lib/x86_64-linux-gnu/qt4/bin/rcc -name images resources/images.qrc -o bin/out/rcc/qrc_images.cpp

compiler_image_collection_make_all: bin/out/ui/qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) bin/out/ui/qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: bin/out/ui/ui_confirmdialog.h bin/out/ui/ui_errordialog.h bin/out/ui/ui_info.h bin/out/ui/ui_mainwindow.h bin/out/ui/ui_selectrecording.h bin/out/ui/ui_settings.h bin/out/ui/ui_simulator.h bin/out/ui/ui_simulatorinit.h bin/out/ui/ui_systeminfo.h bin/out/ui/ui_viewprocessor.h bin/out/ui/ui_viewprocessorinit.h bin/out/ui/ui_viewrunning.h bin/out/ui/ui_visualiser.h
compiler_uic_clean:
	-$(DEL_FILE) bin/out/ui/ui_confirmdialog.h bin/out/ui/ui_errordialog.h bin/out/ui/ui_info.h bin/out/ui/ui_mainwindow.h bin/out/ui/ui_selectrecording.h bin/out/ui/ui_settings.h bin/out/ui/ui_simulator.h bin/out/ui/ui_simulatorinit.h bin/out/ui/ui_systeminfo.h bin/out/ui/ui_viewprocessor.h bin/out/ui/ui_viewprocessorinit.h bin/out/ui/ui_viewrunning.h bin/out/ui/ui_visualiser.h
bin/out/ui/ui_confirmdialog.h: ui/confirmdialog.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/confirmdialog.ui -o bin/out/ui/ui_confirmdialog.h

bin/out/ui/ui_errordialog.h: ui/errordialog.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/errordialog.ui -o bin/out/ui/ui_errordialog.h

bin/out/ui/ui_info.h: ui/info.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/info.ui -o bin/out/ui/ui_info.h

bin/out/ui/ui_mainwindow.h: ui/mainwindow.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/mainwindow.ui -o bin/out/ui/ui_mainwindow.h

bin/out/ui/ui_selectrecording.h: ui/selectrecording.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/selectrecording.ui -o bin/out/ui/ui_selectrecording.h

bin/out/ui/ui_settings.h: ui/settings.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/settings.ui -o bin/out/ui/ui_settings.h

bin/out/ui/ui_simulator.h: ui/simulator.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/simulator.ui -o bin/out/ui/ui_simulator.h

bin/out/ui/ui_simulatorinit.h: ui/simulatorinit.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/simulatorinit.ui -o bin/out/ui/ui_simulatorinit.h

bin/out/ui/ui_systeminfo.h: ui/systeminfo.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/systeminfo.ui -o bin/out/ui/ui_systeminfo.h

bin/out/ui/ui_viewprocessor.h: ui/viewprocessor.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/viewprocessor.ui -o bin/out/ui/ui_viewprocessor.h

bin/out/ui/ui_viewprocessorinit.h: ui/viewprocessorinit.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/viewprocessorinit.ui -o bin/out/ui/ui_viewprocessorinit.h

bin/out/ui/ui_viewrunning.h: ui/viewrunning.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/viewrunning.ui -o bin/out/ui/ui_viewrunning.h

bin/out/ui/ui_visualiser.h: ui/visualiser.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic ui/visualiser.ui -o bin/out/ui/ui_visualiser.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

bin/out/objects/main.o: src/main/cpp/main.cpp include/main/cpp/gui/mainwindow.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/info.h \
		include/main/cpp/gui/simulatorinit.h \
		include/main/cpp/gui/settings.h \
		include/main/cpp/gui/viewrunning.h \
		include/main/cpp/gui/systeminfo.h \
		include/main/cpp/gui/viewprocessorinit.h \
		include/main/cpp/gui/viewprocessor.h \
		include/main/cpp/gui/qgraphicsprocessitem.h \
		include/main/cpp/gui/selectrecording.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/main.o src/main/cpp/main.cpp

bin/out/objects/proc.o: src/main/cpp/core/proc.cpp include/main/cpp/core/proc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/proc.o src/main/cpp/core/proc.cpp

bin/out/objects/sys.o: src/main/cpp/core/sys.cpp include/main/cpp/core/sys.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/sys.o src/main/cpp/core/sys.cpp

bin/out/objects/confirmdialog.o: src/main/cpp/gui/confirmdialog.cpp include/main/cpp/gui/confirmdialog.h \
		bin/out/ui/ui_confirmdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/confirmdialog.o src/main/cpp/gui/confirmdialog.cpp

bin/out/objects/errordialog.o: src/main/cpp/gui/errordialog.cpp include/main/cpp/gui/errordialog.h \
		bin/out/ui/ui_errordialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/errordialog.o src/main/cpp/gui/errordialog.cpp

bin/out/objects/info.o: src/main/cpp/gui/info.cpp include/main/cpp/gui/info.h \
		bin/out/ui/ui_info.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/info.o src/main/cpp/gui/info.cpp

bin/out/objects/mainwindow.o: src/main/cpp/gui/mainwindow.cpp include/main/cpp/gui/mainwindow.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/info.h \
		include/main/cpp/gui/simulatorinit.h \
		include/main/cpp/gui/settings.h \
		include/main/cpp/gui/viewrunning.h \
		include/main/cpp/gui/systeminfo.h \
		include/main/cpp/gui/viewprocessorinit.h \
		include/main/cpp/gui/viewprocessor.h \
		include/main/cpp/gui/qgraphicsprocessitem.h \
		include/main/cpp/gui/selectrecording.h \
		bin/out/ui/ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/mainwindow.o src/main/cpp/gui/mainwindow.cpp

bin/out/objects/selectrecording.o: src/main/cpp/gui/selectrecording.cpp include/main/cpp/gui/selectrecording.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		bin/out/ui/ui_selectrecording.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/selectrecording.o src/main/cpp/gui/selectrecording.cpp

bin/out/objects/settings.o: src/main/cpp/gui/settings.cpp include/main/cpp/gui/settings.h \
		include/main/cpp/core/sys.h \
		bin/out/ui/ui_settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/settings.o src/main/cpp/gui/settings.cpp

bin/out/objects/simulatorinit.o: src/main/cpp/gui/simulatorinit.cpp include/main/cpp/gui/simulatorinit.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		bin/out/ui/ui_simulatorinit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/simulatorinit.o src/main/cpp/gui/simulatorinit.cpp

bin/out/objects/systeminfo.o: src/main/cpp/gui/systeminfo.cpp include/main/cpp/gui/systeminfo.h \
		include/main/cpp/core/proc.h \
		bin/out/ui/ui_systeminfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/systeminfo.o src/main/cpp/gui/systeminfo.cpp

bin/out/objects/qgraphicsprocessitem.o: src/main/cpp/gui/qgraphicsprocessitem.cpp include/main/cpp/gui/qgraphicsprocessitem.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/qgraphicsprocessitem.o src/main/cpp/gui/qgraphicsprocessitem.cpp

bin/out/objects/qtablewidgetcpuusageitem.o: src/main/cpp/gui/qtablewidgetcpuusageitem.cpp include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/core/proc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/qtablewidgetcpuusageitem.o src/main/cpp/gui/qtablewidgetcpuusageitem.cpp

bin/out/objects/viewprocessor.o: src/main/cpp/gui/viewprocessor.cpp include/main/cpp/gui/viewprocessor.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/qgraphicsprocessitem.h \
		bin/out/ui/ui_viewprocessor.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/viewprocessor.o src/main/cpp/gui/viewprocessor.cpp

bin/out/objects/viewprocessorinit.o: src/main/cpp/gui/viewprocessorinit.cpp include/main/cpp/gui/viewprocessorinit.h \
		include/main/cpp/gui/viewprocessor.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		include/main/cpp/gui/qgraphicsprocessitem.h \
		bin/out/ui/ui_viewprocessorinit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/viewprocessorinit.o src/main/cpp/gui/viewprocessorinit.cpp

bin/out/objects/viewrunning.o: src/main/cpp/gui/viewrunning.cpp include/main/cpp/gui/viewrunning.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/visualiser.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		bin/out/ui/ui_viewrunning.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/viewrunning.o src/main/cpp/gui/viewrunning.cpp

bin/out/objects/visualiser.o: src/main/cpp/gui/visualiser.cpp include/main/cpp/gui/visualiser.h \
		include/main/cpp/core/proc.h \
		include/main/cpp/gui/confirmdialog.h \
		include/main/cpp/core/sys.h \
		include/main/cpp/gui/errordialog.h \
		include/main/cpp/gui/qtablewidgetcpuusageitem.h \
		bin/out/ui/ui_visualiser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/visualiser.o src/main/cpp/gui/visualiser.cpp

bin/out/objects/moc_confirmdialog.o: bin/out/moc/moc_confirmdialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_confirmdialog.o bin/out/moc/moc_confirmdialog.cpp

bin/out/objects/moc_errordialog.o: bin/out/moc/moc_errordialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_errordialog.o bin/out/moc/moc_errordialog.cpp

bin/out/objects/moc_info.o: bin/out/moc/moc_info.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_info.o bin/out/moc/moc_info.cpp

bin/out/objects/moc_mainwindow.o: bin/out/moc/moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_mainwindow.o bin/out/moc/moc_mainwindow.cpp

bin/out/objects/moc_selectrecording.o: bin/out/moc/moc_selectrecording.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_selectrecording.o bin/out/moc/moc_selectrecording.cpp

bin/out/objects/moc_settings.o: bin/out/moc/moc_settings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_settings.o bin/out/moc/moc_settings.cpp

bin/out/objects/moc_simulatorinit.o: bin/out/moc/moc_simulatorinit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_simulatorinit.o bin/out/moc/moc_simulatorinit.cpp

bin/out/objects/moc_systeminfo.o: bin/out/moc/moc_systeminfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_systeminfo.o bin/out/moc/moc_systeminfo.cpp

bin/out/objects/moc_viewprocessor.o: bin/out/moc/moc_viewprocessor.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_viewprocessor.o bin/out/moc/moc_viewprocessor.cpp

bin/out/objects/moc_viewprocessorinit.o: bin/out/moc/moc_viewprocessorinit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_viewprocessorinit.o bin/out/moc/moc_viewprocessorinit.cpp

bin/out/objects/moc_viewrunning.o: bin/out/moc/moc_viewrunning.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_viewrunning.o bin/out/moc/moc_viewrunning.cpp

bin/out/objects/moc_visualiser.o: bin/out/moc/moc_visualiser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/moc_visualiser.o bin/out/moc/moc_visualiser.cpp

bin/out/objects/qrc_help.o: bin/out/rcc/qrc_help.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/qrc_help.o bin/out/rcc/qrc_help.cpp

bin/out/objects/qrc_images.o: bin/out/rcc/qrc_images.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o bin/out/objects/qrc_images.o bin/out/rcc/qrc_images.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

