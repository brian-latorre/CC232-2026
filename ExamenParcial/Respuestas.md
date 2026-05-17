### Pregunta 1
a) ADT: lo descrito como interfaz pública como size(), get(), set(), add() y remove() porque define qué hace la estructura. Implementación: La aplicación directa de arreglo dinámico o lista doblemente enlazada, con sus respectivas características mencionadas ya que esto explica cómo se logra el comportamiento del ADT. 

b) 

|  | I | II|
|-----|-----|-----|
|get | $O(1)$ | $O(min(i,n-i))$ | 
|set | $O(1)$ | $O(min(i,n-i))$ |
| add(i,x)| $O(n)$ | $O(min(i,n-i))$ |
| remove (i) | $O(n)$ | $O(min(i,n-i))$ |

c) Invariante I: $ 0 <= size <= capacity$, gracias al redimensionamiento del arreglo, no salimos del arreglo. Romper la implementación I: Manipular size() sin devolver el verdadero valor del arreglo, dando valores incorrectos al usar get(). Invariante II: Para los nodos, uno apunta al siguiente y el siguiente apunta al nodo anterior, ocasionando que siempre estén unidas. Romper la implementación II: Olvidarse de actualizar un puntero a la hora de manipular la lista enlazada.
d) La implementación I es conveniente porque las operaciones de get() y set() son $O(1)$. La implementación II es $O(n)$. Como el 90% de las veces será $O(1)$, sería la mejor opción. 
e) Porque se debe de recorrer hasta llegar a esa posición. Solo sucede en los extremos. 

### Pregunta 2

a) 

Iteración 1: ans = 3 , p = 9 , n = 6

Iteración 2: ans = 3 , p = 81 , n = 3

Iteración 3: ans = 243 , p = 6561 , n = 1

Iteración 4: ans = 1594323 , p = 43046721 , n = 0

b) Siempre se cumple que $ans \times p^{k} = a^{n inicial}$, donde $k$ es el valor de n en el bucle.

c) En cada iteración, el valor de $n$ se actualiza a $n/2$ lo cual garantiza que se vaya disminuyendo. Forzosamente disminuirá a $0$.

d) Complejidad de $O(\log(n))$ porque el problema se va dividiendo en dos. 

e) Realizarlo con un bucle for para que $ans = ans * a$, tomando un costo temporal de $O(n)$. Un caso de casila sería fastPower(3,23).



### Pregunta 3

a) 

Primera inserción: _capacity = 1 , _size = 1 , 0 copias

Segunda inserción: _capacity = 2 , _size = 2 , 1 copia

Tercera inserción: _capacity = 4 , _size = 3 , 2 copias

b) El número total de copias se da por $2^{⌊\log_2(n)⌋}−1$
ya que se da por potencias de 2.

c) El costo amortizado es de $O(1)$ porque el redimensionamiento solo se da en las potencias de dos, lo cual se va disminuyendo la concurrencia conforme más crece $n$.

d) Evita una oscilación a la hora de hacer add o remove, para que no se esté redimensionando tan constantemente. 

e) Reducir a la mitad cuando el tamaño se disminuye, ocasiona oscilación ya que si se alterna repetidamente entre hacer un add y un remove, en ese límite se la pasará creciendo y encongiendo. Generando que no se pueda tener un valor amortizado de $O(1)$

### Pregunta 4

a) 

- [ D , - , - , - , - , A , B , C].
Con D en índice 0 hasta C con índice 7. 

b) 

- [ D , - , - , - , X , A , B , C]
lógico [X,A,B,C,D]
- [ C , D , - , - , X , A , B , Y]
lógico [X,A,B,Y,C,D]
- [ C , - , - , - , X , A , B , Y]
lógico [X,A,B,Y,C]
- [ C , - , - , X , A , Z , B , Y]
lógico [X,A,Z,B,Y,C]

c) Porque asegura que nunca se muevan más de la mitad de elementos. Lo que garantiza que sea rápido.

d) Ubicar el índice toma $O(1)$. El algoritmo escoge mover el bloque de elementos más pequeños. 

e) Se gana poder agregar y quitar en el inicio con costo $O(1)$. El invariante es que funciona de forma circular. 

### Pregunta 5

a) 

```
Nodo* prev = nullptr;
Nodo* current = head;
tail = head;
while(current != nullptr){
    Nodo* aux = current->next;
    current->next = prev;
    prev = current;
    current = aux;
}
head = prev;
```
b) Se intercambian cuando $n \geq 2$. En $n = 0$, el bucle no se va a ejecutar y se mantienen nulos. En $n=1$, el único nodo se apunta a nulo mientras que head y tail apuntan a ese nodo creado.

c) En cada iteración, la lista está dividida en dos partes, una donde se contiene la lista invertida y otra la que falta invertir. 

d) El tiempo es $O(n)$ porque recorre todos los nodos una vez. El espacio es $O(1)$ porque solo usa variables temporales. 

e) Porque se necesita borrar por el final en $O(1)$. No hay punteros hacia atrás asi que borrar el último tendríamos que recorrer todo. 

### Pregunta 6

a) Caso 1: A = [10, 20, 30, 40], n = 4, k = 1, con salida esperada [20, 30, 40, 10]. Caso 2: B = [1, 2, 3, 4, 5, 6] , n = 6 , k = 3, con salida esperada [4, 5, 6, 1, 2, 3]

Casos borde: 

1: Entrada V = [ ], n = 0 , k = 2 con salida esperada [ ]. 

2: V = [7, 8, 9], n = 3, k = 0 con salida esperada [7, 8, 9] 

3: V = [4, 5, 6], n = 3, k = 3 con salida esperada [4, 5, 6]

4: V = [1, 2, 3] , n = 3 , k = 5 con salida esperada [3, 1 ,2] en el cual se podría usar modularidad.


b) 

1: Se debe detectar si el arreglo está vacío para evitar hacer k%n si se usará modularidad.

2: Ineficiencia ya que se puede hacer una verificación con coste $O(1)$ para evitar todos los pasos lógicos si el arreglo terminará igual.

3: De la misma manera, costo innecesario al ejecutar toda la lógica si el arreglo quedará igual.

4: Uso de modularidad para desbordamiento en el arreglo con respecto al valor de $k$ ya que es mayor a $n$. 

c) Por ejemplo en el caso 4, si el valor no es normalizado, salta a un apartado de memoria que no ha sido asignada al arreglo.

d) En la primera linea se debe colocar el caso de $(n == 0)$, para evitar ejecución del calculo $(k \% 0)$

### Pregunta 7

a) ADT MinQueue, donde se puede agregar, ver y quitar elementos desde sus extremos. Además de que se puede obtener el mínimo valor contenido. 

b) Con dos MinStacks. Una para la parte delantera y otra para la parte de atrás conectadas.

c) El mínimo global siempre es menor entre los mínimos de cada pila. 

d) Complejidad $O(1)$ porque se pueden agregar de manera directa a cada extremo y el retirado también es de cada extremo, ya que siempre tenemos acceso a los extremos en $O(1)$. 

e) Con valores repetidos, se debe comprobar que la función que brinde el mínimo no se quede sin el otro mínimo valor. En la eliminación de ambos extremos, se debe comprobar el menor elemento, se debe actualizar la función que brinde el mínimo. En una estructura vacía debe lanzar algún error y comprobar que el tamaño es cero. 

f) Usar bucle for de manera sencilla, tardando $O(n)$ y sería más costoso entre mayor el valor de $n$.