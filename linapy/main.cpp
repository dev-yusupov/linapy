#include "lina_types/Array.hpp"
#include <iostream>

int main() {
    std::vector<int> data = {1, 2, 3, 4, 5};
    Array<int> arr(data);
    std::cout << arr[2] << std::endl;

    arr.set(2, 10);

    arr.display();
    return 0;
}
