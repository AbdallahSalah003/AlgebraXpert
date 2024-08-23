#ifndef LINEAR_EQUATION_SOLVER_H
#define LINEAR_EQUATION_SOLVER_H

#include <iostream>
#include <stdexcept>
#include <string.h>
#include <sstream>
#include <iomanip>

class LinearEquation
{
private:
    double a;
    double b;
    double c;
    double x;

public:
    LinearEquation(double a, double b, double c);

    double solve();
    std::string getEquation() const;
    std::string getX() const;
};

#endif // LINEAR_EQUATION_SOLVER_H
