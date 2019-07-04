#-------------------------------------------------
#
# Project created by QtCreator 2011-12-01T17:35:56
#
#-------------------------------------------------

QT       += core gui
QT       += opengl

TARGET = OGL_Quadrics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    oglwidget.cpp

HEADERS  += mainwindow.h \
    oglwidget.h

FORMS    += mainwindow.ui \
    oglwidget.ui

LIBS += -lOpengl32
LIBS += -lglu32

RESOURCES += \
    resource.qrc

win32:RC_FILE = winrc.rc
