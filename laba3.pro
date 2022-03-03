QT  += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CalculateSizeFunctions.cpp \
    CalculateStrategy.cpp \
    Chart.cpp \
    FileTypesStrategy.cpp \
    FoldersStrategy.cpp \
    filedisplaymodel.cpp \
    filemanagerform.cpp \
    main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    CalculateSizeFunctions.h \
    CalculateStrategy.h \
    Chart.h \
    Data.h \
    FileObserver.h \
    FileTypesStrategy.h \
    FoldersStrategy.h \
    filedisplaymodel.h \
    filemanagerform.h

FORMS += \
    filemanagerform.ui
