#include <gtest/gtest.h>
#include <vector>
#include <iostream>

#include "../../linapy/lina_types/Array.hpp"

TEST(Array, TestArrayInitialization) {
    std::vector<int> arr = {1, 2, 3};
    Array<int> a(arr);

    EXPECT_EQ(a.size(), 3);
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
    EXPECT_EQ(a[2], 3);
}

TEST(Array, TestArrayCopy) {
    std::vector<int> arr = {1, 2, 3};
    Array<int> a(arr);
    Array<int> b = a;

    EXPECT_EQ(b.size(), 3);
    EXPECT_EQ(b[0], 1);
    EXPECT_EQ(b[1], 2);
    EXPECT_EQ(b[2], 3);
}

TEST(Array, TestArraySize) {
    std::vector<int> arr = {1, 2, 3};
    Array<int> a(arr);

    EXPECT_EQ(a.size(), 3);
}