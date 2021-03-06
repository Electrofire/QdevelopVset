#############################################################################
# Makefile for building: bin/vset
<<<<<<< HEAD
# Generated by qmake (2.01a) (Qt 4.7.2) on: Sun May 1 17:09:12 2011
=======
# Generated by qmake (2.01a) (Qt 4.7.0) on: Sun May 1 16:56:23 2011
>>>>>>> 15ea0dbf92a614c84db8f7f990916ea72e036416
# Project:  vset.pro
# Template: app
# Command: /usr/bin/qmake -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile vset.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -Isrc -Ibuild -Ibuild/vtk -Ibuild -Ibuild
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib -L./build/vtk/bin -lvtkRendering -lvtkIO -lvtkFiltering -lvtkGraphics -lvtkVolumeRendering -lQVTK -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

OBJECTS_DIR   = build/

####### Files

SOURCES       = src/animatorwindow.cpp \
		src/CoverageModel.cpp \
		src/Experiment.cpp \
		src/ExperimentManager.cpp \
		src/main.cpp \
		src/mainwindowimpl.cpp \
		src/Model.cpp \
		src/PerturbationModel.cpp \
		src/pugixml.cpp \
		src/RenderWindow.cpp \
		src/ShotPoint.cpp \
		src/TimeModel.cpp \
		src/VelocityModel.cpp \
		src/Visualization.cpp \
		src/Workspace.cpp \
		src/modelwindow.cpp \
<<<<<<< HEAD
		src/Exception.cpp build/moc_animatorwindow.cpp \
=======
		src/updateThread.cpp build/moc_animatorwindow.cpp \
>>>>>>> 15ea0dbf92a614c84db8f7f990916ea72e036416
		build/moc_mainwindowimpl.cpp \
		build/moc_modelwindow.cpp
OBJECTS       = build/animatorwindow.o \
		build/CoverageModel.o \
		build/Experiment.o \
		build/ExperimentManager.o \
		build/main.o \
		build/mainwindowimpl.o \
		build/Model.o \
		build/PerturbationModel.o \
		build/pugixml.o \
		build/RenderWindow.o \
		build/ShotPoint.o \
		build/TimeModel.o \
		build/VelocityModel.o \
		build/Visualization.o \
		build/Workspace.o \
		build/modelwindow.o \
<<<<<<< HEAD
		build/Exception.o \
=======
		build/updateThread.o \
>>>>>>> 15ea0dbf92a614c84db8f7f990916ea72e036416
		build/moc_animatorwindow.o \
		build/moc_mainwindowimpl.o \
		build/moc_modelwindow.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		vset.pro
QMAKE_TARGET  = vset
DESTDIR       = bin/
TARGET        = bin/vset

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

$(TARGET): build/ui_animatorwindow.h build/ui_mainwindow.h build/ui_modelwindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) bin/ || $(MKDIR) bin/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: vset.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/lib/libQtGui.prl \
		/usr/lib/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile vset.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/lib/libQtGui.prl:
/usr/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile vset.pro

dist: 
	@$(CHK_DIR_EXISTS) build/vset1.0.0 || $(MKDIR) build/vset1.0.0 
<<<<<<< HEAD
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/vset1.0.0/ && $(COPY_FILE) --parents src/animatorwindow.h src/Experiment.h src/ExperimentManager.h src/mainwindowimpl.h src/Model.h src/pugiconfig.hpp src/pugixml.hpp src/RenderWindow.h src/ShotPoint.h src/Visualization.h src/Workspace.h src/modelwindow.h src/Exception.h build/vset1.0.0/ && $(COPY_FILE) --parents src/animatorwindow.cpp src/CoverageModel.cpp src/Experiment.cpp src/ExperimentManager.cpp src/main.cpp src/mainwindowimpl.cpp src/Model.cpp src/PerturbationModel.cpp src/pugixml.cpp src/RenderWindow.cpp src/ShotPoint.cpp src/TimeModel.cpp src/VelocityModel.cpp src/Visualization.cpp src/Workspace.cpp src/modelwindow.cpp src/Exception.cpp build/vset1.0.0/ && $(COPY_FILE) --parents ui/animatorwindow.ui ui/mainwindow.ui ui/modelwindow.ui build/vset1.0.0/ && (cd `dirname build/vset1.0.0` && $(TAR) vset1.0.0.tar vset1.0.0 && $(COMPRESS) vset1.0.0.tar) && $(MOVE) `dirname build/vset1.0.0`/vset1.0.0.tar.gz . && $(DEL_FILE) -r build/vset1.0.0
=======
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/vset1.0.0/ && $(COPY_FILE) --parents src/animatorwindow.h src/Experiment.h src/ExperimentManager.h src/mainwindowimpl.h src/Model.h src/pugiconfig.hpp src/pugixml.hpp src/RenderWindow.h src/ShotPoint.h src/Visualization.h src/Workspace.h src/modelwindow.h src/updateThread.h build/vset1.0.0/ && $(COPY_FILE) --parents src/animatorwindow.cpp src/CoverageModel.cpp src/Experiment.cpp src/ExperimentManager.cpp src/main.cpp src/mainwindowimpl.cpp src/Model.cpp src/PerturbationModel.cpp src/pugixml.cpp src/RenderWindow.cpp src/ShotPoint.cpp src/TimeModel.cpp src/VelocityModel.cpp src/Visualization.cpp src/Workspace.cpp src/modelwindow.cpp src/updateThread.cpp build/vset1.0.0/ && $(COPY_FILE) --parents ui/animatorwindow.ui ui/mainwindow.ui ui/modelwindow.ui build/vset1.0.0/ && (cd `dirname build/vset1.0.0` && $(TAR) vset1.0.0.tar vset1.0.0 && $(COMPRESS) vset1.0.0.tar) && $(MOVE) `dirname build/vset1.0.0`/vset1.0.0.tar.gz . && $(DEL_FILE) -r build/vset1.0.0
>>>>>>> 15ea0dbf92a614c84db8f7f990916ea72e036416


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

compiler_moc_header_make_all: build/moc_animatorwindow.cpp build/moc_mainwindowimpl.cpp build/moc_modelwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) build/moc_animatorwindow.cpp build/moc_mainwindowimpl.cpp build/moc_modelwindow.cpp
build/moc_animatorwindow.cpp: build/ui_animatorwindow.h \
		src/Workspace.h \
		src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Visualization.h \
		src/updateThread.h \
		src/animatorwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/animatorwindow.h -o build/moc_animatorwindow.cpp

build/moc_mainwindowimpl.cpp: build/ui_mainwindow.h \
		src/Workspace.h \
		src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Visualization.h \
		src/animatorwindow.h \
		build/ui_animatorwindow.h \
		src/updateThread.h \
		src/mainwindowimpl.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/mainwindowimpl.h -o build/moc_mainwindowimpl.cpp

build/moc_modelwindow.cpp: build/ui_modelwindow.h \
		src/modelwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) src/modelwindow.h -o build/moc_modelwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: build/ui_animatorwindow.h build/ui_mainwindow.h build/ui_modelwindow.h
compiler_uic_clean:
	-$(DEL_FILE) build/ui_animatorwindow.h build/ui_mainwindow.h build/ui_modelwindow.h
build/ui_animatorwindow.h: ui/animatorwindow.ui
	/usr/bin/uic-qt4 ui/animatorwindow.ui -o build/ui_animatorwindow.h

build/ui_mainwindow.h: ui/mainwindow.ui
	/usr/bin/uic-qt4 ui/mainwindow.ui -o build/ui_mainwindow.h

build/ui_modelwindow.h: ui/modelwindow.ui
	/usr/bin/uic-qt4 ui/modelwindow.ui -o build/ui_modelwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/animatorwindow.o: src/animatorwindow.cpp src/animatorwindow.h \
		build/ui_animatorwindow.h \
		src/Workspace.h \
		src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Visualization.h \
		src/updateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/animatorwindow.o src/animatorwindow.cpp

build/CoverageModel.o: src/CoverageModel.cpp src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/CoverageModel.o src/CoverageModel.cpp

build/Experiment.o: src/Experiment.cpp src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Experiment.o src/Experiment.cpp

build/ExperimentManager.o: src/ExperimentManager.cpp src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/ExperimentManager.o src/ExperimentManager.cpp

build/main.o: src/main.cpp src/mainwindowimpl.h \
		build/ui_mainwindow.h \
		src/Workspace.h \
		src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Visualization.h \
		src/animatorwindow.h \
		build/ui_animatorwindow.h \
		src/updateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/main.o src/main.cpp

build/mainwindowimpl.o: src/mainwindowimpl.cpp src/mainwindowimpl.h \
		build/ui_mainwindow.h \
		src/Workspace.h \
		src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Visualization.h \
		src/animatorwindow.h \
		build/ui_animatorwindow.h \
		src/updateThread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/mainwindowimpl.o src/mainwindowimpl.cpp

build/Model.o: src/Model.cpp src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Model.o src/Model.cpp

build/PerturbationModel.o: src/PerturbationModel.cpp src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/PerturbationModel.o src/PerturbationModel.cpp

build/pugixml.o: src/pugixml.cpp src/pugixml.hpp \
		src/pugiconfig.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/pugixml.o src/pugixml.cpp

build/RenderWindow.o: src/RenderWindow.cpp src/RenderWindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/RenderWindow.o src/RenderWindow.cpp

build/ShotPoint.o: src/ShotPoint.cpp src/ShotPoint.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/ShotPoint.o src/ShotPoint.cpp

build/TimeModel.o: src/TimeModel.cpp src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/TimeModel.o src/TimeModel.cpp

build/VelocityModel.o: src/VelocityModel.cpp src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/VelocityModel.o src/VelocityModel.cpp

build/Visualization.o: src/Visualization.cpp src/Visualization.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Visualization.o src/Visualization.cpp

build/Workspace.o: src/Workspace.cpp src/Workspace.h \
		src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Visualization.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Workspace.o src/Workspace.cpp

build/modelwindow.o: src/modelwindow.cpp src/modelwindow.h \
		build/ui_modelwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/modelwindow.o src/modelwindow.cpp

<<<<<<< HEAD
build/Exception.o: src/Exception.cpp src/Exception.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Exception.o src/Exception.cpp
=======
build/updateThread.o: src/updateThread.cpp src/updateThread.h \
		src/Workspace.h \
		src/ExperimentManager.h \
		src/Experiment.h \
		src/pugixml.hpp \
		src/pugiconfig.hpp \
		src/ShotPoint.h \
		src/Model.h \
		src/modelwindow.h \
		build/ui_modelwindow.h \
		src/Visualization.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/updateThread.o src/updateThread.cpp
>>>>>>> 15ea0dbf92a614c84db8f7f990916ea72e036416

build/moc_animatorwindow.o: build/moc_animatorwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_animatorwindow.o build/moc_animatorwindow.cpp

build/moc_mainwindowimpl.o: build/moc_mainwindowimpl.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_mainwindowimpl.o build/moc_mainwindowimpl.cpp

build/moc_modelwindow.o: build/moc_modelwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/moc_modelwindow.o build/moc_modelwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

