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
SOURCES +=  "../../Abgabe, HIER NICHT PROGRAMMIEREN/StartseiteStudikalender/pbearbeiten.cpp"\
            "../../Abgabe, HIER NICHT PROGRAMMIEREN/StartseiteStudikalender/Nutzerprofil.cpp"\



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    tst_tst.h \
        "../../Abgabe, HIER NICHT PROGRAMMIEREN/StartseiteStudikalender/pbearbeiten.h"\
        "../../Abgabe, HIER NICHT PROGRAMMIEREN/StartseiteStudikalender/Nutzerprofil.h"\
