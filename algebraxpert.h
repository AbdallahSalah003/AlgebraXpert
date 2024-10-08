#ifndef ALGEBRAXPERT_H
#define ALGEBRAXPERT_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include "utils/utils.h"
#include "solvers/system_solver/system_solver.h"
#include "solvers/linear_equation_solver/linear_equation_solver.h"
#include "solvers/quadratic_equation_solver/quadratic_equation_solver.h"
#include "solvers/matrix_solver/matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class AlgebraXpert;
}
QT_END_NAMESPACE

class AlgebraXpert : public QMainWindow
{
    Q_OBJECT

public:
    AlgebraXpert(QWidget *parent = nullptr);
    ~AlgebraXpert();

private slots:
    void onStartButtonClicked();
    void onExitButtonClicked();
    void onBackButtonClicked();

    void onLinearEquationSolverButtonClicked();

    void onLinearEquationSolveButtonClicked();

    void onQuadraticEquationSolverButtonClicked();

    void onQuadraticEquationSolveButtonClicked();

    void onSystemEquationSolverButtonClicked();

    void onSystemEquationSolveButtonClicked();

    void onMatrixBinaryOperationsButtonClicked();
    void onMatrixBinaryOperationsSolveButtonClicked();

    void onMatrixDeterminantButtonClicked();
    void onMatrixDeterminantSolveButtonClicked();

    void onMatrixInverseButtonClicked();
    void onMatrixInverseSolveButtonClicked();

    void onMatrixEigenValuesButtonClicked();
    void onMatrixEigenValuesSolveButtonClicked();

private:
    Ui::AlgebraXpert *ui;

};
#endif // ALGEBRAXPERT_H
