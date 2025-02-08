#include <gtest/gtest.h>
#include <vector>
#include <iostream>

#include "../../linapy/lina_types/Matrix.hpp"

TEST(MatrixTypeTest, MatrixInitialization) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(vec);

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            EXPECT_EQ(mat[i][j], vec[i][j]);
        }
    }
}

TEST(MatrixTypeTest, MatrixCopy) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(vec);
    Matrix<int> mat_copy = mat;

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            EXPECT_EQ(mat[i][j], mat_copy[i][j]);
        }
    }
}

TEST(MatrixTypeTest, MatrixRowAndColumns) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(vec);

    EXPECT_EQ(mat.rows(), vec.size());
    EXPECT_EQ(mat.columns(), vec[0].size());
}

TEST(MatrixTypeTest, MatrixIndexing) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(vec);

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            EXPECT_EQ(mat(i, j), vec[i][j]);
        }
    }
}

TEST(MatrixTypeTest, MatrixIndexingOutOfBounds) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(vec);

    EXPECT_THROW(mat(mat.rows(), mat.columns()), std::out_of_range);
}

TEST(MatrixTypeTest, MatrixIndexingConst) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    const Matrix<int> mat(vec);

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            EXPECT_EQ(mat(i, j), vec[i][j]);
        }
    }
}

TEST(MatrixTypeTest, MatrixIndexingConstOutOfBounds) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    const Matrix<int> mat(vec);

    EXPECT_THROW(mat(mat.rows(), mat.columns()), std::out_of_range);
}

TEST(MatrixTypeTest, MatrixSet) {
    std::vector<std::vector<int>> vec = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat(vec);

    mat(0, 0) = 10;
    EXPECT_EQ(mat(0, 0), 10);
}


