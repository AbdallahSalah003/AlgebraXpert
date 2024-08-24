#ifndef EQUATION_SOLVER_H
#define EQUATION_SOLVER_H

#include <iostream>
#include <stdexcept>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <complex>
#include <variant>

class EquationSolver
{
protected:
    double a;
    double b;
    double c;

public:
    EquationSolver(double a, double b, double c) : a(a), b(b), c(c) {};

    virtual void solve() = 0;
    virtual std::string getEquation() const = 0;
    virtual std::string getX() const = 0;
};

#endif // EQUATION_SOLVER_H
