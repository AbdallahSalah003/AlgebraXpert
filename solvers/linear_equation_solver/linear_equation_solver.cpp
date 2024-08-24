#include "linear_equation_solver.h"

LinearEquation::LinearEquation(double a, double b, double c) : EquationSolver(a, b, c) {}

void LinearEquation::solve() {
    if (a == 0) {
        throw std::runtime_error("Invalid equation: 'a' cannot be zero.");
    }
    this->x = (c - b) / a;
}
std::string LinearEquation::getEquation() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2); // Set precision to 2 decimal places
    stream << this->a << "x + " << this->b << " = " << this->c;
    return stream.str();
}

std::string LinearEquation::getX() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    stream << this->x;
    return stream.str();
}
