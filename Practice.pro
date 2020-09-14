QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += QMAKE_LFLAGS_CONSOLE

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ClassExample/ExampleClassSingleton.cpp \
    ClassExample/ExampleClassStatic.cpp \
    Form_MainForm.cpp \
    MyApplication.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ClassExample/ExampleClassSingleton.h \
    ClassExample/ExampleClassStatic.h \
    Form_MainForm.h \
    MyApplication.h \
    mainwindow.h

FORMS += \
    Form_MainForm.ui \
    mainwindow.ui

TRANSLATIONS += \
    Practice_ja_JP.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
