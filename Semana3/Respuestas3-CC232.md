### Ejercicio 1

1. Revisado: SLList contiene una cabeza (head) que apunta al primer nodo, y las operaciones get(i), set(i, x), add(i, x) y removeAt(i) recorren secuencialmente desde head.
2. Estas operaciones se apoyan en el recorrido secuencial: get(i) y set(i, x) avanzan i pasos hasta encontrar el nodo en la posición i, luego leen o escriben su valor; add(i, x) recorre hasta la posición i-1, crea un nodo nuevo y reenlaza; removeAt(i) recorre hasta el nodo anterior a i, actualiza los enlaces saltando el nodo a eliminar.
3. Cada una cuesta `O(1 + i)` porque en el peor caso deben recorrer desde head hasta la posición i, lo que requiere i saltos (O(i)) más operaciones de lectura/escritura (`O(1)`), resultando en `O(i)`. Cuando se recorre desde la cabeza sin acceso directo a posición intermedia, todo acceso requiere travesía previa.
4. Prueba pequeña (ejemplo):
   - Inserción al inicio: add(0, 10) → lista [10] cuesta `O(1)`.
   - Inserción al final sobre lista de tamaño n: add(n, 20) → lista [10, ..., 20] cuesta `O(n)`.
   - Inserción intermedia: add(1, 15) sobre [10, 20] → [10, 15, 20] cuesta `O(1)`.
   - Eliminación intermedia: removeAt(1) → [10, 20] cuesta `O(1)`.
5. Comparación con estructura contigua: en un arreglo, get(i) y set(i, x) cuestan `O(1)` (acceso directo por índice), pero add(i, x) y removeAt(i) en posición intermedia requieren desplazamientos (`O(n-i)`) que amortizado son `O(n)`. En lista enlazada, lectura cuesta `O(i)`, inserción/eliminación cuesta `O(i)` más `O(1)` de reasignación. El enlazado favorece operaciones de inicio/final si se tiene referencia, y el contiguo favorece acceso aleatorio.

### Ejercicio 2

1. Recorro la lista y voy invirtiendo cada enlace next mientras avanzo con prev, current y next.
2. Implementación: ver Semana3/include/SLList.h (método reverse()).
3. El invariante es que todo lo ya recorrido queda invertido y current guarda el resto por procesar.
4. Verificación mínima: [1, 2, 3, 4, 5] pasa a [5, 4, 3, 2, 1] y head/tail se intercambian.
5. Tiempo `O(n)`: una sola pasada sobre todos los nodos. Espacio `O(1)`: solo se usan tres punteros temporales (prev, current, next) que reutilizan memoria.

### Ejercicio 3

1. `checkSize()` recorre la lista y compara el conteo real con `_size`.
2. Implementación: ver Semana3/include/SLList.h (método checkSize()).
3. En DLList también se verifica que los enlaces `prev/next` sean coherentes.
4. En SLList, la lista vacía debe tener `head == nullptr` y `tail == nullptr`.
5. Basta llamarlo tras operaciones de cambio para detectar inconsistencias.

### Ejercicio 4

1. La lista con centinela dummy permite comparar desde ambos extremos sin casos especiales.
2. Implementación: ver Semana3/include/DLList.h (método isPalindrome()).
3. Comparo solo la mitad porque el resto queda determinado por simetría.
4. Casos básicos: vacía y un elemento dan `true`; `[1, 2, 2, 1]` da `true`; `[1, 2, 3, 4]` da `false`.
5. Complejidad `O(n)`: se recorren n/2 elementos (dos punteros avanzan simultáneamente desde los extremos hasta el centro), cada avance es `O(1)`.

### Ejercicio 5

1. `rotate(r)` mueve cada elemento a la posición `(i + r) mod n`.
2. Implementación: ver Semana3/include/DLList.h (método rotate()).
3. Normalizo `r` y reengancho el tramo que pasa a ser la nueva cabeza.
4. Ejemplos con `[1, 2, 3, 4, 5]`:
   - rotate(0) → [1, 2, 3, 4, 5] (sin cambio).
   - rotate(1) → [5, 1, 2, 3, 4].
   - rotate(5) → [1, 2, 3, 4, 5] (equivalente a rotate(0)).
   - rotate(-1) → [2, 3, 4, 5, 1] (equivalente a rotate(4)).
5. El costo es `O(min(r, n-r))` al buscar el punto de corte desde el extremo más cercano.

### Ejercicio 6

1. `truncate(i)` deja en la lista original los elementos `[0, i)` y devuelve el resto.
2. Implementación: ver Semana3/include/DLList.h (método truncate()).
3. El corte se hace solo con reasignación de enlaces, sin copiar nodos.
4. Casos básicos: `i = 0` devuelve toda la cola, `i = n` devuelve una lista vacía.
5. El costo es `O(i)` para localizar el corte y `O(1)` para separar.

### Ejercicio 7

1. MinStack guarda en cada nodo el valor y el mínimo acumulado.
2. Implementación: ver Semana3/include/MinStack.h.
3. `push`, `pop`, `top` y `min` se resuelven en `O(1)`.
4. Ejemplo mínimo: `push(5)`, `push(2)`, `push(8)`, `pop()`, `push(1)` mantiene el mínimo correcto.
5. No hay recorridos; todo depende solo del tope.
   - push(5): pila [(5, 5)], min() = 5.
   - push(2): pila [(5,5), (2,2)], min() = 2.
   - push(8): pila [(5,5), (2,2), (8,2)], min() = 2.
   - pop(): pila [(5,5), (2,2)], min() = 2.
   - push(1): pila [(5,5), (2,2), (1,1)], min() = 1.
   - pop(): pila [(5,5), (2,2)], min() = 2.
5. Todas las operaciones son `O(1)` porque cada operación realiza un número constante de operaciones primitivas (crear nodo, desenlazar, leer campo). No hay recorridos ni búsquedas.

### Ejercicio 8

1. MinQueue usa dos MinStack: uno de entrada y uno de salida.
2. `add` entra por el stack de entrada; `remove` transfiere si hace falta y luego saca del de salida.
3. `front`, `size` y `min` se obtienen en `O(1)`.
4. La transferencia invierte el orden una sola vez por elemento.
5. El costo es `O(1)` amortizado.

### Ejercicio 9

1. MinDeque usa dos MinStack: uno para el frente y otro para el fondo.
2. `addFirst` y `addLast` insertan en su lado; `removeFirst` y `removeLast` rebalancean solo cuando hace falta.
3. `front`, `back` y `min` salen en `O(1)`.
4. El rebalanceo mueve medio deque una sola vez por bloque de operaciones.
5. El costo queda `O(1)` amortizado.

### Ejercicio 10

1. Revisado: DengList.h proporciona dedup() para listas no ordenadas; CleanList.h ofrece uniquify() para listas ordenadas; MorinDengBridge.h permite reutilizar operaciones Deng sobre estructuras Morin (como DLList, SEList).
2. Diferencia: dedup() en lista no ordenada requiere comparar cada elemento con todos los demás para identificar duplicados (costo `O(n^2)` en general, aunque con hash puede mejorarse). uniquify() en lista ordenada solo compara elementos contiguos (costo `O(n)`).
3. Prueba con repeticiones: lista [3, 1, 4, 1, 5, 9, 2, 6, 5]:
   - Aplicar dedup_with_deng() → [3, 1, 4, 5, 9, 2, 6] (primera ocurrencia de cada elemento preservada).
   - Comparar antes/después en pantalla.
4. Comparación con ordenamiento:
   - Aplicar stable_sort_with_deng() sobre [3, 1, 4, 1, 5, 9, 2, 6, 5] → [1, 1, 2, 3, 4, 5, 5, 6, 9].
   - Luego aplicar dedup_with_deng() → [1, 2, 3, 4, 5, 6, 9] (todos duplicados eliminados).
5. Rol del puente: MorinDengBridge traduce operaciones de estilo Deng (que trabajan con arreglos) a la interfaz de DLList o SEList (que son enlazadas). El puente maneja la conversión; la estructura enlazada sigue siendo responsable de mantener coherencia de enlaces.

### Ejercicio 11

1. Revisado:
   - LinkedStack: usa SLList o DLList internamente; push() y pop() operan sobre el inicio; top() accede al primer elemento.
   - LinkedQueue: usa SLList o DLList; add() inserta al final; remove() extrae del inicio; mantiene FIFO.
   - LinkedDeque: usa DLList; permite operaciones en ambos extremos (addFirst, addLast, removeFirst, removeLast).
2. Operaciones internas:
   - LinkedStack: push(x) → _list.push_front(x), pop() → _list.pop_front(), top() → _list.front().
   - LinkedQueue: add(x) → _list.push_back(x), remove() → _list.pop_front(), front() → _list.front().
   - LinkedDeque: usa directamente los métodos de DLList para ambos extremos.
3. Separación ADT vs implementación: estos adaptadores definen interfaces (operaciones permitidas, semántica LIFO/FIFO/ambos extremos) sin exposer la representación interna; permiten cambiar a otra estructura (e.g., ArrayStack) manteniendo la interfaz.
4. Pruebas:
   - LinkedStack: push(1), push(2), pop(), top() == 1 (LIFO).
   - LinkedQueue: add(1), add(2), remove() == 1, front() == 2 (FIFO).
   - LinkedDeque: operaciones mixtas en ambos extremos conservan orden correcto.
5. Comparación conceptual: adaptadores enlazados suelen tener mejor rendimiento en inserciones/eliminaciones de ambos extremos (deque), mientras que adaptadores contigüos tienen mejor localidad de caché y acceso más rápido en promedio, pero operaciones de extremo requieren redimensionamiento y copia ocasional.

### Ejercicio 12

1. Revisado: XorList comprime los enlaces prev y next en un solo campo link = prev XOR next. Dado el nodo anterior, se recupera el siguiente como next = link XOR prev (ya que a XOR a = 0 y a XOR 0 = a).
2. Codificación XOR: cada nodo almacena link = (dirección_prev) XOR (dirección_next). Para navegar hacia next, conociendo prev, se calcula next = link XOR prev; análogamente en sentido inverso. Esto reduce memoria de 2 punteros a 1.
3. Verificación experimental:
   - push_front(x), push_back(y), pop_front(), pop_back(): verifica que los elementos se insertan y extraen correctamente.
   - get(i), reverse(): prueba lectura de posición y inversión de enlaces XOR.
4. Comparación con DLList: XorList es más compacto en memoria (un puntero por nodo vs. dos), pero más complejo en depuración (los valores de link no son direcciones reales interpretables) y más propenso a errores si la aritmética de punteros no es cuidadosa. DLList es más legible y segura, aunque consume más memoria.
5. Interés conceptual: XorList es un ejemplo elegante de compresión de información usando propiedades algebraicas de XOR; sin embargo, en código de producción moderno (donde memoria es abundante y legibilidad es crítica), DLList tradicional es preferible. XorList es más relevante en sistemas embebidos o con restricciones muy severas de memoria.

### Ejercicio 13

1. Ejecución del benchmark Semana3/benchmarks/benchmark_semana3.cpp: registrar tiempos de operaciones sobre cola enlazada (LinkedQueue o SLList) vs. cola contigua (ArrayQueue o DengVector), y deque enlazado vs. deque contiguo.
2. Diferencia en colas:
   - **Cola enlazada**: inserciones al final y extracciones del inicio son ambas `O(1)` con buen cache locality en el extremo principal.
   - **Cola contigua**: inserciones al final amortizado `O(1)`, extracciones del inicio `O(1)` si se maneja un índice frontal, pero con potencial fragmentación lógica.
   - En práctica, colas enlazadas suelen ser más lentas debido a overhead de punteros y peor localidad de caché.
3. Acceso aleatorio en DLList vs. ArrayDeque:
   - **DLList**: get(i) requiere recorrer `O(i)` nodos, perjudicado por saltos de puntero.
   - **ArrayDeque**: get(i) es `O(1)` acceso directo, con mejor localidad de caché.
   - Resultado esperado: ArrayDeque gana notablemente.
4. Factores de rendimiento:
   - **Localidad de referencia**: arreglo contiguo mantiene datos cercanos en memoria (mejor cache hit); punteros enlazados acceden a direcciones dispersas (cache misses).
   - **Movimiento de elementos**: insertiones/eliminaciones intermedias en contiguo requieren desplazamientos (`O(n)`); en enlazado solo ajustan punteros (`O(1)` después de localizar).
   - **Costo de punteros**: enlazado gasta 8 bytes por puntero (o 16 en DLList); contiguo no tiene ese overhead.
5. Conclusión: usar estructuras enlazadas cuando las operaciones de inserción/eliminación intermedia sean frecuentes (mejor complejidad asintótica), especialmente en posiciones variables. Usar estructuras contiguas para acceso aleatorio, iteración frecuente o cuando la localidad de caché sea crítica. Para colas simples (inserción/extracción en extremos), la diferencia práctica de rendimiento puede favorecer el contiguo a pesar de la complejidad teórica similar.
