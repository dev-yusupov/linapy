/*

Utility functions for matrix operations

*/

#ifndef LINAPY_UTILS_MATRIX_UTILS_HPP
#define LINAPY_UTILS_MATRIX_UTILS_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>

#include "../lina_types/Matrix.hpp"

template <typename T>
Matrix<T> transpose(const Matrix<T>& matrix);

template <typename T>
Matrix<T> add(const Matrix<T>& matrix1, const Matrix<T>& matrix2);

template <typename T>
Matrix<T> subtract(const Matrix<T>& matrix1, const Matrix<T>& matrix2);

template <typename T>
Matrix<T> multiply(const Matrix<T>& matrix1, const Matrix<T>& matrix2);

template <typename T>
Matrix<T> scalar_multiply(const Matrix<T>& matrix, const T& scalar);

template <typename T>
Matrix<T> determinant(const Matrix<T>& matrix1, const Matrix<T>& matrix2);

#include "matrix_utils.cpp"

#endif