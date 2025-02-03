#include <iostream>
#include <vector>

#include "lina_types/Matrix.hpp"
#include "utils/matrix_utils.hpp"

int main() {
    std::vector<std::vector<int>> data = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> data2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Matrix<int> mat1(data);
    Matrix<int> mat2(data2);

    mat1.display();

    std::cout << std::endl;

    mat2.display();

    std::cout << std::endl;

    Matrix<int> mat3 = multiply(mat1, mat2);

    mat3.display();
    
    return 0;
}