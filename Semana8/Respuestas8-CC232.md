## Respuestas

### Bloque 1

1. Los targets de demostracion para Semana 8 son sem8_demo_chained, sem8_demo_linear, sem8_demo_hashtable_oa, sem8_demo_aplicaciones, sem8_demo_collision_strategies, sem8_demo_hash_functions, sem8_demo_tombstones, sem8_demo_benchmark_load_factor.
2. Las pruebas publicas son test_public_week8 y las internas son test_internal_week8, test_tombstones, test_collision_patterns, test_rehashing, test_randomized_against_stl.
3. Capitulo9 incluye la interfaz abstracta, los tipos de datos en la jerarquia de tablas, las utilidades de distribucion matematicas, politicas, estadisticas y aplicaciones especificas del area.
4. La Semana 5 introduce arboles binarios con costo dependiente de altura, Semana 6 monticulos para prioridad, Semana 7 arboles balanceados con costo logaritmico garantizado, y Semana 8 tablas con costo constante esperado pero no garantizado.
5. No es correcto porque en el peor caso, si todas las claves colisionan o generan un agrupamiento, el costo se vuelve proporcional a la cantidad de elementos almacenados.
6. Al ejecutar las pruebas sin modificar nada, todas pasaron exitosamente, confirmando que la implementacion original es estable y correcta.
7. Compilar solo los objetivos limitados a esta area de estudio es mas rapido porque descarta la construccion y enlaze del codigo de modulos anteriores, facilitando un ciclo de prueba veloz en el entorno.

### Bloque 2

1. Un diccionario abstracto es una especificacion que establece operaciones para almacenar pares formados por una clave y un valor, permitiendo su insercion, obtencion y borrado por medio de su identificador.
2. Un diccionario asocia una clave a un valor sin ordenamiento forzado. Un mapa es conceptualmente analogo. Un conjunto solo guarda las claves unicas sin ningun valor agregado. Una tabla es la traduccion en memoria que permite llevar a cabo estas operaciones sobre un arreglo plano.
3. Representa un empaquetado estructurado basico que asocia de forma indivisible a la clave con su valor respectivo dentro de las casillas de almacenamiento.
4. Toma una clave de entrada y genera un identificador numerico entero, que sera acotado matematicamente para encajar dentro de los limites del tamaño actual de la coleccion.
5. Ocurren debido a los limites de espacio natural en la coleccion de arreglos finita frente a la ilimitada cantidad teorica de datos a ingresar.
6. El factor de carga ilustra en un numero fraccionario la ocupacion actual en relacion a la extension del almacen de reserva en memoria principal.
7. Es el procedimiento operativo donde la coleccion reasigna todo su contenido a un nuevo arreglo al cambiar sus dimensiones.
8. Mide las acciones fisicas del rendimiento, cuantificando los recorridos internos de bucles, la longitud de las colisiones superpuestas y cantidad de inserciones fallidas o logradas.
9. Decide las fases de incremento de la extension de almacenamiento, verificando cuando el limite superior, ocupacion falsa o reduccion sobrepasan parametros preestablecidos.
10. Posee un rendimiento previsible de escasas operaciones de forma amortizada y veloz ante casos probables. Mientras, los arboles estructurados previenen las variaciones extremas logrando operaciones controladas en forma continua y sin excepciones lineales.


### Bloque 3

1. El arreglo principal aloja cabeceras pre-asignadas. Los contenedores secundarios conservan las variables introducidas y operan dinamicamente con listas.
2. Porque el limite no lo imponen las cabeceras individuales de memoria, sino la extension dinamica adicional anclada a cada una de ellas que escala a demanda.
3. Significa que hay una saturacion especifica y pobre dispersion generada en los valores ingresados, transformando el rendimiento en lineal.
4. Porque establece el pico de degradacion visible para cualquier futura consulta de peores escenarios operacionales.
5. Pierde el costo amortizado unitario en los instantes en donde se eleva la concentracion excesiva de los datos superando el ratio sugerido o por fallas de formula de entrada aleatoria.
6. El costo abarca un recuento continuo de cada variable anidada sobre sus antecesores requiriendo iterar linealmente dicha cantidad de pasos.
7. La distribucion de formulas computacionales impacta en la determinacion originaria, y la agrupacion local se rige por las casualidades agrupadas y el crecimiento no distribuido de volumenes densos de datos de entrada.

### Bloque 4

1. Porque si la funcion hash es la identidad, x modulo m mantendra el mismo residuo para multiplos de m.
2. Si se aplica una mezcla, el patron de colisiones cambia y ya no basta con sumar un multiplo de la capacidad para forzar que dos elementos caigan en el mismo bucket.
3. Para una capacidad de 8 y el bucket 3, usando mix64, encontre claves especificas probando secuencialmente desde cero.
4. Si se usan cadenas, la funcion de hash itera sobre los caracteres y luego aplica la mezcla, requiriendo generar combinaciones de letras para encontrar colisiones.
5. Es importante porque demuestra que una buena funcion hash resiste patrones simples de entrada, obligando a generar distribuciones mas uniformes en casos practicos.

### Bloque 5

1. Vacio declara casillas sin uso primario e inmaculadas. Lleno senala casillas portadoras de contenido vital actual. Eliminado funciona como marca sepulcral residual.
2. Si marca sepulcral se suplantara con estado Vacio inmaculado, cualquier travesia secuencial desencadenada previamente desde esa posicion interpretaria una finalidad falsa impidiendo ubicar fragmentos exiliados adyacentes.
3. El tamano unicamente pondera casillas de vida util, el tamano ocupado reune tambien las marcas residuales y desfasadas que afectan la busqueda iterativa futura.
4. Por efecto del paso del tiempo y sucesion de extirpaciones singulares que aumentan el residual inactivo sin disminuir formalmente el peso de ocupacion estructural base.
5. Las lecturas en busqueda consumen iteraciones excesivas, degradando su agilidad operativa unitaria y simulando sobrepoblacion sobre porciones desiertas reales.
6. Cuando el computo inactivo corrompe la proporcion activa limite del entorno y perjudica metricas latentes sin incrementar significativamente vida util real.
7. Requiere evaluar en linea continua todos los bloques concatenados e intervinientes incluyendo vestigios para certificar ausencia tras alcanzar zona inexplorada Vacio inmaculada.

### Bloque 6

1. La modalidad individual unicamente afirma pertenencia; el asociativo retiene datos subordinados, enlazando de manera inseparable identificadores y significados vinculantes.
2. Simboliza el medio principal inconfundible de indexacion referenciada.
3. Agrega dimension complementaria consultable o actualizable, dotando al indice previo de uso pragmatico informativo y operacional real.
4. Regresara el vinculo subordinado de forma segura empacada para denotar viabilidad, esquivando asi resultados ambiguos nulos directos.
5. Abandonara la operacion devolviendo falsedad rotunda al impedir manipulaciones sin existencia, omitiendo conteos alterados e invariantes sanos.
6. Detiene el proceso notificando falsedad de reasignacion para salvaguardar estado originario por concepto primitivo en base de operacion original implementada.
7. Porque aísla al consultante de interacciones de almacenamiento, forzando un pacto abstracto robusto y blindado, inmutable frente a optimizaciones profundas.

Tabla de dictamenes:
Accion insertar primera rinde exito real confirmando aumento de tamano interno. Accion obtener recobra envase exitoso. Accion sustraer falsa mantiene invariantes fijos confirmables.
Frecuencia basica operada rinde uso practico al sumar contadores iterativos bajo un nuevo ingreso suplantando antiguo contenido. Actualizaciones directas requeririan metodos mutables inyectados.

### Bloque 7

1. Es la acumulacion anomala donde sucesiones de valores llenan continuidades adyacentes, actuando como obstaculo aglomerado para busquedas o posicionamientos posteriores en el entorno.
2. Porque responde de manera basica por proximidad natural; en cualquier eventualidad adhiere componentes limitrofes engrosando inexorablemente zonas contiguas de manera previsible y constante.
3. Desea fragmentar agrupamientos primarios alejando repeticiones por espacios variables crecientes, rompiendo cercania lineal consecutiva de posicionamiento.
4. Proyecta desterrar patrones al dispersar con variables adicionales la ruta individual e introducir heterogeneidad direccional calculada segun variable unica de distribucion inicial y subsiguiente.
5. Nivela el coste penalizador igualando distancias de recorrido esperadas, protegiendo las discrepancias extremas, reubicando los valores que poseen mejores o mas cercanos asientos iniciales relativos.
6. El anidamiento segrega las demoras independizandolas del arreglo primordial principal en multiples apendices, reduciendo obstaculos cruzados que asfixian el arreglo estricto al saturarse dimensionalmente.
7. Una tabla de exploracion adyacente simple es ideal porque rinde bajo localidad, agilidad logica e instrucciones rapidas primitivas con requerimientos muy bajos de inicializacion y estructura formal.
8. Una tabla Robin Hood que distribuya costes unitarios es ideal porque mitiga el efecto pernicioso de prolongaciones agudas, nivelando picos de retardo inesperados, brindando busquedas seguras inalterables masivas continuas.
9. Sondeo adyacente simple declina visiblemente mas tras acumulaciones extensivas residuales post eliminacion masiva que requieren reensamblado urgente e imprevisible de mantenimiento riguroso operativo.


### Bloque 8

1. Exige desordenacion amplia sin predecibilidad intrinseca ni tendencia concentrada, garantizando simetria repartida teorica aplicable al rango fisico de representacion del escenario real operativo.
2. Un factor pernicioso inducido de datos fabricados externamente aprovecha esa regla invariable colapsando toda distribucion, logrando saturacion absoluta localizada lineal ineficiente destructora y perjudicial globalmente.
3. Refuerza un pilar de incertidumbre controlada determinando de manera aleatoria los multiplicadores combinados al inicializarse, impidiendo asi vulnerabilidades orquestadas intencionadas previas y externas de asimilacion.
4. Por su susceptibilidad inherente; si un test agrupa numeros sucesivos demostrara aparente eficacia aunque ante formaciones estructuradas por iteracion alfabetica similar revele acumulaciones extremas colisionantes severas latentes ocultas inicialmente.
5. Minimizar anomalias contiguas recae intrinsecamente en optimizar promedios unitarios y asegurar operaciones eficientes esperadas inalterables incluso cuando densidades reales ocupan limites criticos pre definidos sistematicamente operativos o limite estable global estricto original dictaminado.

### Bloque 9

1. El factor ocupacional activo rebasando la marca especificada porcentual autorizada activa inmediatamente la alerta respectiva de reorganizacion por expansion geometrica requerida fundamental e inalterable obligatoria para operar.
2. Acumulaciones residuales muertas abultando ocupacion inactiva aparente desencadenaran accion reactivadora mantenedora inyectando variables legitimas vivas extirpando vacios ilusorios en dimension conservada sin crecimiento espacial innecesario.
3. Desocupacion extrema relativa inferior al umbral limite tolerado ocasionara reduccion proporcional espacial salvando memoria excedente de retencion inactiva inservible.
4. Requiere reevaluar todo dato interno mediante rutinas matematicas completas de alojamiento consumiendo tiempo por elemento reinsertado al arreglo completamente limpio.
5. Su infrecuencia y reparticion teorica sobre multiples tareas pasadas triviales garantiza un promedio practico insignificante en uso sostenido y persistente constante regular sin percepcion grave observable real exterior.
6. Masivos aglutinamientos y estrechez inducen mayor tasa iterativa promedio para busqueda o instalacion al carecer la proximidad original vacante y engrosar colisiones sistematicas repetidas constantes progresivas extensas continuas.
7. Estadisticas compilan y registran cantidades formales unicas evidenciando transiciones excepcionales infrecuentes respecto a la suma absoluta gigantesca exitosa basica ordinaria.
8. Retardar o abolir limitaciones exacerba agrupamientos, eleva metricas maximas exploratorias, condena tiempos a variaciones lineales impredecibles lentificando todos requerimientos hasta niveles inoperables sistematicamente absolutos.

### Bloque 10

1. Entrada conjunto basico busca duplicados, retorna comprobacion exitosa si falla instalacion. Domina el rendimiento en tablas donde es necesario. El costo opera en busquedas breves garantizadas que contrastan con busquedas secuenciales completas comparativas cruzadas que generarian lentitud.
2. Para histogramas rinde asociando recuento enlazado al identificador de entrada iterado continuamente en secuencias limpias estandarizadas de lectura en archivos formales externos que rinden resultados agrupados exactos optimizados veloces garantizados de consulta inmediata sin lentitud cruzada o agrupacion lenta pre ordena estructurada arborea formal que se haria engorrosa por comparaciones ineficientes repetitivas.
