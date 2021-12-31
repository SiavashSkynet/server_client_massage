# server_client_messaging
Based on Qt/C++ 
```
1- create a tcp server
2- create a tcp connection over telnet
3- send your massage to the server
```
Here is My .pro file :
```ruby

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS


SOURCES += \
    main.cpp \
    server.cpp

HEADERS += \
    server.h

FORMS += \
    server.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
```
