#include <iostream>
#include <vector>
#include "largest_rectangle.h"

int main() {
    std::vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    std::vector<int> heights2 = {2, 4};
    std::cout << "| Primer Histograma LeetCode: [2, 1, 5, 6, 2, 3] \n";
    std::cout << "El rectangulo de mayor area por fuerza bruta es: " << largestRectangleBruteForce(heights1) << std::endl;
    std::cout << "| Segundo Histograma LeetCode: [2, 4] \n";
    std::cout << "El rectangulo de mayor area por fuerza bruta es: " << largestRectangleBruteForce(heights2) << std::endl;
    return 0;
}
