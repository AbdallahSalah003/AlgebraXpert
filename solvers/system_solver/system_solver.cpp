#include "system_solver.h"

SystemSolver::SystemSolver(std::vector<std::vector<double>> coefficients, std::vector<double> d) {
    this->len = coefficients.size();
    this->coefficients.resize(len, len);
    this->d.resize(len);

    for (int i = 0; i < this->len; ++i) {
        for (int j = 0; j < this->len; ++j) {
            this->coefficients(i, j) = coefficients[i][j];
        }
    }
    for (int i = 0; i < this->len; ++i) {
        this->d(i) = d[i];
    }

}

void SystemSolver::solve() {

    this->result = this->coefficients.colPivHouseholderQr().solve(this->d);
}

std::string SystemSolver::getResult() const {
    std::ostringstream stream;
    for(int i = 1; i <= this->len; ++i) {
        stream << "var" << i << " = ";
        stream << this->result(i-1) << "\n";
    }
    return stream.str();
}
