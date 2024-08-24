#ifndef QUADRATIC_EQUATION_SOLVER_H
#define QUADRATIC_EQUATION_SOLVER_H

#include "../equation_solver/equation_solver.h"

class QuadraticEquation : public EquationSolver
{
private:
    double d;
    std::variant<double, std::complex<double>> x1;
    std::variant<double, std::complex<double>> x2;

public:
    QuadraticEquation(double a, double b, double c, double d);

    void solve() override;
    std::string getEquation() const override;
    std::string getX() const override;
};

#endif // QUADRATIC_EQUATION_SOLVER_H
