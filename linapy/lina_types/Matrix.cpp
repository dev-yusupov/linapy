#include "../include/types.hpp"

template <typename T>
types::Matrix<T>::Matrix(const std::vector<std::vector<T>>& data) {
    if (data.empty() || data[0].empty()) {
        throw std::invalid_argument("Matrix constructor: data is empty or improperly formatted");
    }

    numberOfRows = data.size();
    numberOfColumns = data[0].size();

    for (const auto& row : data) {
        if (row.size() != numberOfColumns) {
            throw std::invalid_argument("Matrix constructor: inconsistent row sizes");
        }
        this->getData().push_back(Array<T>(row));
    }
}

template <typename T>
size_t types::Matrix<T>::rows() const {
    return numberOfRows;
}

template <typename T>
size_t types::Matrix<T>::columns() const {
    return numberOfColumns;
}

template <typename T>
T& types::Matrix<T>::operator()(size_t row, size_t column) {
    if (row >= numberOfRows || column >= numberOfColumns) {
        throw std::out_of_range("Matrix::operator(): index out of range");
    }
    return this->getData()[row][column];
}

template <typename T>
const T& types::Matrix<T>::operator()(size_t row, size_t column) const {
    if (row >= numberOfRows || column >= numberOfColumns) {
        throw std::out_of_range("Matrix::operator(): index out of range");
    }
    return this->getData()[row][column];
}

template <typename T>
void types::Matrix<T>::display() const {
    for (const auto& row : this->getData()) {
        row.display();
    }
}

template <typename T>
void types::Matrix<T>::set(size_t row, size_t column, T value) const {
    if (row >= numberOfRows || column >= numberOfColumns) {
        throw std::out_of_range("Matrix::set(): index out of range");
    }

    this->getData()[row].set(column, value);
}
