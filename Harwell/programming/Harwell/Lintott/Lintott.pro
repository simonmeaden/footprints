#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T10:00:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

CONFIG(debug, debug|release) {
    TARGET = Lintottd
    DESTDIR = ../../build/lintott
    OBJECTS_DIR = $$DESTDIR/lintott/.objd
    MOC_DIR = $$DESTDIR/lintott/.mocd
    RCC_DIR = $$DESTDIR/lintott/.qrcd
    UI_DIR = $$DESTDIR/lintott/.uid
}

CONFIG(release, debug|release) {
    TARGET = Lintott
    DESTDIR = ../../build/lintott
    OBJECTS_DIR = $$DESTDIR/lintott/.obj
    MOC_DIR = $$DESTDIR/lintott/.moc
    RCC_DIR = $$DESTDIR/lintott/.qrc
    UI_DIR = $$DESTDIR/lintott/.ui
}


SOURCES += \
        main.cpp \
        mainwindow.cpp \
        daemon/backgroundcontroller.cpp \
    manualmotorvoltage.cpp

HEADERS  += \
        mainwindow.h \
        daemon/backgroundcontroller.h \
    manualmotorvoltage.h

FORMS    += mainwindow.ui
