QT += network

HEADERS  += \
$$PWD/src/eventdispatcher_epoll.h \
$$PWD/src/eventdispatcher_epoll_p.h \
$$PWD/src/qt4compat.h

SOURCES  += \
$$PWD/src/eventdispatcher_epoll.cpp \
$$PWD/src/eventdispatcher_epoll_p.cpp \
$$PWD/src/timers_p.cpp \
$$PWD/src/socknot_p.cpp

INCLUDEPATH += $$PWD/src/
