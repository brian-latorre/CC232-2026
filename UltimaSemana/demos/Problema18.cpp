#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

#include "AVL.h"
#include "LinearHashTable.h"
#include "RedBlackTreeLLRB.h"


int main(){
    const int N = 20000;
    const int BE = 120000;
    const int BF = 4000;

    std::vector<int> keys;
    keys.reserve(N);

    for (int i = 1; i <= N; ++i){
        keys.push_back(i * 3);
    }

    ods::AVL<int> avl;
    ods::RedBlackTreeLLRB<int> rb;
    ods::LinearHashTable<int> hash(8);

    for (int x : keys){
        avl.insert(x);
        rb.add(x);
        hash.add(x);
    }

    std::vector<int> encontrados;
    encontrados.reserve(BE);
    for (int i = 0; i < BE; ++i) {
        encontrados.push_back(keys[i % N]);
    }

    std::vector<int> fallidos;
    fallidos.reserve(BF);
    for (int i = 0; i < BF; ++i) {
        fallidos.push_back(-(i + 1)); 
    }

    auto inicioAVL = std::chrono::high_resolution_clock::now();
    int avl_ok = 0;
    for (int x : encontrados) {
        if (avl.contains(x)) avl_ok++;
    }
    auto finAVL = std::chrono::high_resolution_clock::now();
    auto tiempoAVL = std::chrono::duration_cast<std::chrono::microseconds>(finAVL - inicioAVL).count();

    auto inicioRB = std::chrono::high_resolution_clock::now();
    int rb_ok = 0;
    for (int x : encontrados) {
        if (rb.contains(x)) rb_ok++;
    }
    auto finRB = std::chrono::high_resolution_clock::now();
    auto tiempoRB = std::chrono::duration_cast<std::chrono::microseconds>(finRB - inicioRB).count();

    auto inicioHash = std::chrono::high_resolution_clock::now();
    int hash_ok = 0;
    for (int x : encontrados) {
        if (hash.contains(x)) hash_ok++;
    }
    auto finHash = std::chrono::high_resolution_clock::now();
    auto tiempoHash = std::chrono::duration_cast<std::chrono::microseconds>(finHash - inicioHash).count();

    int avl_fail = 0, rb_fail = 0, hash_fail = 0;
    for (int x : fallidos) { //Si no encuentra, no va a incrementar
        if (avl.contains(x)) avl_fail++;
        if (rb.contains(x)) rb_fail++;
        if (hash.contains(x)) hash_fail++;
    }


    std::cout << "Tamanio de la coleccion de claves: " << N << "\n";

    std::cout << "\nBusquedas:\n";
    std::cout << "Consultas exitosas:\n";
    std::cout << "AVL=" << avl_ok << " RB=" << rb_ok << " Hash=" << hash_ok << "\n\n";

    std::cout << "Consultas en el vector fallidos encontradas:\n";
    std::cout << "AVL=" << avl_fail << " RB=" << rb_fail << " Hash=" << hash_fail << "\n";

    std::cout << "Tiempo exitosas AVL: " << tiempoAVL << " microsegundos\n";
    std::cout << "Tiempo exitosas RB: " << tiempoRB << " microsegundos\n";
    std::cout << "Tiempo exitosas Hash: " << tiempoHash << " microsegundos\n";

    std::vector<int> avlSorted = avl.inorder();
    std::vector<int> rbSorted = rb.inorder();

    int minAVL = avlSorted.front();
    int maxAVL = avlSorted.back();

    int minRB = rbSorted.front();
    int maxRB = rbSorted.back();

    std::cout << "\nMinimo y Maximo de cada estructura:\n";
    std::cout << "Minimo AVL:" << minAVL << ", Maximo AVL:" << maxAVL << "\n";
    std::cout << "Minimo RedBlack:" << minRB << ", Maximo RedBlack:" << maxRB << "\n";

    std::vector<std::pair<int, int>> rangos;
    rangos.push_back({300, 900});
    rangos.push_back({1500, 3000});
    rangos.push_back({10000, 20000});

        
    for (const auto& [a, b] : rangos) {
        auto itAVL1 = std::lower_bound(avlSorted.begin(), avlSorted.end(), a); // busca posicion
        auto itAVL2 = std::upper_bound(avlSorted.begin(), avlSorted.end(), b);
        int cantidadAVL = static_cast<int>(itAVL2 - itAVL1);

        auto itRB1 = std::lower_bound(rbSorted.begin(), rbSorted.end(), a);
        auto itRB2 = std::upper_bound(rbSorted.begin(), rbSorted.end(), b);
        int cantidadRB = static_cast<int>(itRB2 - itRB1);

        std::cout << "\n";
        std::cout << "Consulta por Rangos";
        std::cout << "\n";
        std::cout << "[" << a << ", " << b << "] ";
        std::cout << "Cantidad de elementos: AVL=" << cantidadAVL << " RB=" << cantidadRB << "\n";
    }
}