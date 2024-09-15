QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    algebraxpert.cpp \
    solvers/linear_equation_solver/linear_equation_solver.cpp \
    solvers/quadratic_equation_solver/quadratic_equation_solver.cpp \
    solvers/system_solver/system_solver.cpp \
    utils/utils.cpp

HEADERS += \
    algebraxpert.h \
    solvers/equation_solver/equation_solver.h \
    solvers/linear_equation_solver/linear_equation_solver.hpp \
    solvers/matrix_solver/matrix.h \
    solvers/quadratic_equation_solver/quadratic_equation_solver.hpp \
    solvers/system_solver/system_solver.h \
    utils/utils.h


FORMS += \
    algebraxpert.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# Add this line to your .pro file to include Eigen headers
INCLUDEPATH += /usr/include/eigen3


RESOURCES += \
    resources.qrc
