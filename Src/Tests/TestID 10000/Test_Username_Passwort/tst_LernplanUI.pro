QT += testlib
QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


MYSQL_LIBS=-lmysqld



CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_tst.cpp
SOURCES +=  username.cpp
SOURCES += Nutzerprofil.cpp
SOURCES += password.cpp



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    tst_tst.h \
    username.h \
    Nutzerprofil.h \
    password.h \
