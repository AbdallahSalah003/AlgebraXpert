#include <QtTest/QTest>
#include <stdexcept>
#include "../../solvers/quadratic_equation_solver/quadratic_equation_solver.h"

class TestQuadraticEquationSolver: public QObject
{
    Q_OBJECT

private slots:
    void testValidEquation();
    void testRepeatedRoots();
    void testComplexRoots();
    void testInvalidEquation();
    void testGetEquation();
    void testGetX();
};

void TestQuadraticEquationSolver::testValidEquation()
{
    QuadraticEquation eq(1, -5, 6, 0);
    eq.solve();
    std::string expectedX = "Double root1: 2.00\nDouble root2: 3.00";
    QCOMPARE(eq.getX(), expectedX);
}

void TestQuadraticEquationSolver::testRepeatedRoots()
{
    QuadraticEquation eq(1, -4, 4, 0);
    eq.solve();
    std::string expectedX = "Double root1: 2.00\nDouble root2: 2.00";
    QCOMPARE(eq.getX(), expectedX);
}

void TestQuadraticEquationSolver::testComplexRoots()
{
    QuadraticEquation eq(1, 2, 5, 0);
    eq.solve();
    std::string expectedX = "Complex root1: (-1.00,-2.00)\nComplex root2: (-1.00,2.00)";
    QCOMPARE(eq.getX(), expectedX);
}

void TestQuadraticEquationSolver::testInvalidEquation()
{
    QuadraticEquation eq(0, 2, 5, 0);
    bool exceptionCaught = false;
    try {
        eq.solve();
    } catch (const std::runtime_error&) {
        exceptionCaught = true;
    }
    QVERIFY(exceptionCaught);
}

void TestQuadraticEquationSolver::testGetEquation()
{
    QuadraticEquation eq(1, -5, 6, 0);
    std::string expectedEquation = "1.00x^2 + -5.00x + 6.00 = 0.00";
    QCOMPARE(eq.getEquation(), expectedEquation);
}

void TestQuadraticEquationSolver::testGetX()
{
    // The test for getX is already handled in the other test cases based on different root types
}

QTEST_MAIN(TestQuadraticEquationSolver)
#include "test_quadratic_equation_solver.moc"
