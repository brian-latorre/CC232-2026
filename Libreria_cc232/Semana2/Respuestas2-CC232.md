### Ejercicio 1


1. Un tiempo promedio indica el tiempo esperado cuando una entrada es aleatoria donde asumimos que cada entrada posible tiene misma probabilidad. A diferencia del tiempo amortizado que es con respecto al costo promedio por operación. 
2. Caso concreto con `DengVector`: si la capacidad es 4 y ya hay 4 elementos, al hacer una insercion mas al final se ejecuta `expand()`. Esa operacion copia los 4 elementos al nuevo arreglo ( el cual ahora tiene capacidad 8) y luego inserta el nuevo. Esa insercion puntual cuesta mucho mas que las anteriores, que solo escribian al final sin redimensionar.
3. No lo contradice porque el analisis amortizado no mira una sola operacion aislada, sino muchas operaciones en conjunto. Aunque algunas inserciones cuesten `O(n)` por copia, la mayoria cuestan `O(1)`, y el promedio por insercion en una secuencia larga se mantiene en `O(1)`.
4. Duplicar capacidad hace que los redimensionamientos sean poco frecuentes. Cuando ocurre una expansion se paga una copia grande, pero luego vienen muchas inserciones baratas sin volver a copiar. Por eso ayuda a mantener el costo amortizado de insertar al final en `O(1)`.
5. Si la capacidad creciera por una cantidad fija, los redimensionamientos ocurririan mucho mas seguido cuando el vector crece. Eso implica copiar elementos muchas veces y el costo amortizado de inserciones repetidas empeora (ya no se mantiene en `O(1)`, sino que crece hacia `O(n)`).

### Ejercicio 2

1. Revisado.
2. El arreglo destino debe ser independiente del fuente para que cada objeto gestione su propia memoria. Así, poder evitar algún error a la hora de borrar uno de los arreglos y poder gestionarlos por separado.
3. Prueba adjuntada en archivo `Semana2/demos/demo_deng_vector.cpp`. Con esto se demuestra que, tras copiar `b = a`, modificar `a` no afecta a `b`.
4. Al ejecutar la prueba, se modifica el original (`a[0] = 99`) y la copia mantiene su valor (`b[0] = 10`). Esto verifica en ejecucion que la copia no cambia cuando cambia el vector original.
5. Si ambos objetos compartieran el mismo arreglo interno, apareceria aliasing: cambiar uno cambiaria tambien al otro. Ademas, al destruirse ambos objetos intentarian liberar el mismo bloque de memoria (`delete[]`) y eso puede causar doble liberacion y comportamiento indefinido.

### Ejercicio 3

1. Variante experimental adjuntada en `Semana2/include/expandDengVector.h` (clase `ExpandDengVector`), donde `expand()` crece por constante fija `c` (parametro `growth`, por defecto 4) en lugar de duplicar capacidad.
2. Se mantiene la interfaz publica basica del vector (`size`, `capacity`, `empty`, `operator[]`, `find`, `insert`, `remove`, `clear`, `traverse`). El cambio principal esta en la politica de `expand()`.
3. En la version original (`DengVector`), la capacidad se duplica y las expansiones son menos frecuentes; en la variante por constante fija, la capacidad aumenta de a pocos y se expande mas seguido.
4. Con crecimiento por constante fija, las inserciones repetidas provocan muchas copias de elementos en diferentes expansiones. Por eso el costo amortizado empeora respecto a la version que duplica capacidad.
5. Ejemplo: si `growth = 4` y se insertan elementos al final desde 1 hasta 40, habra expansiones frecuentes (capacidad 3, 7, 11, 15, ...). En cada expansion se copian muchos elementos otra vez; con duplicacion (3, 6, 12, 24, 48) hay menos expansiones para llegar al mismo tamaño.


### Ejercicio 4

1. Revisado en `Semana2/include/DengVector.h` (`shrink()`) y `Semana2/include/ArrayStack.h` (`resize()` usado tras `remove`).
2. Para reducir capacidad de forma razonable, debe haber suficiente espacio ocioso (subutilizacion). En `DengVector`, solo reduce si `_size * 4 <= _capacity` y respeta una capacidad minima.
3. No conviene reducir despues de cada eliminacion porque habria redimensionamientos muy frecuentes (copias repetidas), empeorando el rendimiento global.
4. El costo amortizado puede mantenerse en `O(1)` porque las reducciones no ocurren en cada operacion, sino solo cuando se acumula suficiente espacio libre; el costo de copiar se reparte entre muchas eliminaciones.
5. `expand()` evita overflow de capacidad al crecer; `shrink()` evita desperdicio de memoria al reducir. Ambos equilibran tiempo (copias ocasionales) y espacio (no sobredimensionar mucho).


### Ejercicio 5 

1. Revisado en Semana2/include/DengVector.h
2. Tiene dos condiciones para terminar, o encuentra "e" o al disminuir hi llega a ser igual que lo. El mejor de los casos es que se encuentre "e" en el primer while (O(1)) y el peor de los casos sería recorrer todo el arreglo y encontrar al final la condición (O(n)).
3. Si hay más coincidencias en el arreglo, no devolvería todas pues el recorrido de while empieza desde hi (desde la derecha) y termina en la izquierda, asi que devolvería el valor que esté más a la derecha. 
4. Prueba minima con tres casos (sobre un vector con valores `[10, 20, 30, 20, 40]`):
	- Elemento al final del intervalo: `find(40, 0, 5)` devuelve `4`.
	- Elemento ausente: `find(99, 0, 5)` devuelve `-1`.
	- Multiples repeticiones: `find(20, 0, 5)` devuelve `3` (la coincidencia mas a la derecha).
5. Esta operacion es sensible a la entrada porque, con el mismo `n`, puede terminar muy rapido o recorrer casi todo el intervalo segun la posicion del elemento (o si no existe). Por eso su costo real depende de la distribucion de datos, no solo del tamaño.

### Ejercicio 6

### Ejercicio 7

### Ejercicio 8

### Ejercicio 9