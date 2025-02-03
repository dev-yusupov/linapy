#include "Array.hpp"

template <typename T>
Array<T>::Array() {
    // Default constructor
}

template <typename T>
Array<T>::Array(const std::vector<T>& data) : data(data) {
    /*
    Constructor that initializes the array with the given data.

    Args:
        data (std::vector<T>): The vector containing the elements to be stored in the array.
    
    Raises:
        std::invalid_argument: If the data vector is empty.
     */
    if (data.empty()) {
        throw std::invalid_argument("Array constructor: data is empty");
    }
}

template <typename T>
size_t Array<T>::size() const {
    /*
    Returns the number of elements in the array.
    */
    return data.size();
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    /**
     * Returns a reference to the element at the given index.
     * 
     * @param index The index of the element to access.
     * @return A reference to the element at the given index.
     * @throws std::out_of_range: If the index is out of bounds.
    */
    if (index >= data.size()) {
        throw std::out_of_range("Array::operator[]: index out of range");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    /**
     * Returns a const reference to the element at the given index.
     * 
     * @param index The index of the element to access.
     * @return A const reference to the element at the given index.
     * @throws std::out_of_range: If the index is out of bounds.
    */
    if (index >= data.size()) {
        throw std::out_of_range("Array::operator[]: index out of range");
    }

    return data[index];
}

template <typename T>
void Array<T>::set(size_t index, const T& value) {
    /**
     * Sets the value of the element at the given index.
     * 
     * @param index The index of the element to set.
     * @param value The value to set.
     * @return void
     * @throws std::out_of_range: If the index is out of bounds.
     */
    if (index >= data.size()) {
        throw std::out_of_range("Array::set: index out of range");
    }
    data[index] = value;
}

template <typename T>
void Array<T>::display() const {
    /**
     * Prints the elements of the array to the standard output.
     * 
     * @return void
     */
    for (const T& elem : data) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::vector<T>& Array<T>::getData() {
    return data;
}

template <typename T>
const std::vector<T>& Array<T>::getData() const {
    return data;
}
