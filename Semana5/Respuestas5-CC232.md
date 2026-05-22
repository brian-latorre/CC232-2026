### Respuestas

#### Bloque 1

1. Uno se basa en enlaces con nodos, siendo una idea más intuitiva y sencilla para nosotros, usando simplemente un puntero para desplazarse. Mientras que el árbol que se encuentra en un arreglo, llega a ser un poco menos intuitivo pero se basa en el uso de índices para determinar padres e hijos. 
2. Dato: el valor usualmente numérico dentro del nodo. Padre: puntero al nodo padre superior. Hijo izquierdo: puntero al nodo siguiente pero izquierdo. Hijo derecho: puntero al nodo siguiente pero derecho. Altura: Qué tan profundo se encuentra el nodo en el árbol. 
3. El puntero parent permite navegar hacia arriba desde un nodo sin recorrer todo el árbol. Sirve para succ() y pred(). El algoritmo sube por parent para llegar a un primer ancestro donde se produce un giro. Habilita una navegación ascendente eficiente y local, necesaria para implementar succ(), pred() y la propagación de cambios en alturas.
4. BinTree es la implementación directa de un árbol binario. El cual usa nodos que son BinNode, pues este es su mínima unidad. 
5. Agrega el funcionamiento general del árbol, sobre los nodos BinNode como unidad mínima, por lo cual manipula a los BinNode.


#### Bloque 2
 
1. hasLeft()/hasRight(): Booleano que indica si existe un hijo izquierdo o derecho un nodo en específico. isRoot(): Establece si es nodo raíz, identificandose cuando no tiene un nodo padre. isLeaf(): Establece si es una hoja, cuando ambos hijos son punteros nulos. isLeftChild/isRightChild(): Booleano que define si es hijo izquierdo o derecho.
2. Si el nodo tiene right, va hacia right y desde ahí desciende repetidamente por left. El resultado sería el nodo siguiente en el recorrido inorder.
3. Si no tiene right, sube por parent hasta encontrar un ancestro de tal manera que encuentre un nodo que el nodo que se evaluó esté en la parte izquierda. 


4. Si pred() es simétrico: si existe left desciende por right hasta el más a la derecha; si no, sube por parent hasta encontrar un giro hacia la derecha.

5. 

6. depth(u): número de aristas desde la raíz hasta u; puede obtenerse subiendo por parent y contando pasos (coste O(depth)).

7. height(u): longitud del camino más largo desde u hasta una hoja; suele calcularse bajando recursivamente por hijos y tomando el máximo de sus alturas +1.

8. subtreeSize(u): número de nodos en el subárbol cuya raíz es u se obtiene sumando 1 + size(left) + size(right).

9. Para todo u: depth(u) + height(u) <= height(T) porque cualquier raíz→hoja que pase por u tiene longitud depth(u)+height(u), y height(T) es la máxima longitud raíz a hoja.

10.  Igualdad ocurre si y solo si u pertenece a algún camino raíz a hoja que alcanza la altura máxima de T

#### Bloque 3
 
1. Preorden: visitar primero la raíz, luego el subárbol izquierdo y después el derecho. El recursivo viene del archivo BinNode.h y el iterativo también viene del archivo BinNode.h.

2. Inorden recursivo: visitan primero el lado izquierdo, luego la raíz y al final el lado derecho. Las cuatro versiones vienen del archivo BinNode.h.

3. Postorden: visitan primero el subárbol izquierdo, luego el derecho y al final la raíz. Las dos versiones vienen del archivo BinNode.h.

4. Recorrido por niveles: visita primero la raíz y después los nodos por capas, de arriba hacia abajo y de izquierda a derecha. En el árbol de prueba la secuencia es 7, 3, 10, 1, 5, 8, 12, 4, 6. Viene del archivo BinNode.h.

5. Los recorridos recursivos tienen tiempo O(n) porque cada nodo se visita una sola vez y en cada visita se hace trabajo constante. El preorden, el inorden y el postorden recursivos vienen del archivo BinNode.h.

6. Las versiones iterativas también tienen tiempo O(n) porque usan una pila o una lógica equivalente para procesar cada nodo una sola vez sin repetir visitas. En este bloque, las versiones iterativas vienen del archivo BinNode.h.

7. La memoria auxiliar de un recorrido recursivo en un árbol balanceado es O(log n), porque esa es la altura aproximada del árbol y esa es la profundidad máxima de la pila de llamadas. Los recorridos recursivos vienen del archivo BinNode.h.

8. La memoria auxiliar de un recorrido recursivo en un árbol degenerado es O(n), porque el árbol puede volverse casi una lista y la pila de llamadas crece con todos los nodos. Los recorridos recursivos vienen del archivo BinNode.h.

9. La diferencia entre usar una pila explícita y usar la pila de llamadas es que en la pila explícita el control lo maneja el programa de forma visible, mientras que en la pila de llamadas lo maneja el lenguaje automáticamente. En ambos casos se guarda el camino actual del recorrido. Las versiones explícitas vienen del archivo BinNode.h.

10. La cola del recorrido por niveles puede crecer mucho más en un árbol completo porque en un mismo nivel puede haber muchos nodos esperando ser procesados, mientras que en un árbol degenerado casi siempre hay uno solo. El recorrido por niveles viene del archivo BinNode.h.

