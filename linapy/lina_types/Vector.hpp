#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

#include "Array.hpp"

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

#include "Vector.cpp"
#endif