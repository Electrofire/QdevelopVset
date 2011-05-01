TEMPLATE = app
TARGET =
DEPENDPATH += . build src ui
DESTDIR = bin
QT = gui core
OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = build
INCLUDEPATH += . src build build/vtk
LIBS += -L./build/vtk/bin \
 -lvtkRendering \
 -lvtkIO \
 -lvtkFiltering \
 -lvtkGraphics \
 -lvtkVolumeRendering \
 -lQVTK
HEADERS += src/animatorwindow.h \
 src/Experiment.h \
 src/ExperimentManager.h \
 src/mainwindowimpl.h \
 src/Model.h \
 src/pugiconfig.hpp \
 src/pugixml.hpp \
 src/RenderWindow.h \
 src/ShotPoint.h \
 src/Visualization.h \
 src/Workspace.h \
 src/modelwindow.h \
 src/Exception.h
FORMS += ui/animatorwindow.ui ui/mainwindow.ui ui/modelwindow.ui
SOURCES += src/animatorwindow.cpp \
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
 src/Exception.cpp
