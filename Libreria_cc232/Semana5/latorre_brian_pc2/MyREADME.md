### Prueba de Avance

Este archivo será un "diario" en el cual iré escribiendo mi avance según pase los días, al cual le puse de nombre "MyREADME" porque colocaré mis ideas principales, cómo he ido pensando el problema, qué cosas he descubierto en el transcurso de los días según mi investigación e incluso errores que detecto en mi lógica a la hora de avanzar. Todo redactado a mano por mi. 

#### Día 1

Mi idea principal se limitaba a solo ver a la derecha sin expandir más de una vez, es decir solo se verificaba i con i+1, lo cual ayudaba a encontrar más rectángulos y no solo los de "ancho 1" pero no eran todos los casos. 

![](imagenes/dia1_logica_inicial.png)

![](imagenes/dia1_desarrollo_inicial.png)

Ahí es donde me empecé a preguntar: ¿Qué pasa si la mínima altura multiplicado por el número de rectángulos de ancho 1 en el histograma es en verdad el rectángulo con más área? Entonces me di cuenta que estaba perdiendo casos. 

![](imagenes/dia1_casos.png)

#### Día 2

Aprovechando que venía de la clase de hoy lunes (2026-04-27) empecé a pensar cómo podría alcanzar todos los casos posibles. En lo que se me ocurrió lo siguiente:
- Usaría un índice i.
- Usaría un índice j. 

La idea es dejar el índice i fijo e ir "scaneando" los rectángulos existentes hacia la derecha, si choca con uno de ancho uno y altura menor, entonces lo que haría sería determinar el área limitandose con la altura mínima que se encontró en el recorrido y tomando el ancho hasta el último indice j. 
Al inicio tuve un problema con esta implementación, tuve que consultarle a la IA para corregirme ya que estaba en verdad agarrando la altura solo de los extremos, mas no estaba siendo delimitado por algún valor menor en medio de los dos. 

Adjunto explicación visual: 

![](imagenes/dia2_diagrama_inicial.png)

Caso que me daba el valor 12, esto debido a que solo se consideraba los extremos. 

![](imagenes/dia2_diagrama_solucion.png)

Un ejemplo de caso válido donde si se respetaba que había un mínimo anterior que limitaba.

Según he estado investigando poco a poco, tengo conocimiento que puede existir un caso borde aquí si se implementa mal. También que la complejidad llega a ser $O(n^2)$. Esto lo evaluaré al día siguiente donde empezaré a buscar la respuesta del problema y empezar a aplicar tests. Al final pienso buscar algún video explicando el problema para confirmar que entiendo todo lo que aborda el problema final.  

