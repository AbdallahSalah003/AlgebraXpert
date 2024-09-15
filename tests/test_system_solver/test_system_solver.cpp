#include <QtTest/QTest>
#include "../../solvers/system_solver/system_solver.h"
#include <iostream>
class TestSystemSolver : public QObject
{
    Q_OBJECT

private slots:
    void testValidSystem();
    void testSingularSystem();
    void testGetResult();
    void testInvalidDimensions();
};

void TestSystemSolver::testValidSystem()
{
    std::vector<std::vector<double>> coefficients = {{2, 5}, {4, 6}};
    std::vector<double> d = {6, 10};

    SystemSolver solver(coefficients, d);
    solver.solve();
    std::string expected = "var1 = 1.75\nvar2 = 0.50\n";
    QCOMPARE(solver.getResult(), expected);
}

void TestSystemSolver::testSingularSystem()
{
    std::vector<std::vector<double>> coefficients = {{1, 1}, {2, 2}};
    std::vector<double> d = {2, 4};

    SystemSolver solver(coefficients, d);
    bool exceptionCaught = false;
    try {
        solver.solve();
        std::cout<<solver.getResult()<<'\n';
    } catch (const std::runtime_error&) {
        exceptionCaught = true;
    }
    QVERIFY(exceptionCaught);
}

void TestSystemSolver::testGetResult()
{
    std::vector<std::vector<double>> coefficients = {{3, 1}, {1, 2}};
    std::vector<double> d = {9, 8};

    SystemSolver solver(coefficients, d);
    solver.solve();

    std::string expected = "var1 = 2.00\nvar2 = 3.00\n";
    QCOMPARE(solver.getResult(), expected);
}

void TestSystemSolver::testInvalidDimensions()
{
    std::vector<std::vector<double>> coefficients = {{1, 1, 1}, {2, 2, 2}};
    std::vector<double> d = {2, 4};
    bool exceptionCaught = false;
    try {
        SystemSolver solver(coefficients, d);
    } catch (const std::invalid_argument&) {
        exceptionCaught = true;
    }
    QVERIFY(exceptionCaught);
}

QTEST_MAIN(TestSystemSolver)
#include "test_system_solver.moc"
