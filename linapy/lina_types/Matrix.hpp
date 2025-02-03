#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

#include "Array.hpp"

template <typename T>
class Matrix : public Array<Array<T>> {
public:
    Matrix(const std::vector<std::vector<T>>& data);
    size_t rows() const;
    size_t columns() const;
    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;
    void display() const;

private:
    size_t numRows;
    size_t numCols;
};

#include "Matrix.cpp"
#endif