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
    T& operator()(size_t row, size_t column);
    const T& operator()(size_t row, size_t column) const;
    void display() const;
    void set(size_t row, size_t column, T value) const;
private:
    size_t numberOfRows;
    size_t numberOfColumns;
};

#include "Matrix.cpp"
#endif