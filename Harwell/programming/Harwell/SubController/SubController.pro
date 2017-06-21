#-------------------------------------------------
#
# Project created by QtCreator 2017-03-31T10:01:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SubController
TEMPLATE = app

CONFIG(debug, debug|release) {
    TARGET = SubControllerd
    DESTDIR = ../../build/lintott
    OBJECTS_DIR = $$DESTDIR/lintott/.objd
    MOC_DIR = $$DESTDIR/lintott/.mocd
    RCC_DIR = $$DESTDIR/lintott/.qrcd
    UI_DIR = $$DESTDIR/lintott/.uid
}

CONFIG(release, debug|release) {
    TARGET = SubController
    DESTDIR = ../../build/lintott
    OBJECTS_DIR = $$DESTDIR/lintott/.obj
    MOC_DIR = $$DESTDIR/lintott/.moc
    RCC_DIR = $$DESTDIR/lintott/.qrc
    UI_DIR = $$DESTDIR/lintott/.ui
}

SOURCES += \
        main.cpp\
        mainwindow.cpp

HEADERS  += \
         mainwindow.h

FORMS    += mainwindow.ui
