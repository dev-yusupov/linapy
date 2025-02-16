#ifndef TYPES_HPP
#define TYPES_HPP

#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

namespace types {

template <typename T>
class Array 
{

/*
    Array class template that wraps around a std::vector<T> and provides a subscript operator to access elements.
    The subscript operator throws an std::out_of_range exception if the index is out of bounds.

    Attributes:
        data (std::vector<T>): The vector that stores the elements of the array.

    Methods:
        Array(const std::vector<T>& data): Constructor that initializes the array with the given data.
        size() const: Returns the number of elements in the array.
        operator[](size_t index): Returns a reference to the element at the given index.
        operator[](size_t index) const: Returns a const reference to the element at the given index.
        display() const: Prints the elements of the array to the standard output.

    Example:
        std::vector<int> data = {1, 2, 3, 4, 5}; // Create a vector with some data
        Array<int> arr(data); // Initialize the array with the data
        std::cout << arr[2] << std::endl; // Output: 3
        arr.display(); // Output: 1 2 3 4 5
*/

protected:
    std::vector<T>& getData();
    const std::vector<T>& getData() const;

private:
    std::vector<T> data;
    
public:
    Array();
    Array(const std::vector<T>& data);

    size_t size() const;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    void set(size_t index, const T& value);

    void display() const;
};

template <typename T>
class Vector : public Array<T> {
public:
    Vector(const std::vector<T>& data);
    size_t size() const;
    T& operator()(size_t index);
    const T& operator()(size_t index) const;
    void display() const;

private:
    size_t numberOfElements;
};

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

}

#include "linapy/lina_types/Array.cpp"
#include "linapy/lina_types/Vector.cpp"
#include "linapy/lina_types/Matrix.cpp"

#endif
