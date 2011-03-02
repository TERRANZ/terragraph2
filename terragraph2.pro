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
    graphlib/basegraphitem.cpp \
    graphlib/arrow.cpp \
    graphlib/vertex.cpp \
    graphlib/box.cpp
HEADERS += mainwindow.h \
    graphlib/basegraphitem.h \
    graphlib/arrow.h \
    graphlib/vertex.h \
    graphlib/box.h
FORMS += mainwindow.ui
