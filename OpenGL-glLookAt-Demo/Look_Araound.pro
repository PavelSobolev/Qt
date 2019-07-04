#-------------------------------------------------
#
# Project created by Pavel Sobolev
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

LIBS += -lOpengl32
LIBS += -lglu32

TARGET = Look_Around
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui
win32:RC_FILE = win.rc
