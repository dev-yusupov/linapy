#include <gtest/gtest.h>
#include <vector>
#include <iostream>

#include "../../linapy/lina_types/Array.hpp"

TEST(ArrayTypeTest, ArrayInitialization) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Array<int> arr(vec);

    for (int i = 0; i < arr.size(); i++) {
        EXPECT_EQ(arr[i], vec[i]);
    }
}

TEST(ArrayTypeTest, ArrayCopy) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Array<int> arr(vec);
    Array<int> arr_copy = arr;

    for (int i = 0; i < arr.size(); i++) {
        EXPECT_EQ(arr[i], arr_copy[i]);
    }
}

TEST(ArrayTypeTest, ArraySize) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Array<int> arr(vec);

    EXPECT_EQ(arr.size(), vec.size());
}

TEST(ArrayTypeTest, ArrayIndexing) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Array<int> arr(vec);

    for (int i = 0; i < arr.size(); i++) {
        EXPECT_EQ(arr[i], vec[i]);
    }
}

TEST(ArrayTypeTest, ArrayIndexingOutOfBounds) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Array<int> arr(vec);

    EXPECT_THROW(arr[arr.size()], std::out_of_range);
}

TEST(ArrayTypeTest, ArrayIndexingConst) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    const Array<int> arr(vec);

    for (int i = 0; i < arr.size(); i++) {
        EXPECT_EQ(arr[i], vec[i]);
    }
}

TEST(ArrayTypeTest, ArrayIndexingConstOutOfBounds) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    const Array<int> arr(vec);

    EXPECT_THROW(arr[arr.size()], std::out_of_range);
}

TEST(ArrayTypeTest, ArraySet) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Array<int> arr(vec);

    arr.set(0, 10);
    EXPECT_EQ(arr[0], 10);
}

TEST(ArrayTypeTest, ArraySetOutOfBounds) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    Array<int> arr(vec);

    EXPECT_THROW(arr.set(arr.size(), 10), std::out_of_range);
}
