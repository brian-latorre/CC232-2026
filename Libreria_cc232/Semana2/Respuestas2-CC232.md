### Ejercicio 1


1. Un tiempo promedio indica el tiempo esperado cuando una entrada es aleatoria donde asumimos que cada entrada posible tiene misma probabilidad. A diferencia del tiempo amortizado que es con respecto al costo promedio por operación. 

### Ejercicio 5 

1. Revisado en Semana2/include/DengVector.h
2. Tiene dos condiciones para terminar, o encuentra "e" o al disminuir hi llega a ser igual que lo. El mejor de los casos es que se encuentre "e" en el primer while (O(1)) y el peor de los casos sería recorrer todo el arreglo y encontrar al final la condición (O(n)).
3. Si hay más coincidencias en el arreglo, no devolvería todas pues el recorrido de while empieza desde hi (desde la derecha) y termina en la izquierda, asi que devolvería el valor que esté más a la derecha. 
4. 