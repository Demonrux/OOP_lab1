TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        circle.cpp \
        figure.cpp \
        figurecollection.cpp \
        main.cpp \
        menucommands.cpp \
        rectangle.cpp \
        triangle.cpp

HEADERS += \
    circle.h \
    figure.h \
    figurecollection.h \
    menucommands.h \
    rectangle.h \
    triangle.h
