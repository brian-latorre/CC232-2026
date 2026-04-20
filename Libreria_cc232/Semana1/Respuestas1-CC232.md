## Actividad 1- CC232

### Integrantes de Grupo 8
- Brian Jair La Torre Urbina
- Oscar Alberto Pomalia Suyo

#### Bloque 1
(respuestas)

#### Bloque 2

3. Podemos verificar que nos dan el mismo resultado ambos algoritmos, tanto fib(n) como fibI(n). Con la demo podemos ver que se obtienen el mismo resultado, pero el tiempo es diferente pues fib(n) es exponencial y fibI(n) es lineal.

4. El ejemplo implementado ayuda mucho a identificar que el tamaño de la entrada no siempre coincide con el valor numérico. En este caso, el valor numérico es 361, pero el tamaño de la entrada son los 9 bits.

#### Bloque 3

1. Las pruebas publicas verifican el comportamiento basico de las funciones implementadas en la semana. En test_public_week1.cpp se prueban: las tres versiones de sum, las funciones de potencia, las tres versiones de Fibonacci y la clase Fib. En test_public_week1_extra.cpp se prueban: bubbleSortOptimized verificando orden y que haya comparaciones, countOnes1 y countOnes2 contando bits en 1, maxI, maxRLinear y maxRDivide para encontrar el maximo, reverseRecursive y shiftLeftByK para invertir y desplazar arreglos, gcdCN para el maximo comun divisor, y solveHanoi.

2. Una prueba publica demuestra que la funcion produce la salida esperada para casos concretos y conocidos. Si la prueba pasa, confirma que para esas entradas especificas el resultado es correcto. Tambien sirve como documentacion ejecutable de que es lo que se espera que haga la funcion.

3. Una prueba publica no demuestra correctitud general. Que pase para unos pocos casos no garantiza que funcione para todas las entradas posibles. No demuestra eficiencia ni costo temporal o espacial. Tampoco casos borde que no esten incluidos explicitamente, ni asegura robustez ante entradas invalidas o extremas.

4. Explica con tus palabras las nociones de:
   
- entrada: se brinda el problema al algoritmo para que pueda tener un resultado final que sea correcto y útil.
- salida: Resultado obtenido a partir del procesamiento del algoritmo del problema brindado, tiene que ser correcto y útil. 
- determinismo: significa que la descripción del algoritmo siempre debe ser el mismo.   
- factibilidad: cuando corresponden los pasos que se han descrito al modelo elegido, que tenga sentido y sea posible poderlos implementar.
- finitud: el algoritmo debe tener una cantidad de pasos finitas para poder llegar al resultado. 
- corrección: el resultado del algoritmo, satisface lo que el problema de entrada pide. Si termina, debe de resolver. 

5. Autoevaluacion usando la rubrica:


#### Bloque 4

1. En demo_const_refs.cpp se observa que la lectura con sum_readonly recibe el vector por referencia constante, lo que significa que solo lo lee sin modificarlo ni copiarlo. La modificacion con append_in_place recibe el vector por referencia normal y lo altera directamente, agregando un elemento al original. La copia con appended_copy crea un vector nuevo con el elemento adicional y deja el original intacto. La diferencia observable es que despues de append_in_place el original cambia, pero despues de appended_copy el original sigue igual y se genera un nuevo vector. Esto muestra el costo de copiar versus modificar en sitio.

2. En bench_vector_growth.cpp, al usar reserve se pre-asigna toda la memoria necesaria antes de los push_back, evitando las reasignaciones dinamicas que ocurren cuando el vector crece sin reserve. Sin reserve, el vector necesita reasignar y copiar elementos varias veces conforme se llena, lo que genera un overhead adicional. Con reserve el tiempo medido es menor porque se elimina ese costo de reasignacion.

3. En bench_vector_ops.cpp, push_back inserta al final y es O(1) amortizado porque no necesita mover ningun elemento existente. insert(begin()) inserta al inicio y es O(n) porque debe desplazar todos los elementos una posicion hacia adelante para hacer espacio. insert(middle) inserta en la mitad y es O(n/2) en promedio porque necesita desplazar la mitad de los elementos. El benchmark muestra que insert al inicio es el mas lento, insert en el medio toma un tiempo intermedio, y push_back al final es el mas rapido, confirmando que el costo depende de cuantos elementos hay que mover.

4. En bench_cache_effects.cpp, el recorrido secuencial del vector es el mas rapido porque accede a posiciones consecutivas en memoria, aprovechando la cache del procesador que precarga bloques contiguos. El acceso aleatorio al mismo vector es mas lento porque salta entre posiciones distantes, provocando fallos de cache frecuentes. El recorrido de std::list es tambien lento porque cada nodo esta en una posicion de memoria distinta y no necesariamente contigua. La intuicion que deja es que la localidad de memoria importa mucho: datos contiguos en memoria se procesan mas rapido que datos dispersos, incluso si la cantidad de operaciones logicas es la misma.

#### Bloque 5
(respuestas)

#### Bloque 6
(respuesta final)

#### Autoevaluación breve
- Qué podemos defender con seguridad:
- Qué todavía confundimos:
- Qué evidencia usaríamos en una sustentación:
```

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, y conexión explícita entre código, correctitud, costo, representación y evidencia.