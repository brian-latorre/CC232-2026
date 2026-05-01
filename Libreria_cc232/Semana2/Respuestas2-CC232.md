### Ejercicio 1

1. El tiempo promedio depende de una entrada aleatoria; el amortizado reparte el costo de muchas operaciones.
2. En DengVector, una expansión copia el arreglo y hace cara una inserción puntual.
3. No se contradice con el amortizado porque varias inserciones baratas compensan las caras.
4. Duplicar capacidad reduce la frecuencia de expansiones y mantiene `O(1)` amortizado al insertar al final.
5. Si la capacidad creciera por una cantidad fija, las copias serían frecuentes y el costo amortizado empeora.

### Ejercicio 2

1. La copia debe tener memoria propia para evitar aliasing y doble liberación.
2. Ver [Semana2/demos/demo_deng_vector.cpp](Semana2/demos/demo_deng_vector.cpp).
3. La prueba muestra que cambiar `a` no cambia `b`.
4. Si compartieran el arreglo interno, cambiar uno afectaría al otro y podría haber `delete[]` duplicado.

### Ejercicio 3

1. [Semana2/include/expandDengVector.h](Semana2/include/expandDengVector.h) usa crecimiento fijo en lugar de duplicación.
2. La interfaz se mantiene; cambia la política de `expand()`.
3. Con crecimiento fijo hay más expansiones y más copias.
4. Por eso el costo amortizado es peor que con duplicación.
5. Con crecimiento 4, las capacidades suben 3, 7, 11, 15...; con duplicación, 3, 6, 12, 24...

### Ejercicio 4

1. `shrink()` se usa cuando hay suficiente espacio ocioso.
2. En DengVector solo reduce si `_size * 4 <= _capacity` y respeta un mínimo.
3. No conviene reducir en cada borrado por el costo de copiar repetidamente.
4. El costo amortizado sigue siendo `O(1)` porque las reducciones son ocasionales.
5. `expand()` evita falta de espacio; `shrink()` evita desperdicio de memoria.

### Ejercicio 5

1. [Semana2/include/DengVector.h](Semana2/include/DengVector.h).
2. La búsqueda termina al encontrar el elemento o al cruzar el intervalo; el mejor caso es `O(1)` y el peor `O(n)`.
3. Si hay repetidos, devuelve la coincidencia más a la derecha.
4. Ejemplos: `find(40, 0, 5) -> 4`, `find(99, 0, 5) -> -1`, `find(20, 0, 5) -> 3`.
5. El costo depende de la posición del dato, no solo de `n`.

### Ejercicio 6

1. `insert(r, e)` y `add(i, x)` desplazan el sufijo a la derecha tras asegurar capacidad.
2. Hay que mover desde atrás hacia adelante para no sobrescribir datos sin copiar.
3. Con inserción uniforme, el costo promedio es `Θ(n)`.
4. Insertar al final sigue siendo `O(1)` amortizado; al inicio requiere mover todo el arreglo.

### Ejercicio 7

1. `remove(lo, hi)` debe eliminar el bloque `[lo, hi)` y compactar el arreglo.
2. No conviene repetir `remove(r)` porque desplaza el mismo sufijo muchas veces.
3. Lo correcto es mover una sola vez el sufijo `A[hi..n)` hasta `lo` y ajustar `_size`.
4. El borrado en bloque es `O(n)`; el borrado uno por uno es mucho peor.

### Ejercicio 8

1. `traverse()` recorre y aplica una operación a cada elemento.
2. `decrease()` resta 1 a cada elemento.
3. `double()` multiplica por 2 cada elemento.
4. La prueba mínima es sobre `[3, 1, 4]`.
5. `traverse()` evita repetir el recorrido en cada operación.

### Ejercicio 9

1. `addAll(i, c)` no debe implementarse como muchas llamadas a `add(i, x)`.
2. La versión eficiente reserva una vez, desplaza el sufijo una sola vez y copia `c` en el hueco.
3. Eso da `O(n + m)` amortizado en lugar de `O(m·n)`.