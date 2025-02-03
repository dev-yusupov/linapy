#include "Matrix.hpp"

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& data) {
    if (data.empty() || data[0].empty()) {
        throw std::invalid_argument("Matrix constructor: data is empty or improperly formatted");
    }

    numRows = data.size();
    numCols = data[0].size();

    for (const auto& row : data) {
        if (row.size() != numCols) {
            throw std::invalid_argument("Matrix constructor: inconsistent row sizes");
        }
        this->getData().push_back(Array<T>(row));
    }
}

template <typename T>
size_t Matrix<T>::rows() const {
    return numRows;
}

template <typename T>
size_t Matrix<T>::columns() const {
    return numCols;
}

template <typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    if (row >= numRows || col >= numCols) {
        throw std::out_of_range("Matrix::operator(): index out of range");
    }
    return this->getData()[row][col];
}

template <typename T>
const T& Matrix<T>::operator()(size_t row, size_t col) const {
    if (row >= numRows || col >= numCols) {
        throw std::out_of_range("Matrix::operator(): index out of range");
    }
    return this->getData()[row][col];
}

template <typename T>
void Matrix<T>::display() const {
    for (const auto& row : this->getData()) {
        row.display();
    }
}
