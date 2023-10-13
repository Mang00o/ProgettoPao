QT += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
#CONFIG += rtti

SOURCES += main.cpp \
        Iterator.cpp \
        carbsource.cpp \
        container.cpp \
        fatsource.cpp \
        food.cpp \
        foodModification_box.cpp \
        foodextrawidget.cpp \
        foodsetwidget.cpp \
        in_out.cpp \
        listmodel.cpp \
        littlewindow.cpp \
        mainwindow.cpp \
        mybutton.cpp \
        proteinsource.cpp \
        ribbon_box.cpp \
        showMenu_box.cpp \
        tablemodel.cpp

HEADERS += mainwindow.h \
    carbsource.h \
    container.h \
    fatsource.h \
    food.h \
    foodModification_box.h \
    foodextrawidget.h \
    foodsetwidget.h \
    in_out.h \
    listmodel.h \
    littlewindow.h \
    mybutton.h \
    proteinsource.h \
    ribbon_box.h \
    showMenu_box.h \
    tablemodel.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
