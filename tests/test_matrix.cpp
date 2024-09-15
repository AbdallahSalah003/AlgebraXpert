#include <QtTest/QTest>
#include "../solvers/matrix_solver/matrix.h"

class TestMatrix: public QObject
{
    Q_OBJECT
    bool fuzzyCompare(double a, double b, double tolerance);
private slots:
    void testMatrixConstruction();
    void testMatrixAddition();
    void testMatrixSubtraction();
    void testMatrixMultiplication();
    void testMatrixScalarMultiplication();
    void testMatrixTranspose();
    void testMatrixDeterminant();
    void testMatrixInverse();
    void testMatrixEigenvalues();
    void testMatrixPrint();
};

void TestMatrix::testMatrixConstruction()
{
    Matrix<double> mat1(2, 2);
    QCOMPARE(mat1.getRows(), static_cast<size_t>(2));
    QCOMPARE(mat1.getCols(), static_cast<size_t>(2));

    Matrix<double> mat2({{1.0, 2.0}, {3.0, 4.0}});
    QCOMPARE(mat2(0, 0), 1.0);
    QCOMPARE(mat2(0, 1), 2.0);
    QCOMPARE(mat2(1, 0), 3.0);
    QCOMPARE(mat2(1, 1), 4.0);
}

void TestMatrix::testMatrixAddition()
{
    Matrix<double> mat1({{1.0, 2.0}, {3.0, 4.0}});
    Matrix<double> mat2({{5.0, 6.0}, {7.0, 8.0}});
    Matrix<double> result = mat1 + mat2;

    QCOMPARE(result(0, 0), 6.0);
    QCOMPARE(result(0, 1), 8.0);
    QCOMPARE(result(1, 0), 10.0);
    QCOMPARE(result(1, 1), 12.0);
}

void TestMatrix::testMatrixSubtraction()
{
    Matrix<double> mat1({{5.0, 6.0}, {7.0, 8.0}});
    Matrix<double> mat2({{1.0, 2.0}, {3.0, 4.0}});
    Matrix<double> result = mat1 - mat2;

    QCOMPARE(result(0, 0), 4.0);
    QCOMPARE(result(0, 1), 4.0);
    QCOMPARE(result(1, 0), 4.0);
    QCOMPARE(result(1, 1), 4.0);
}

void TestMatrix::testMatrixMultiplication()
{
    Matrix<double> mat1({{1.0, 2.0}, {3.0, 4.0}});
    Matrix<double> mat2({{2.0, 0.0}, {1.0, 2.0}});
    Matrix<double> result = mat1 * mat2;

    QCOMPARE(result(0, 0), 4.0);
    QCOMPARE(result(0, 1), 4.0);
    QCOMPARE(result(1, 0), 10.0);
    QCOMPARE(result(1, 1), 8.0);
}

void TestMatrix::testMatrixScalarMultiplication()
{
    Matrix<double> mat({{1.0, 2.0}, {3.0, 4.0}});
    Matrix<double> result = mat * 2.0;

    QCOMPARE(result(0, 0), 2.0);
    QCOMPARE(result(0, 1), 4.0);
    QCOMPARE(result(1, 0), 6.0);
    QCOMPARE(result(1, 1), 8.0);
}

void TestMatrix::testMatrixTranspose()
{
    Matrix<double> mat({{1.0, 2.0}, {3.0, 4.0}});
    Matrix<double> result = mat.transpose();

    QCOMPARE(result(0, 0), 1.0);
    QCOMPARE(result(0, 1), 3.0);
    QCOMPARE(result(1, 0), 2.0);
    QCOMPARE(result(1, 1), 4.0);
}

void TestMatrix::testMatrixDeterminant()
{
    Matrix<double> mat({{1.0, 2.0}, {3.0, 4.0}});
    QCOMPARE(mat.determinant(), -2.0);
}

void TestMatrix::testMatrixInverse()
{
    Matrix<double> mat({{1.0, 2.0}, {3.0, 4.0}});
    Matrix<double> result = mat.inverse();

    QCOMPARE(result(0, 0), -2.0);
    QCOMPARE(result(0, 1), 1.0);
    QCOMPARE(result(1, 0), 1.5);
    QCOMPARE(result(1, 1), -0.5);
}

bool TestMatrix::fuzzyCompare(double a, double b, double tolerance = 1e-6) {
    return std::fabs(a - b) < tolerance;
}

void TestMatrix::testMatrixEigenvalues()
{
    Matrix<double> mat({{1.0, 2.0}, {3.0, 4.0}});
    auto eigenvalues = mat.eigenvalues();

    std::vector<double> expectedEigenvalues = {-0.372281323, 5.372281323};

    QCOMPARE(eigenvalues.size(), expectedEigenvalues.size());

    for (size_t i = 0; i < eigenvalues.size(); ++i) {
        QVERIFY(fuzzyCompare(eigenvalues[i], expectedEigenvalues[i]));
    }
}

void TestMatrix::testMatrixPrint()
{
    Matrix<double> mat({{1.0, 2.0}, {3.0, 4.0}});
    QString output = QString::fromStdString(mat.print());

    QString expectedOutput = "1.000 2.000 \n3.000 4.000 \n";
    QCOMPARE(output, expectedOutput);
}

QTEST_MAIN(TestMatrix)
#include "test_matrix.moc"
