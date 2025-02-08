#include <gtest/gtest.h>
#include <vector>
#include <iostream>

#include "../../linapy/lina_types/Vector.hpp"

TEST(VectorTypeTest, VectorInitialization) {
    std::vector<int> vec = {1, 2, 3};
    Vector<int> v(vec);

    for (int i = 0; i < v.size(); i++) {
        EXPECT_EQ(v[i], vec[i]);
    }
}

TEST(VectorTypeTest, VectorCopy) {
    std::vector<int> vec = {1, 2, 3};
    Vector<int> v(vec);
    Vector<int> v_copy = v;

    for (int i = 0; i < v.size(); i++) {
        EXPECT_EQ(v[i], v_copy[i]);
    }
}

TEST(VectorTypeTest, VectorIndexing) {
    std::vector<int> vec = {1, 2, 3};
    Vector<int> v(vec);

    for (int i = 0; i < v.size(); i++) {
        EXPECT_EQ(v(i), vec[i]);
    }
}

TEST(VectorTypeTest, VectorIndexingOutOfBounds) {
    std::vector<int> vec = {1, 2, 3};
    Vector<int> v(vec);

    EXPECT_THROW(v(v.size()), std::out_of_range);
}

TEST(VectorTypeTest, VectorIndexingConst) {
    std::vector<int> vec = {1, 2, 3};
    const Vector<int> v(vec);

    for (int i = 0; i < v.size(); i++) {
        EXPECT_EQ(v(i), vec[i]);
    }
}

TEST(VectorTypeTest, VectorDisplay) {
    std::vector<int> vec = {1, 2, 3};
    Vector<int> v(vec);

    testing::internal::CaptureStdout();
    v.display();
    std::string output = testing::internal::GetCapturedStdout();

    std::string expected_output = "1\n2\n3\n";
    EXPECT_EQ(output, expected_output);
}

TEST(VectorTypeTest, VectorSet) {
    std::vector<int> vec = {1, 2, 3};
    Vector<int> v(vec);

    v.set(0, 10);
    EXPECT_EQ(v(0), 10);
}

