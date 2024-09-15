#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iostream>
#include <stdexcept>
#include <sstream>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows, size_t cols);
    Matrix(const std::vector<std::vector<T>>& values);

    T& operator ()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;

    size_t getRows() const;
    size_t getCols() const;

    Matrix<T> operator+(const Matrix<T>& other) const;
    Matrix<T> operator-(const Matrix<T>& other) const;
    Matrix<T> operator*(const Matrix<T>& other) const;
    Matrix<T> operator*(const T& scalar) const;

    std::string print() const;
};

#endif // MATRIX_H
