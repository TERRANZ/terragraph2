# -------------------------------------------------
# Project created by QtCreator 2011-03-02T12:03:30
# -------------------------------------------------
QT += network \
    xml \
    xmlpatterns
TARGET = terragraph2
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    graphlib/vertex.cpp \
    graphlib/arrow.cpp \
    graphlib/geometry.cpp \
    vertattrsdlg.cpp \
    dom.cpp \
    xmllib/xmlbackend.cpp
HEADERS += mainwindow.h \
    graphlib/vertex.h \
    graphlib/arrow.h \
    graphlib/geometry.h \
    vertattrsdlg.h \
    dom.h \
    dombackend.h \
    command.h \
    xmllib/xmlbackend.h
FORMS += mainwindow.ui \
    vertattrsdlg.ui
