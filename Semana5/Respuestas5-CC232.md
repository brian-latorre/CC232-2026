### Respuestas

#### Bloque 1

1. Uno se basa en enlaces con nodos, siendo una idea más intuitiva y sencilla para nosotros, usando simplemente un puntero para desplazarse. Mientras que el árbol que se encuentra en un arreglo, llega a ser un poco menos intuitivo pero se basa en el uso de índices para determinar padres e hijos. 
2. Dato: el valor usualmente numérico dentro del nodo. Padre: puntero al nodo padre superior. Hijo izquierdo: puntero al nodo siguiente pero izquierdo. Hijo derecho: puntero al nodo siguiente pero derecho. Altura: Qué tan profundo se encuentra el nodo en el árbol. 
3. El puntero parent permite navegar hacia arriba desde un nodo sin recorrer todo el árbol. Sirve para succ() y pred(). El algoritmo sube por parent para llegar a un primer ancestro donde se produce un giro. Habilita una navegación ascendente eficiente y local, necesaria para implementar succ(), pred() y la propagación de cambios en alturas.
4. BinTree es la implementación directa de un árbol binario. El cual usa nodos que son BinNode, pues este es su mínima unidad. 
5. Agrega el funcionamiento general del árbol, sobre los nodos BinNode como unidad mínima, por lo cual manipula a los BinNode.
6. Un BinarySearchTree agrega la propiedad de orden: en cada nodo, todo lo que está a la izquierda es menor y todo lo que está a la derecha es mayor. Eso permite buscar, insertar y eliminar siguiendo comparaciones.
7. Un BinaryHeap mínimo agrega la propiedad de prioridad: el valor más pequeño queda en la raíz y cada padre es menor o igual que sus hijos. Así se puede consultar rápido el mínimo.
8. En un BST el orden está organizado por claves y permite recorrer en forma ordenada; en un heap solo importa la prioridad relativa del padre con sus hijos, no el orden global entre hermanos o subárboles.
9. Porque el recorrido inorden visita izquierdo, raíz y derecho, y en un BST eso significa visitar primero los menores, luego el nodo actual y después los mayores. Por eso la secuencia sale ordenada.
10. Porque un heap no mantiene un orden total entre todos sus elementos, solo una prioridad local. Para verlos en orden habría que ir extrayendo o copiar la estructura, ya que el árbol no está organizado para listar directamente de menor a mayor.


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
 
1. Preorden: visitar primero la raíz, luego el subárbol izquierdo y después el derecho.

2. Inorden recursivo: visitan primero el lado izquierdo, luego la raíz y al final el lado derecho.

3. Postorden: visitan primero el subárbol izquierdo, luego el derecho y al final la raíz.

4. Recorrido por niveles: visita primero la raíz y después los nodos por capas, de arriba hacia abajo y de izquierda a derecha.

5. Los recorridos recursivos tienen tiempo O(n) porque cada nodo se visita una sola vez y en cada visita se hace trabajo constante.

6. Las versiones iterativas también tienen tiempo O(n) porque usan una pila o una lógica equivalente para procesar cada nodo una sola vez sin repetir visitas. 

7. La memoria auxiliar de un recorrido recursivo en un árbol balanceado es O(log n), porque esa es la altura aproximada del árbol y esa es la profundidad máxima de la pila de llamadas. 

8. La memoria auxiliar de un recorrido recursivo en un árbol degenerado es O(n), porque el árbol puede volverse casi una lista y la pila de llamadas crece con todos los nodos. 

9. La diferencia entre usar una pila explícita y usar la pila de llamadas es que en la pila explícita el control lo maneja el programa de forma visible, mientras que en la pila de llamadas lo maneja el lenguaje automáticamente. En ambos casos se guarda el camino actual del recorrido. 

10. La cola del recorrido por niveles puede crecer mucho más en un árbol completo porque en un mismo nivel puede haber muchos nodos esperando ser procesados, mientras que en un árbol degenerado casi siempre hay uno solo. 

