#!/bin/bash

run_tests() {
    local test_dir=$1
    local executable=$2

    cd $test_dir || exit
    qmake > /dev/null 2>&1
    make > /dev/null 2>&1
    ./$executable
    make clean > /dev/null
    rm Makefile $executable > /dev/null
    cd - > /dev/null || exit
}

run_tests "test_linear_equation_solver" "test_linear_equation_solver"
run_tests "test_matrix" "test_matrix"
run_tests "test_quadratic_equation_solver" "test_quadratic_equation_solver"
run_tests "test_system_solver" "test_system_solver"

