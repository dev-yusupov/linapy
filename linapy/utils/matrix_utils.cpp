/*

Implementation of matrix_utils.h

*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <type_traits>

#include "types.hpp"
#include "matrix_utils.hpp"

/**
 * @brief Transposes the given matrix.
 *
 * @tparam T The type of the matrix elements.
 * @param matrix The matrix to transpose.
 * @return Matrix<T> The transposed matrix.
 */

template <typename T>
types::Matrix<T> transpose(const types::Matrix<T>& matrix) {
    size_t rows = matrix.rows();
    size_t columns = matrix.columns();

    std::vector<std::vector<T>> transposed_matrix_data(columns, std::vector<T>(rows));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            transposed_matrix_data[j][i] = matrix(i, j);
        }
    }

    return Matrix<T>(transposed_matrix_data);
}

/**
 * @brief Adds two matrices.
 * 
 * @tparam T The type of the matrix elements. Must be a numerical type.
 * @param matrix1 The first matrix.
 * @param matrix2 The second matrix.
 * @return Matrix<T> The resulting matrix after addition.
 * @throws std::invalid_argument if the matrices have different dimensions.
 */
template <typename T>
types::Matrix<T> add(const types::Matrix<T>& matrix1, const types::Matrix<T>& matrix2) {
    static_assert(std::is_arithmetic<T>::value, "Matrix elements must be of a numerical type.");

    if (matrix1.rows() != matrix2.rows() || matrix1.columns() != matrix2.columns()) {
        throw std::invalid_argument("Matrices must have the same dimensions for addition.");
    }

    size_t rows = matrix1.rows();
    size_t columns = matrix1.columns();

    std::vector<std::vector<T>> result_matrix_data(rows, std::vector<T>(columns));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result_matrix_data[i][j] = matrix1(i, j) + matrix2(i, j);
        }
    }

    return Matrix<T>(result_matrix_data);
}

/**
 * @brief Subtracts two matrices.
 * 
 * @tparam T The type of the matrix elements. Must be a numerical type.
 * @param matrix1 The first matrix.
 * @param matrix2 The second matrix.
 * @return Matrix<T> The resulting matrix after subtraction.
 * @throws std::invalid_argument if the matrices have different dimensions.
 */

template <typename T>
types::Matrix<T> subtract(const types::Matrix<T>& matrix1, const types::Matrix<T>& matrix2) {
    static_assert(std::is_arithmetic<T>::value, "Matrix elements must be of a numerical type.");

    if (matrix1.rows() != matrix2.rows() || matrix1.columns() != matrix2.columns()) {
        throw std::invalid_argument("Matrices must have the same dimensions for subtraction.");
    }

    size_t rows = matrix1.rows();
    size_t columns = matrix1.columns();

    std::vector<std::vector<T>> result_matrix_data(rows, std::vector<T>(columns));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result_matrix_data[i][j] = matrix1(i, j) - matrix2(i, j);
        }
    }

    return Matrix<T>(result_matrix_data);
}

/**
 * @brief Multiplies two matrices using Blocked Matrix Multiplication. 
 * (O(n^3) but optimal for large matrices and cache efficient)
 * 
 * @tparam T The type of the matrix elements. Must be a numerical type.
 * @param matrix1 The first matrix.
 * @param matrix2 The second matrix.
 * @return Matrix<T> The resulting matrix after multiplication.
 * @throws std::invalid_argument if the matrices have incompatible dimensions.
 */

#define BLOCK_SIZE 32

template <typename T>
types::Matrix<T> multiply(const types::Matrix<T>& matrix1, const types::Matrix<T>& matrix2) {
    static_assert(std::is_arithmetic<T>::value, "Matrix elements must be of a numerical type.");

    if (matrix1.columns() != matrix2.rows()) {
        throw std::invalid_argument("Matrices have incompatible dimensions for multiplication.");
    }

    size_t rows = matrix1.rows();
    size_t columns = matrix2.columns();
    size_t common_dim = matrix1.columns();

    std::vector<std::vector<T>> result_matrix_data(rows, std::vector<T>(columns));

    for (size_t i = 0; i < rows; i += BLOCK_SIZE) {
        for (size_t j = 0; j < columns; j += BLOCK_SIZE) {
            for (size_t k = 0; k < common_dim; k += BLOCK_SIZE) {
                for (size_t ii = i; ii < std::min(i + BLOCK_SIZE, rows); ++ii) {
                    for (size_t jj = j; jj < std::min(j + BLOCK_SIZE, columns); ++jj) {
                        for (size_t kk = k; kk < std::min(k + BLOCK_SIZE, common_dim); ++kk) {
                            result_matrix_data[ii][jj] += matrix1(ii, kk) * matrix2(kk, jj);
                        }
                    }
                }
            }
        }
    }

    return Matrix<T>(result_matrix_data);
}

/**
 * @brief Multiplies a matrix by a scalar.
 * 
 * @tparam T The type of the matrix elements. Must be a numerical type.
 * @param matrix The matrix.
 * @param scalar The scalar value.
 * @return Matrix<T> The resulting matrix after scalar multiplication.
 */

template <typename T>
types::Matrix<T> scalar_multiply(const types::Matrix<T>& matrix, const T& scalar) {
    static_assert(std::is_arithmetic<T>::value, "Matrix elements must be of a numerical type.");

    size_t rows = matrix.rows();
    size_t columns = matrix.columns();

    std::vector<std::vector<T>> result_matrix_data(rows, std::vector<T>(columns));

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            result_matrix_data[i][j] = matrix(i, j) * scalar;
        }
    }

    return Matrix<T>(result_matrix_data);
}

/**
 * @brief Calculates the determinant of a 2x2 matrix.
 * 
 * @tparam T The type of the matrix elements. Must be a numerical type.
 * @param matrix1 The first matrix.
 * @param matrix2 The second matrix.
 * @return Matrix<T> The determinant of the matrix.
 * @throws std::invalid_argument if the matrix is not 2x2.
 */

template <typename T>
types::Matrix<T> determinant(const types::Matrix<T>& matrix1, const types::Matrix<T>& matrix2) {
    static_assert(std::is_arithmetic<T>::value, "Matrix elements must be of a numerical type.");

    if (matrix1.rows() != 2 || matrix1.columns() != 2) {
        throw std::invalid_argument("Matrix must be 2x2 for determinant calculation.");
    }

    return matrix1(0, 0) * matrix2(1, 1) - matrix1(1, 0) * matrix2(0, 1);
}