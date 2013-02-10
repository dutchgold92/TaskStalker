#############################################################################
# Makefile for building: TaskStalker
# Generated by qmake (2.01a) (Qt 4.8.2) on: Sun Feb 10 20:34:40 2013
# Project:  TaskStalker.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile TaskStalker.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
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

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		proc.cpp \
		visualiser.cpp \
		confirmkill.cpp \
		info.cpp \
		simulatorinit.cpp \
		sys.cpp \
		settings.cpp \
		errordialog.cpp \
		viewrunning.cpp \
		systeminfo.cpp moc_mainwindow.cpp \
		moc_visualiser.cpp \
		moc_confirmkill.cpp \
		moc_info.cpp \
		moc_simulatorinit.cpp \
		moc_settings.cpp \
		moc_errordialog.cpp \
		moc_viewrunning.cpp \
		moc_systeminfo.cpp \
		qrc_images.cpp \
		qrc_help.cpp
OBJECTS       = main.o \
		mainwindow.o \
		proc.o \
		visualiser.o \
		confirmkill.o \
		info.o \
		simulatorinit.o \
		sys.o \
		settings.o \
		errordialog.o \
		viewrunning.o \
		systeminfo.o \
		moc_mainwindow.o \
		moc_visualiser.o \
		moc_confirmkill.o \
		moc_info.o \
		moc_simulatorinit.o \
		moc_settings.o \
		moc_errordialog.o \
		moc_viewrunning.o \
		moc_systeminfo.o \
		qrc_images.o \
		qrc_help.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		TaskStalker.pro
QMAKE_TARGET  = TaskStalker
DESTDIR       = 
TARGET        = TaskStalker

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

$(TARGET): ui_mainwindow.h ui_visualiser.h ui_confirmkill.h ui_info.h ui_simulatorinit.h ui_settings.h ui_errordialog.h ui_viewrunning.h ui_systeminfo.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

Makefile: TaskStalker.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile TaskStalker.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ -unix CONFIG+=debug -o Makefile TaskStalker.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/TaskStalker1.0.0 || $(MKDIR) .tmp/TaskStalker1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/TaskStalker1.0.0/ && $(COPY_FILE) --parents mainwindow.h proc.h visualiser.h confirmkill.h info.h simulatorinit.h sys.h settings.h errordialog.h viewrunning.h systeminfo.h .tmp/TaskStalker1.0.0/ && $(COPY_FILE) --parents images.qrc help.qrc .tmp/TaskStalker1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp proc.cpp visualiser.cpp confirmkill.cpp info.cpp simulatorinit.cpp sys.cpp settings.cpp errordialog.cpp viewrunning.cpp systeminfo.cpp .tmp/TaskStalker1.0.0/ && $(COPY_FILE) --parents mainwindow.ui visualiser.ui confirmkill.ui info.ui simulatorinit.ui settings.ui errordialog.ui viewrunning.ui systeminfo.ui .tmp/TaskStalker1.0.0/ && (cd `dirname .tmp/TaskStalker1.0.0` && $(TAR) TaskStalker1.0.0.tar TaskStalker1.0.0 && $(COMPRESS) TaskStalker1.0.0.tar) && $(MOVE) `dirname .tmp/TaskStalker1.0.0`/TaskStalker1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/TaskStalker1.0.0


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

compiler_moc_header_make_all: moc_mainwindow.cpp moc_visualiser.cpp moc_confirmkill.cpp moc_info.cpp moc_simulatorinit.cpp moc_settings.cpp moc_errordialog.cpp moc_viewrunning.cpp moc_systeminfo.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_visualiser.cpp moc_confirmkill.cpp moc_info.cpp moc_simulatorinit.cpp moc_settings.cpp moc_errordialog.cpp moc_viewrunning.cpp moc_systeminfo.cpp
moc_mainwindow.cpp: proc.h \
		visualiser.h \
		confirmkill.h \
		sys.h \
		errordialog.h \
		info.h \
		simulatorinit.h \
		settings.h \
		viewrunning.h \
		systeminfo.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_visualiser.cpp: proc.h \
		confirmkill.h \
		sys.h \
		errordialog.h \
		visualiser.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) visualiser.h -o moc_visualiser.cpp

moc_confirmkill.cpp: confirmkill.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) confirmkill.h -o moc_confirmkill.cpp

moc_info.cpp: info.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) info.h -o moc_info.cpp

moc_simulatorinit.cpp: visualiser.h \
		proc.h \
		confirmkill.h \
		sys.h \
		errordialog.h \
		simulatorinit.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) simulatorinit.h -o moc_simulatorinit.cpp

moc_settings.cpp: sys.h \
		settings.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) settings.h -o moc_settings.cpp

moc_errordialog.cpp: errordialog.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) errordialog.h -o moc_errordialog.cpp

moc_viewrunning.cpp: sys.h \
		proc.h \
		viewrunning.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) viewrunning.h -o moc_viewrunning.cpp

moc_systeminfo.cpp: proc.h \
		systeminfo.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) systeminfo.h -o moc_systeminfo.cpp

compiler_rcc_make_all: qrc_images.cpp qrc_help.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_images.cpp qrc_help.cpp
qrc_images.cpp: images.qrc \
		img/button_pause.png \
		img/button_play.png \
		img/stop.png \
		img/logo.png \
		img/resume.png \
		img/uninterruptible.png \
		img/icon.png \
		img/kill.png \
		img/unknown.png \
		img/ready.png \
		img/stopped.png \
		img/interruptible.png \
		img/zombie.png \
		img/view.png \
		img/executing.png \
		img/running.png \
		img/terminate.png
	/usr/bin/rcc -name images images.qrc -o qrc_images.cpp

qrc_help.cpp: help.qrc \
		doc/sysinfo.html \
		doc/help.qch \
		doc/index.html \
		doc/mainwindow.png \
		doc/main.html \
		doc/info.html \
		doc/settings.html \
		doc/runningprocs.png \
		doc/collection.qhc \
		doc/simulatorinit.png \
		doc/viswindow.png \
		doc/style.css \
		doc/sysinfo.png \
		doc/visualisation.html \
		doc/runningprocs.html \
		doc/settings.png \
		doc/simulator.html
	/usr/bin/rcc -name help help.qrc -o qrc_help.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_visualiser.h ui_confirmkill.h ui_info.h ui_simulatorinit.h ui_settings.h ui_errordialog.h ui_viewrunning.h ui_systeminfo.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_visualiser.h ui_confirmkill.h ui_info.h ui_simulatorinit.h ui_settings.h ui_errordialog.h ui_viewrunning.h ui_systeminfo.h
ui_mainwindow.h: mainwindow.ui
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

ui_visualiser.h: visualiser.ui
	/usr/bin/uic-qt4 visualiser.ui -o ui_visualiser.h

ui_confirmkill.h: confirmkill.ui
	/usr/bin/uic-qt4 confirmkill.ui -o ui_confirmkill.h

ui_info.h: info.ui
	/usr/bin/uic-qt4 info.ui -o ui_info.h

ui_simulatorinit.h: simulatorinit.ui
	/usr/bin/uic-qt4 simulatorinit.ui -o ui_simulatorinit.h

ui_settings.h: settings.ui
	/usr/bin/uic-qt4 settings.ui -o ui_settings.h

ui_errordialog.h: errordialog.ui
	/usr/bin/uic-qt4 errordialog.ui -o ui_errordialog.h

ui_viewrunning.h: viewrunning.ui
	/usr/bin/uic-qt4 viewrunning.ui -o ui_viewrunning.h

ui_systeminfo.h: systeminfo.ui
	/usr/bin/uic-qt4 systeminfo.ui -o ui_systeminfo.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		proc.h \
		visualiser.h \
		confirmkill.h \
		sys.h \
		errordialog.h \
		info.h \
		simulatorinit.h \
		settings.h \
		viewrunning.h \
		systeminfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		proc.h \
		visualiser.h \
		confirmkill.h \
		sys.h \
		errordialog.h \
		info.h \
		simulatorinit.h \
		settings.h \
		viewrunning.h \
		systeminfo.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

proc.o: proc.cpp proc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o proc.o proc.cpp

visualiser.o: visualiser.cpp visualiser.h \
		proc.h \
		confirmkill.h \
		sys.h \
		errordialog.h \
		ui_visualiser.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o visualiser.o visualiser.cpp

confirmkill.o: confirmkill.cpp confirmkill.h \
		ui_confirmkill.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o confirmkill.o confirmkill.cpp

info.o: info.cpp info.h \
		ui_info.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o info.o info.cpp

simulatorinit.o: simulatorinit.cpp simulatorinit.h \
		visualiser.h \
		proc.h \
		confirmkill.h \
		sys.h \
		errordialog.h \
		ui_simulatorinit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o simulatorinit.o simulatorinit.cpp

sys.o: sys.cpp sys.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o sys.o sys.cpp

settings.o: settings.cpp settings.h \
		sys.h \
		ui_settings.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o settings.o settings.cpp

errordialog.o: errordialog.cpp errordialog.h \
		ui_errordialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o errordialog.o errordialog.cpp

viewrunning.o: viewrunning.cpp viewrunning.h \
		sys.h \
		proc.h \
		ui_viewrunning.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o viewrunning.o viewrunning.cpp

systeminfo.o: systeminfo.cpp systeminfo.h \
		proc.h \
		ui_systeminfo.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o systeminfo.o systeminfo.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_visualiser.o: moc_visualiser.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_visualiser.o moc_visualiser.cpp

moc_confirmkill.o: moc_confirmkill.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_confirmkill.o moc_confirmkill.cpp

moc_info.o: moc_info.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_info.o moc_info.cpp

moc_simulatorinit.o: moc_simulatorinit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_simulatorinit.o moc_simulatorinit.cpp

moc_settings.o: moc_settings.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_settings.o moc_settings.cpp

moc_errordialog.o: moc_errordialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_errordialog.o moc_errordialog.cpp

moc_viewrunning.o: moc_viewrunning.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_viewrunning.o moc_viewrunning.cpp

moc_systeminfo.o: moc_systeminfo.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_systeminfo.o moc_systeminfo.cpp

qrc_images.o: qrc_images.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_images.o qrc_images.cpp

qrc_help.o: qrc_help.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_help.o qrc_help.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

