#include <QtTest/QTest>
#include <stdexcept>
#include "../../solvers/linear_equation_solver/linear_equation_solver.h"

class TestLinearEquationSolver: public QObject
{
    Q_OBJECT

private slots:
    void testValidEquation();
    void testInvalidEquation();
    void testGetEquation();
    void testGetX();
};

void TestLinearEquationSolver::testValidEquation()
{
    LinearEquation eq(2, 3, 7);
    eq.solve();
    QCOMPARE(eq.getX(), std::string("2.00"));
}

void TestLinearEquationSolver::testInvalidEquation()
{
    LinearEquation eq(0, 3, 7);
    bool exceptionCaught = false;
    try {
        eq.solve();
    } catch (const std::runtime_error&) {
        exceptionCaught = true;
    }
    QVERIFY(exceptionCaught);
}

void TestLinearEquationSolver::testGetEquation()
{
    LinearEquation eq(1.234, 5.678, 9.101);
    std::string expected = "1.23x + 5.68 = 9.10";
    QCOMPARE(eq.getEquation(), expected);
}

void TestLinearEquationSolver::testGetX()
{
    LinearEquation eq(3.456, 1.234, 7.890);
    eq.solve();
    QCOMPARE(eq.getX().substr(0, 4), std::string("1.93"));
}

QTEST_MAIN(TestLinearEquationSolver)
#include "test_linear_equation_solver.moc"
