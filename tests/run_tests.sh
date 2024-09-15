cd test_linear_equation_solver/
qmake > /dev/null 2>&1
make > /dev/null 2>&1
./test_linear_equation_solver
make clean > /dev/null
rm Makefile test_linear_equation_solver > /dev/null

cd ../test_matrix/
qmake > /dev/null 2>&1
make > /dev/null 2>&1
./test_matrix
make clean > /dev/null
rm Makefile test_matrix > /dev/null
