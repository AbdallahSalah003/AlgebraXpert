#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
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


template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols)
{
    this->data.resize(rows, std::vector<T>(cols));
}

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& values)
    : data(values), rows(values.size()), cols(values[0].size()) {}
template <typename T>
T& Matrix<T>::operator()(size_t row, size_t col)
{
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->data[row][col];
}

template <typename T>
const T& Matrix<T>::operator()(size_t row, size_t col) const
{
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return this->data[row][col];
}

template <typename T>
size_t Matrix<T>::getRows() const
{
    return this->rows;
}
template <typename T>
size_t Matrix<T>::getCols() const
{
    return this->cols;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    Matrix result(this->rows, this->cols);
    for(size_t i=0; i<this->rows; i++)
    {
        for(size_t j=0; j<this->cols; j++)
        {
            result(i, j) = data[i][j] + other(i, j);
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& other) const
{
    if (this->rows != other.rows || this->cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions must match");
    }
    Matrix result(this->rows, this->cols);
    for(size_t i=0; i<this->rows; i++)
    {
        for(size_t j=0; j<this->cols; j++)
        {
            result(i, j) = data[i][j] - other(i, j);
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& other) const
{
    if (this->cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions must be compatible for multiplication");
    }
    Matrix result(this->rows, other.cols);
    for(size_t i=0; i<this->rows; i++)
    {
        for(size_t j=0; j<other.cols; j++)
        {
            result(i, j) = 0;
            for (size_t k = 0; k < this->cols; ++k)
            {
                result(i, j) += data[i][k] * other(k, j);
            }
        }
    }
    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T& scalar) const
{
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result(i, j) = data[i][j] * scalar;
        }
    }
    return result;
}

template <typename T>
std::string Matrix<T>::print() const
{
    std::ostringstream stream;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            stream << data[i][j] << " ";
        }
        stream << "\n";
    }
    return stream.str();
}


#endif // MATRIX_H
