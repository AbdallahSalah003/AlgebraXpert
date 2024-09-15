QT += widgets testlib

SOURCES = test_matrix.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/qtestlib/tutorial1
INSTALLS += target

INCLUDEPATH += /usr/include/eigen3
