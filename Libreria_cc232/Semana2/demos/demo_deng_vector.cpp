#include <iostream>
#include "DengVector.h"

namespace {

void increaseByOne(int& x) {
    ++x;
}

struct MultiplyByTwo {
    void operator()(int& x) const {
        x *= 2;
    }
};

} // namespace

int main() {
    ods::DengVector<int> v;

    for (int i = 0; i < 8; ++i) {
        v.insert(v.size(), i * 10);
        std::cout << "insert(" << i * 10 << ") -> size=" << v.size()
                  << ", capacity=" << v.capacity() << "\n";
    }

    v.insert(2, 99);
    std::cout << "Luego de insert(2, 99): ";
    for (int i = 0; i < v.size(); ++i) {
        std::cout << v[i] << (i + 1 < v.size() ? ' ' : '\n');
    }

    std::cout << "remove(3) = " << v.remove(3) << "\n";
    std::cout << "remove(1, 3) elimina " << v.remove(1, 3) << " elementos\n";

    ods::DengVector<int> copia(v);
    ods::DengVector<int> asignado;
    asignado = copia;

    copia.traverse(increaseByOne);
    MultiplyByTwo mult;
    asignado.traverse(mult);

    std::cout << "Copia + increaseByOne: ";
    for (int i = 0; i < copia.size(); ++i) {
        std::cout << copia[i] << (i + 1 < copia.size() ? ' ' : '\n');
    }

    std::cout << "Asignado * 2: ";
    for (int i = 0; i < asignado.size(); ++i) {
        std::cout << asignado[i] << (i + 1 < asignado.size() ? ' ' : '\n');
    }

    std::cout << "find(50) = " << asignado.find(50) << "\n";
    std::cout << "Estado final -> size=" << asignado.size()
              << ", capacity=" << asignado.capacity() << "\n";

    std::cout << "\n Ejercicio 2.3 \n";
    ods::DengVector<int> a;
    a.insert(0, 10);
    a.insert(1, 20);
    std::cout << "insert 10 y 20 en a (a[0] = 10, a[1] = 20)\n";

    ods::DengVector<int> b = a; // aqui se usa el copyFrom
    std::cout << "Copia a en b...\n";
    std::cout << "se establece a[0] = 99, lo cual no debería afectar a b[0] \n";
    a[0] = 99;                  // modifica solo el original

    std::cout << "a[0] = " << a[0] << ", b[0] = " << b[0] << "\n";
    std::cout << "Esperado: a[0] = 99 y b[0] = 10\n";

    return 0;
}
