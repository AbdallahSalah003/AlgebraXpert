#ifndef ALGEBRAXPERT_H
#define ALGEBRAXPERT_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QWidget>
#include "solvers/linear_equation_solver/linear_equation_solver.h"
#include "solvers/quadratic_equation_solver/quadratic_equation_solver.h"

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

private:
    Ui::AlgebraXpert *ui;

};
#endif // ALGEBRAXPERT_H
