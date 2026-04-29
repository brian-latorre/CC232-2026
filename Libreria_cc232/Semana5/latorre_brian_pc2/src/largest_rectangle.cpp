#include "largest_rectangle.h"
#include <vector>
#include <stack>

bool isLarger(int area1, int area2) {
    if(area1 > area2){
        return true;
    }
    return false;
}

int largestRectangleBruteForce(const std::vector<int>& heights) {
    int maxArea = heights[0];
    int rectangle;
    // Recorre todos los íncdices del vector "heights"
    for(int i = 0 ; i < heights.size(); i++){
        if(isLarger(heights[i], maxArea)){
            maxArea = heights[i];
        }
        
        // Empieza a scanear hacia la derecha calculando cada rectangulo posible a partir del indice "i"
        int minHeight = heights[i]; 
        for(int j = i+1 ; j < heights.size() ; j++ ){
            if(isLarger(heights[j], minHeight)){ 
                rectangle = minHeight * (j - i + 1);
            } else { 
                minHeight = heights[j];
                rectangle = minHeight * (j - i + 1);
            }
            if(isLarger(rectangle, maxArea)){
                maxArea = rectangle;
            }
        }
    }
    return maxArea;
}

int largestRectangle(const std::vector<int>& heights) {
    std::stack<int> indices;
    int maxRectangle = 0;
    int NSL, NSR, height, base, rectangle, heightIndex;
    for(int i = 0 ; i < heights.size() ; i++ ){ 

        while(!indices.empty() && heights[i] < heights[indices.top()]){
            NSR = i;
            heightIndex = indices.top();
            indices.pop();
            if(indices.empty()){
                NSL = -1;
            } else {
                NSL = indices.top();
            }
            height = heights[heightIndex];
            base = NSR - NSL - 1;
            rectangle = height * base; // heights[i] * (NSR - NSL - 1)
            if(isLarger(rectangle, maxRectangle)){
                maxRectangle = rectangle;
            }
        }
        indices.push(i);
    }
    
    NSR = heights.size();
    while(!indices.empty()){
        heightIndex = indices.top();
        indices.pop();
        if(indices.empty()){
            NSL = -1;
        } else {
            NSL = indices.top();
        }
        height = heights[heightIndex];
        base = NSR - NSL - 1;
        rectangle = height * base;
        if(isLarger(rectangle, maxRectangle)){
            maxRectangle = rectangle;
        }
    }
    return maxRectangle;
}