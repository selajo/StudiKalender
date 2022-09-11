QT += testlib
QT       += core gui
QT += sql
QT += widgets


MYSQL_LIBS=-lmysqld
CONFIG += c++11


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES +=  \
    tst_termin_bearbeiten.cpp
SOURCES +=  termin_bearbeiten.cpp



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    termin_bearbeiten.h  \
    tst_termin_bearbeiten.h