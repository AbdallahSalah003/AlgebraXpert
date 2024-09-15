#include "system_solver.h"

SystemSolver::SystemSolver(std::vector<std::vector<double>> coefficients, std::vector<double> d) {
    if(coefficients.size()!=coefficients[0].size() or d.size()!=coefficients.size())
    {
        throw std::invalid_argument("Invalid input deminsions");
    }
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

    Eigen::FullPivLU<Eigen::MatrixXd> lu_decomp(this->coefficients);

    if (lu_decomp.rank() < this->len) {
        throw std::runtime_error("The system is either under-determined or inconsistent (no unique solution).");
    }

    this->result = this->coefficients.colPivHouseholderQr().solve(this->d);

    Eigen::VectorXd residual = this->coefficients * this->result - this->d;
    if (residual.norm() > 1e-9) {
        throw std::runtime_error("The system has no exact solution (inconsistent).");
    }
}

std::string SystemSolver::getResult() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2);
    for(int i = 1; i <= this->len; ++i) {
        stream << "var" << i << " = ";
        stream << this->result(i-1) << "\n";
    }
    return stream.str();
}
