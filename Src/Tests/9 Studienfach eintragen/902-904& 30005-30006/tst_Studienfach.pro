
QT += testlib
QT       += core gui
QT += sql
QT += widgets


MYSQL_LIBS=-lmysqld
CONFIG += c++11


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES +=  tst_studifach.cpp
SOURCES +=  studifaecher.cpp



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    tst_studifach.h\
    studifaecher.h 
    