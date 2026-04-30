#include "largest_rectangle.h"

#include <iostream>
#include <vector>
#include <chrono>
#include <random>

template <typename Func>
long long measure_us(Func&& func) {
    const auto inicio = std::chrono::steady_clock::now();
    func();
    const auto fin = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
}

std::vector<int> generateAscending(int n) {
    std::vector<int> data(n);
    for(int i = 0 ; i < n ; i++){
        data[i] = i + 1;
    }
    return data;
}

std::vector<int> generateDescending(int n) {
    std::vector<int> data(n);
    for(int i = n ; i > 0 ; i--){
        data[i - 1] = i;
    }
    return data;
}

std::vector<int> generateRandom(int n) {
    std::vector<int> data(n);
    std::mt19937 rng(42); // Semilla fija para que el test sea repetible
    std::uniform_int_distribution<int> dist(1, 10000);
    for (int i = 0; i < n; i++) {
        data[i] = dist(rng);
    }
    return data;
}

int main() {
    constexpr int n = 100000;
    std::vector<int> datos = generateRandom(n);

    auto inicio_opt = std::chrono::steady_clock::now();
    int resultado_opt = largestRectangleArea(datos);
    auto fin_opt = std::chrono::steady_clock::now();
    auto duracion_opt = std::chrono::duration_cast<std::chrono::milliseconds>(fin_opt - inicio_opt).count();
    
    std::cout << "\nArreglo Random\n";
    std::cout << "Resultado: " << resultado_opt << "\n";
    std::cout << "Tiempo CPU: " << duracion_opt << " ms\n";

    datos = generateAscending(n);

    inicio_opt = std::chrono::steady_clock::now();
    resultado_opt = largestRectangleArea(datos);
    fin_opt = std::chrono::steady_clock::now();
    duracion_opt = std::chrono::duration_cast<std::chrono::milliseconds>(fin_opt - inicio_opt).count();

    std::cout << "\nArreglo Ascendente\n";
    std::cout << "Resultado: " << resultado_opt << "\n";
    std::cout << "Tiempo CPU: " << duracion_opt << " ms\n";

    datos = generateDescending(n);

    inicio_opt = std::chrono::steady_clock::now();
    resultado_opt = largestRectangleArea(datos);
    fin_opt = std::chrono::steady_clock::now();
    duracion_opt = std::chrono::duration_cast<std::chrono::milliseconds>(fin_opt - inicio_opt).count();

    std::cout << "\nArreglo Descendente\n";
    std::cout << "Resultado: " << resultado_opt << "\n";
    std::cout << "Tiempo CPU: " << duracion_opt << " ms\n";

    std::cout << "\n\nBrute Force vs Stack Monotonica\n\n";
    constexpr int m = 10000;
    auto dato = generateRandom(m);
    auto t_opt = measure_us([&]{ largestRectangleArea(dato); });
    std::cout << "n=" << m << ", Optimal:" << t_opt << "\n";
    auto t_bf = measure_us([&]{ largestRectangleBruteForce(dato); });
    std::cout << "n=" << m << ", BruteForce: " << t_bf << "\n";
    
    return 0;
}