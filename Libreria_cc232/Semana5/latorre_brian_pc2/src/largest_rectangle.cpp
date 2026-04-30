#include "largest_rectangle.h"
#include <vector>
#include <stack>
#include <algorithm>

int largestRectangleBruteForce(const std::vector<int>& heights) {

    int maxArea = 0;
    int rectangle;
    // Recorre todos los íncdices del vector "heights"
    for(int i = 0 ; i < heights.size(); i++){
        maxArea = std::max(maxArea, heights[i]); 
        // Empieza a scanear hacia la derecha calculando cada rectangulo posible a partir del indice "i"
        int minHeight = heights[i]; 
        for(int j = i+1 ; j < heights.size() ; j++ ){
            if(heights[j] > minHeight){ 
                rectangle = minHeight * (j - i + 1);
            } else { 
                minHeight = heights[j];
                rectangle = minHeight * (j - i + 1);
            }
            if(rectangle > maxArea){
                maxArea = rectangle;
            }
        }
    }
    return maxArea;
}

int largestRectangleArea(const std::vector<int>& heights) {
    std::stack<int> indices;
    int maxRectangle = 0;
    for(int i = 0 ; i < heights.size() ; i++ ){ 
        
        while(!indices.empty() && heights[i] < heights[indices.top()]){
            int NSL, NSR, height, base, rectangle, heightIndex;

            heightIndex = indices.top(); indices.pop(); //Obtiene y retira el índice de la pila
            height = heights[heightIndex]; // Altura del índice sacado (altura del rectángulo)

            NSR = i; // Límite derecho

            // Determina índice izquierdo (incluyendo caso borde izquierdo)
            NSL = indices.empty() ? -1 : indices.top();

            base = NSR - NSL - 1; // cálculo de la base

            rectangle = height * base; // cálculo del rectángulo: heights[i] * (NSR - NSL - 1)

            // Determinar si este es el máximo encontrado hasta el momento (pero si será el máximo con esa altura)
            maxRectangle = std::max(maxRectangle, rectangle);
        }
        // Entra a la pila luego de haber limitado a los rectángulos anteriores o solamente entra por ser mayor que el top()
        indices.push(i);

    }
    
    // Los índices que queden en la pila, contemplan el caso borde derecho, ningún rectángulo del vector fueron menores que estos índices.
    while(!indices.empty()){
        int NSL, NSR, height, base, rectangle, heightIndex;
        NSR = heights.size();

        heightIndex = indices.top();
        indices.pop();

        NSL = indices.empty() ? -1 : indices.top();

        height = heights[heightIndex];
        base = NSR - NSL - 1;
        rectangle = height * base;

        maxRectangle = std::max(maxRectangle, rectangle);
    }

    return maxRectangle;
}