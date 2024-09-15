QT += widgets testlib

HEADERS += \
            ../../solvers/system_solver/system_solver.h

SOURCES += test_system_solver.cpp \
            ../../solvers/system_solver/system_solver.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

INCLUDEPATH += /usr/include/eigen3
