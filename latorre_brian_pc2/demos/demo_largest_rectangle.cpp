#include <iostream>
#include <vector>
#include "largest_rectangle.h"

int main() {
    std::vector<int> heights1 = {2, 1, 5, 6, 2, 3};
    std::vector<int> heights2 = {2, 4};
    std::cout << "| Primer Histograma LeetCode: [2, 1, 5, 6, 2, 3] \n";
    std::cout << largestRectangleArea(heights1) << std::endl;
    std::cout << " es el mayor area del histograma. " << std::endl; // valor esperado: 10
    std::cout << "| Segundo Histograma LeetCode: [2, 4] \n";
    std::cout << "El rectangulo de mayor area por el algoritmo eficiente es: " << largestRectangleArea(heights2) << std::endl; // valor esperado: 4
    return 0;
}
