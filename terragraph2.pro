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
    vertattrsdlg.cpp \
    dom.cpp \
    xmllib/xmlbackend.cpp \
    commands/cmdaddvert.cpp \
    commands/cmdaddarr.cpp \
    commands/cmddelvert.cpp \
    commands/cmddelarr.cpp \
    commands/cmdvertsetpos.cpp \
    commands/cmdarrsetstartend.cpp \
    graphlib/graphicscene.cpp
HEADERS += mainwindow.h \
    graphlib/vertex.h \
    graphlib/arrow.h \
    graphlib/geometry.h \
    vertattrsdlg.h \
    dom.h \
    dombackend.h \
    command.h \
    xmllib/xmlbackend.h \
    commands/cmdaddvert.h \
    commands/cmdaddarr.h \
    commands/cmddelvert.h \
    commands/cmddelarr.h \
    commands/cmdvertsetpos.h \
    commands/cmdarrsetstartend.h \
    graphlib/graphicscene.h
FORMS += mainwindow.ui \
    vertattrsdlg.ui
RESOURCES += icons.qrc
