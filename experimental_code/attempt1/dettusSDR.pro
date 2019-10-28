######################################################################
# Automatically generated by qmake (3.1) Wed Oct 16 09:05:58 2019
######################################################################

TEMPLATE = app
TARGET = dettusSDR
INCLUDEPATH += . \
		tuners \
		tuners/dummy \
		tuners/rtltcp \
		gui \
		central	\
		signalprocessing

CONFIG += debug

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += signalprocessing/SimpleFft.h \
           signalprocessing/SimpleShifter.h \
           tuners/Tuners.h \
           tuners/dummy/TDummy.h	\
           tuners/dummy/CBDummy.h	\
           tuners/dummy/WDummy.h	\
           tuners/rtltcp/TRtlTcp.h	\
           tuners/rtltcp/WRtlTcp.h	\
           tuners/rtltcp/CBRtlTcp.h	\
           gui/MainWindow.h	\
           gui/WSpectrum.h	\
           gui/WWaterfall.h	\
           gui/TunerDialog.h	\
           central/Datatypes.h	\
           central/Sink.h	\
           central/Central.h

SOURCES += main.cpp \
           signalprocessing/SimpleFft.cpp \
           signalprocessing/SimpleShifter.cpp \
           tuners/dummy/TDummy.cpp	\
           tuners/dummy/WDummy.cpp	\
           tuners/rtltcp/TRtlTcp.cpp	\
           tuners/rtltcp/WRtlTcp.cpp	\
           gui/MainWindow.cpp		\
           gui/WSpectrum.cpp		\
           gui/WWaterfall.cpp		\
           gui/TunerDialog.cpp		\
           central/Central.cpp

QT += multimedia widgets