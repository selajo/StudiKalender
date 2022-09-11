QT += testlib
QT       += core gui
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


MYSQL_LIBS=-lmysqld
CONFIG += c++11


CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_tst.cpp
SOURCES +=  "StartseiteStudikalender/mainwindow.cpp"
SOURCES +=  "StartseiteStudikalender/Nutzerprofil.cpp"
SOURCES +=  "StartseiteStudikalender/Datenbank.cpp"
SOURCES +=  "StartseiteStudikalender/Tagesansicht.cpp"



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    tst_tst.h \
        "StartseiteStudikalender/mainwindow.h" \
        "StartseiteStudikalender/Nutzerprofil.h" \
        "StartseiteStudikalender/Datenbank.h" \
        "StartseiteStudikalender/Tagesansicht.h" \

