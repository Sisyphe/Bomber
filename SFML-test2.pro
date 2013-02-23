TEMPLATE = app
CONFIG -= console
CONFIG -= qt
CONFIG += debug

LIBS += -lsfml-system -lsfml-window -lsfml-graphics

SOURCES += main.cpp \
    animatedsprite.cpp \
    character.cpp \
    user.cpp \
    localuser.cpp \
    bomb.cpp \
    drawbuffer.cpp \
    map.cpp \
    tile.cpp

HEADERS += \
    animatedsprite.h \
    character.h \
    user.h \
    localuser.h \
    bomb.h \
    drawbuffer.h \
    map.h \
    tile.h

OTHER_FILES +=

