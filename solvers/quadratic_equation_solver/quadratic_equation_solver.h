#ifndef QUADRATIC_EQUATION_SOLVER_H
#define QUADRATIC_EQUATION_SOLVER_H

#include <iostream>
#include <stdexcept>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <complex>
#include <variant>

class QuadraticEquation
{
private:
    double a;
    double b;
    double c;
    double d;
    std::variant<double, std::complex<double>> x1;
    std::variant<double, std::complex<double>> x2;

public:
    QuadraticEquation(double a, double b, double c, double d);

    void solve();
    std::string getEquation() const;
    std::string getX() const;
};

#endif // QUADRATIC_EQUATION_SOLVER_H
