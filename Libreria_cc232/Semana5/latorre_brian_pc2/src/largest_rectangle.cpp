#include "largest_rectangle.h"
#include <vector>

bool isLarger(int area1, int area2) {
    if(area1 > area2){
        return true;
    }
    return false;
}

int largestRectangleBruteForce(const std::vector<int>& height) {
    int maxArea = height[0];
    int rectangle;
    // Recorre todos los íncdices del vector "height"
    for(int i = 0 ; i < height.size(); i++){
        if(isLarger(height[i], maxArea)){
            maxArea = height[i];
        }
        
        // Empieza a scanear hacia la derecha calculando cada rectangulo posible a partir del indice "i"
        int minHeight = height[i]; 
        for(int j = i+1 ; j < height.size() ; j++ ){
            if(isLarger(height[j], minHeight)){ 
                rectangle = minHeight * (j - i + 1);
            } else { 
                minHeight = height[j];
                rectangle = minHeight * (j - i + 1);
            }
            if(isLarger(rectangle, maxArea)){
                maxArea = rectangle;
            }
        }
    }
    return maxArea;
}
