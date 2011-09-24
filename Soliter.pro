HEADERS += tgbutton.h \
    mainwidget.h \
    mainwindow.h \
    createnewfield.h \
    serverdialog.h \
    thread.h \
    tcpsocket.h \
    client.h
SOURCES += main.cpp \
    tgbutton.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    createnewfield.cpp \
    serverdialog.cpp \
    thread.cpp \
    tcpsocket.cpp \
    client.cpp
FORMS += createnewfield.ui \
    serverdialog.ui \
    client.ui
RESOURCES += resource.qrc
RC_FILE = icon.rc
QT += network
CONFIG += console
