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
4. 

### Ejercicio 3

### Ejercicio 4


### Ejercicio 5 

1. Revisado en Semana2/include/DengVector.h
2. Tiene dos condiciones para terminar, o encuentra "e" o al disminuir hi llega a ser igual que lo. El mejor de los casos es que se encuentre "e" en el primer while (O(1)) y el peor de los casos sería recorrer todo el arreglo y encontrar al final la condición (O(n)).
3. Si hay más coincidencias en el arreglo, no devolvería todas pues el recorrido de while empieza desde hi (desde la derecha) y termina en la izquierda, asi que devolvería el valor que esté más a la derecha. 
4. 

### Ejercicio 6

### Ejercicio 7

### Ejercicio 8

### Ejercicio 9