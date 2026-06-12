## Respuestas

### Bloque 1

1. Targets: demo_pq_complheap_basico, demo_heapify_floyd, demo_heapsort, demo_left_heap_merge, demo_huffman, demo_compare_with_semana5, demo_bst_rotations, demo_treap_basico, test_public_week6, test_internal_week6.
2. `Capitulo6.h` incluye: PQ.h, PQ_ComplHeap.h, PQ_ComplHeap_macro.h, PQ_ComplHeap_getMax.h, PQ_ComplHeap_insert.h, PQ_ComplHeap_delMax.h, PQ_ComplHeap_percolateUp.h, PQ_ComplHeap_percolateDown.h, PQ_ComplHeap_heapifyFloyd.h, vector_heapSort.h, PQ_LeftHeap.h, Huffman_PQ.h, Treap.h.
3. Diferencia práctica: `Capitulo6.h` agrupa el código de la semana 6; `Capitulo10.h` contiene material de otro capítulo usado como dependencia.
4. Dependencias de Semana 5: BinaryTree, BinaryHeap y BinarySearchTree; se reutiliza la representación en vector para heaps.
5. Prioridad pura: `PQ_ComplHeap`.
6. Búsqueda ordenada: `BinarySearchTree`.
7. Mixta (orden + prioridad): `Treap`.
8. Evidencia inicial: el repo tiene demos y tests; ejecutar cmake, compilar y correr ctest mostrará si compila y pasa los tests.
9. Un Leftist Heap permite hacer uniones (merge) de dos colas de prioridad de forma muy eficiente en O(log N), algo que en un Complete Heap tomaría O(N).
10. El algoritmo de Huffman usa una cola de prioridad para ir sacando siempre los dos nodos de menor frecuencia y unirlos, construyendo así el árbol óptimo.

### Bloque 2

1. Ventaja de funciones pequeñas: código más claro, menos errores y reutilizable.
2. Ventaja de constexpr sobre macros: comprobación de tipos y evaluación en compilación, más seguro y depurable.
3. Caso borde hijo izquierdo solo: el índice del hijo derecho queda fuera del heap y solo se compara con el izquierdo.
4. Condición de hoja: no tiene hijo izquierdo (left index >= n).
5. Cambio en percolateDown: ahora usa pqHasLeftChild y pqHasRightChild, quedando más legible; complejidad sin cambios.
6. En `PQ_LeftHeap_merge`, la recursión se asegura de que el hijo derecho siempre tenga menor npl (null path length) que el izquierdo.
7. Un Treap asigna prioridades aleatorias a cada nodo para mantener el árbol balanceado con alta probabilidad.
8. La función `heapifyFloyd` construye un heap en tiempo O(N) haciéndolo de abajo hacia arriba, en vez de O(N log N).
9. En Huffman_PQ.h, se reutiliza la lógica de colas de prioridad pasando un comparador personalizado.
10. La ventaja del heapSort usando arreglos es que se hace in-place, es decir, ordena los elementos en el mismo arreglo.

### Bloque 3

1. Cuando el elemento insertado no tiene mayor prioridad que su padre, ya está en posición válida. También si se inserta en la raíz con i = 0.
2. En el peor caso, el elemento insertado asciende desde una hoja hasta la raíz; el número máximo de intercambios está acotado por la altura del heap, que es O(log n).
3. Es su tope, no puede seguir bajando. Altura = O(log n). 
4. Porque es un árbol, no tiene la misma lógica que colocarlos en un arreglo simplemente.
5. En `percolateDown`, el elemento baja intercambiándose con el mayor de sus hijos. En el peor caso recorre la altura O(log n).
6. La altura máxima esperada de un Treap con N nodos es O(log n) gracias a la aleatoriedad de sus prioridades.
7. Al hacer `delMax` en un Complete Heap, se pone el último elemento en la raíz y luego se hace `percolateDown` (O(log n)).
8. Para el Leftist Heap, la operación `insert` crea un heap de un solo nodo y hace `merge` con el heap actual.
9. En Huffman, para N caracteres, tomamos los 2 menores N-1 veces, cada operación en el heap es O(log N), logrando O(N logN).
10. El null path length de una hoja en un Leftist Heap es 0, y permite equilibrar hacia la izquierda de forma rápida.