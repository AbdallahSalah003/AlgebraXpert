QT += widgets testlib

HEADERS += \
            ../../solvers/quadratic_equation_solver/quadratic_equation_solver.h \

SOURCES += test_quadratic_equation_solver.cpp \
            ../../solvers/quadratic_equation_solver/quadratic_equation_solver.cpp
# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target
