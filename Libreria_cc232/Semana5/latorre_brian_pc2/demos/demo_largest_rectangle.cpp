#include <iostream>
#include <vector>
#include "largest_rectangle.h"

int main() {
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::cout << "El rectangulo de mayor area por fuerza bruta es: " << largestRectangleBruteForce(heights) << std::endl;
    std::cout << "El rectangulo de mayor area por el algoritmo eficiente es: " << largestRectangle(heights) << std::endl;
    return 0;
}