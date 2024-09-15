QT += widgets testlib

HEADERS += \
            ../../solvers/linear_equation_solver/linear_equation_solver.h \

SOURCES += test_linear_equation_solver.cpp \
            ../../solvers/linear_equation_solver/linear_equation_solver.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target
