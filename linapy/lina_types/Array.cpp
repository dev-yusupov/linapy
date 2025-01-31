#include "Array.hpp"

template <typename T>
Array<T>::Array(const std::vector<T>& data) : data(data) {
    if (data.empty()) {
        throw std::invalid_argument("Array constructor: data is empty");
    }
}

template <typename T>
size_t Array<T>::size() const {
    return data.size();
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= data.size()) {
        throw std::out_of_range("Array::operator[]: index out of range");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= data.size()) {
        throw std::out_of_range("Array::operator[]: index out of range");
    }
    return data[index];
}

template <typename T>
void Array<T>::display() const {
    for (const T& elem : data) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
