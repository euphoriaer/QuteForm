QT -= gui

TEMPLATE = lib
DEFINES += PLUGINCORE_LIBRARY
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH  += ../../Main

SOURCES += \
    plugincore.cpp \
    plugmanager.cpp

HEADERS += \
    plugincore.h \
    plugmanager.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DESTDIR += ../../../Build/Generate/plugins #目标路径
TARGET = PluginsManager  #软件名

FORMS += \
    plugmanager.ui
