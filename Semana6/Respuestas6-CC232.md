
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

Comandos sugeridos y resultado breve:

- cmake -S . -B build  > genera la configuración de build
- cmake --build build   > compila los demos y tests
- ctest --test-dir build --output-on-failure  > ejecuta tests y muestra fallos

Archivos que planeo modificar:

- `Semana6/include/PQ_ComplHeap_macro.h`
- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_percolateDown.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/include/PQ_ComplHeap_delMax.h`
- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/vector_heapSort.h`
- `Semana6/include/PQ_LeftHeap.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/Huffman_PQ.h`
- `Semana6/include/Huffman_PQ_generateTree.h`
- `Semana6/include/Treap.h`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

### Bloque 2

1. 
2. 
3. Cuando se calcula el hijo derecho, puede quedar fuera si el nodo solo tiene hijo izquierdo. 

1. Ventaja de funciones pequeñas: código más claro, menos errores y reutilizable.

2. Ventaja de constexpr sobre macros: comprobación de tipos y evaluación en compilación, más seguro y depurable.

3. Caso borde hijo izquierdo solo: el índice del hijo derecho queda fuera del heap y solo se compara con el izquierdo.

4. Condición de hoja: no tiene hijo izquierdo (left index >= n).

5. Cambio en percolateDown: ahora usa pqHasLeftChild y pqHasRightChild, quedando más legible; complejidad sin cambios.