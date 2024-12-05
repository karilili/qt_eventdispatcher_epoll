QT       -= gui
TARGET    = eventdispatcher_epoll
TEMPLATE  = lib
DESTDIR   = ../lib
CONFIG   += staticlib
CONFIG   += create_prl create_pc
HEADERS  += eventdispatcher_epoll.h eventdispatcher_epoll_p.h qt4compat.h
SOURCES  += eventdispatcher_epoll.cpp eventdispatcher_epoll_p.cpp timers_p.cpp socknot_p.cpp

QMAKE_CXXFLAGS_RELEASE = $$QMAKE_CFLAGS_RELEASE_WITH_DEBUGINFO #realease模式下也可以生成pdb文件
QMAKE_LFLAGS_RELEASE = $$QMAKE_LFLAGS_RELEASE_WITH_DEBUGINFO

headers.files = eventdispatcher_epoll.h
headers.path  = /usr/include
target.path   = /usr/lib

QMAKE_PKGCONFIG_NAME        = eventdispatcher_epoll
QMAKE_PKGCONFIG_DESCRIPTION = "epoll()-based event dispatcher for Qt"
QMAKE_PKGCONFIG_LIBDIR      = $$target.path
QMAKE_PKGCONFIG_INCDIR      = $$headers.path
QMAKE_PKGCONFIG_DESTDIR     = pkgconfig

INSTALLS += target headers
