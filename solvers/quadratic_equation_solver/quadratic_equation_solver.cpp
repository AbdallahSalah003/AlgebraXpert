#include "quadratic_equation_solver.h"

QuadraticEquation::QuadraticEquation(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}

void QuadraticEquation::solve() {
    if (a == 0) {
        throw std::runtime_error("Invalid Quadratic Equation: 'a' cannot be zero.");
    }
    double discriminant = b * b - 4 * a * c;
    double denom = 2 * a;

    if (discriminant > 0) {
        // Two distinct real roots
        double sqrtDiscriminant = sqrt(discriminant);
        this->x1 = (-b - sqrtDiscriminant) / denom;
        this->x2 = (-b + sqrtDiscriminant) / denom;

    } else if (discriminant == 0) {
        // One repeated real root
        double root = -b / denom;
        this->x1 = root;
        this->x2 = root;
    } else {
        // Complex roots
        std::complex<double> sqrtDiscriminant = std::sqrt(std::complex<double>(discriminant, 0));
        this->x1 = (-b - sqrtDiscriminant) / denom;
        this->x2 = (-b + sqrtDiscriminant) / denom;
    }
}
std::string QuadraticEquation::getEquation() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    stream << this->a << "x^2 + " << this->b << "x + " << this->c << " = " << this->d;
    return stream.str();
}

std::string QuadraticEquation::getX() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    // Check the type and handle accordingly
    if (std::holds_alternative<double>(this->x1)) {
        stream << "Double root1: " << std::get<double>(this->x1) << "\n";
        stream << "Double root2: " << std::get<double>(this->x2);
    } else if (std::holds_alternative<std::complex<double>>(this->x1)) {
        stream << "Complex root1: " << std::get<std::complex<double>>(this->x1) << "\n";
        stream << "Complex root2: " << std::get<std::complex<double>>(this->x2);
    }
    return stream.str();
}
