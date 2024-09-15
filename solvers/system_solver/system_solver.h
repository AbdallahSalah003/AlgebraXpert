#ifndef SYSTEM_SOLVER_H
#define SYSTEM_SOLVER_H

#include <iomanip>
#include <vector>
#include <Eigen/Dense>

class SystemSolver
{
private:
    int len;
    Eigen::MatrixXd coefficients;
    Eigen::VectorXd d;
    Eigen::VectorXd result;

public:
    SystemSolver(std::vector<std::vector<double>> coefficients, std::vector<double> d);

    void solve();
    std::string getResult() const;
};
#endif // SYSTEM_SOLVER_H
