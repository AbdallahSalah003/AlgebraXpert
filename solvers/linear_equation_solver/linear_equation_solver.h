#ifndef LINEAR_EQUATION_SOLVER_H
#define LINEAR_EQUATION_SOLVER_H

#include "../equation_solver/equation_solver.h"

class LinearEquation : public EquationSolver
{
private:
    double x;

public:
    LinearEquation(double a, double b, double c);

    void solve() override;
    std::string getEquation() const override;
    std::string getX() const override;
};

#endif // LINEAR_EQUATION_SOLVER_H
