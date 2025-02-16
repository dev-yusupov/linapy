#include "../include/types.hpp"

template <typename T>
types::Vector<T>::Vector(const std::vector<T>& data) {
    if (data.empty()) {
        throw std::invalid_argument("Vector constructor: data is empty");
    }

    numberOfElements = data.size();
    this->getData() = data;
}

template <typename T>
size_t types::Vector<T>::size() const {
    return numberOfElements;
}

template <typename T>
T& types::Vector<T>::operator()(size_t index) {
    if (index >= numberOfElements) {
        throw std::out_of_range("Vector::operator(): index out of range");
    }
    return this->getData()[index];
}

template <typename T>
const T& types::Vector<T>::operator()(size_t index) const {
    if (index >= numberOfElements) {
        throw std::out_of_range("Vector::operator(): index out of range");
    }
    return this->getData()[index];
}

template <typename T>
void types::Vector<T>::display() const {
    for (const auto& element : this->getData()) {
        std::cout << element << std::endl;
    }
}
