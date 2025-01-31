#ifndef ARRAY_HPP   
#define ARRAY_HPP

#include <iostream>
#include <vector>
#include <type_traits>
#include <stdexcept>

template <typename T>

class Array {
private:
    std::vector<T> data;
    
public:
    Array(const std::vector<T>& data);

    size_t size() const;

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    void display() const;
};


#include "Array.cpp"
#endif