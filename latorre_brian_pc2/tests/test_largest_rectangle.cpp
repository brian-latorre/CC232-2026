#include "largest_rectangle.h"
#include <iostream>
#include <vector>
#include <cassert>

void test_general_case(){
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    assert(largestRectangleArea(heights) == 10);
}

void test_repeated_case(){
    std::vector<int> heights = {2, 2, 2, 2};
    assert(largestRectangleArea(heights) == 8);
}

void test_empty_case(){
    std::vector<int> heights = {};
    assert(largestRectangleArea(heights) == 0);
}

void test_leetcode_example2() {
    std::vector<int> heights = {2, 4};
    assert(largestRectangleArea(heights) == 4);
}

void test_ascending() {
    std::vector<int> heights = {1, 2, 3, 4, 5};
    assert(largestRectangleArea(heights) == 9); // altura 3, ancho 3
}

void test_valley() {
    std::vector<int> heights = {6, 2, 5, 4, 5, 1, 6};
    assert(largestRectangleArea(heights) == 12);
}

int main(){
    std::cout << "Ejecutando pruebas \n";
    test_general_case();
    test_repeated_case();
    test_empty_case();
    test_leetcode_example2();
    test_ascending();
    test_valley();
    std::cout << "Pruebas realizadas con exito\n";
    return 0;
}