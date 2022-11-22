QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH    += ../Plugs/PlugManager

SOURCES += \
    allformfileshow.cpp \
    basewidget.cpp \
    datamanager.cpp \
    formwindow.cpp \
    hintdialog.cpp \
    main.cpp \
    mainwindow.cpp \
    nearformshow.cpp \
    starformshow.cpp \
    tip.cpp \
    ui/createform.cpp

HEADERS += \
    allformfileshow.h \
    datamanager.h \
    nearformshow.h \
    pluginsInterface.h \
    basewidget.h \
    formwindow.h \
    hintdialog.h \
    mainwindow.h \
    starformshow.h \
    tip.h \
    ui/createform.h

FORMS += \
    allformfileshow.ui \
    datamanager.ui \
    formwindow.ui \
    hintdialog.ui \
    mainwindow.ui \
    nearformshow.ui \
    starformshow.ui \
    tip.ui \
    ui/createform.ui

TRANSLATIONS += \
    QuteForm_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

DESTDIR += ../../Build/Generate #目标路径
TARGET = QuteForm  #软件名

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../Resources/icons/Icons.qrc

