## Respuestas

### Bloque 1

1. Los targets de demostracion son avl_deng_core, avl_compact_rotations, bst_deng_vs_avl, redblack_morin, redblack_llrb, compare_avl_vs_redblack, compare_with_semana5 y capitulo7_panorama.
2. 
3. Incluye los archivos Entry, BinNode, BinTree, BST, AVL, BinaryTree, BinarySearchTree, RedBlackTree, AVLTreeCompact y RedBlackTreeLLRB.
4. La Semana 5 introduce BST puro. La Semana 6 muestra como la prioridad cambia la estructura. La Semana 7 usa rotaciones para mantener un balance constante evitando degeneraciones.
5. No es correcto decir que heredan porque la herencia es para clases, en configuraciones solo se incluyen rutas.
6. La clase AVL hereda de BST y este de BinTree. La clase RedBlackTree hereda de BinarySearchTree y este de BinaryTree.
7. 

### Bloque 2

1. Para todo nodo, los elementos del lado izquierdo son menores y los del lado derecho son mayores.
2. Porque visita primero los nodos menores, luego la raiz y finalmente los mayores, listando todo en orden.
3. Porque cada dato nuevo es mayor al anterior y se acomoda siempre a la derecha formando una sola linea sin divisiones.
4. 
5. La altura es 6 asumiendo la raiz como el nivel cero.
6. Como el arbol parece una lista recta hay que revisar cada elemento uno por uno hasta llegar al final.
7. Evita que la altura se degenere forzando matematicamente que la diferencia de niveles entre ramas no pase de 1.
8. Evita la degeneracion pero usa reglas de color en vez de niveles exactos, esto hace que requiera reestructurarse menos veces.

### Bloque 5

1. Mantiene el orden estandar donde el hijo izquierdo es menor y el derecho mayor.
2. Todo nodo es rojo o negro, la raiz es negra y las hojas nulas tambien son negras.
3. Evita que el color rojo suba fuera de los limites y cause conflictos en la copa del arbol.
4. Significa que si hay un nodo rojo sus hijos deben ser negros para no permitir que una rama se estire demasiado.
5. Es la suma de nodos negros bajando por cualquier camino hasta una hoja nula y tiene que ser igual para todas las rutas.
6. Porque no exige diferencia estricta de niveles, solo que los caminos negros sumen igual, permitiendo cierto desnivel para evitar rotar tan seguido.
7. Pueden ocurrir cambios de color o rotaciones para evitar que se junten dos nodos rojos seguidos.
8. Se compensa la falta de nodos negros rotando ramas vecinas o subiendo el color rojo.
9. Mueven ramas pesadas hacia el otro lado cuando el desbalance no puede arreglarse solo pintando los nodos.
10. Ayuda a resolver problemas localmente ajustando las reglas contables sin tener que mover los enlaces de la estructura.