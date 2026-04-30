## PC2 - CC232

### Estudiante
- Nombre: Brian Jair La Torre Urbina
- Código: 20240398C
- Problema asignado: 84. Largest Rectangle in Histogram
- Enlace: https://leetcode.com/problems/largest-rectangle-in-histogram/

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal
- Semana: Semana 4
- Estructura o técnica principal: Stack monotónica creciente

### Resumen de la solución
Recorrer cada una de las alturas del histograma para poder maximizar su base y conseguir el mayor área con esa altura, así ir comparando hasta conseguir el máximo de todo el histograma. 

### Complejidad
- Tiempo: $O(n)$
- Espacio: $O(n)$

### Invariante o idea clave
La pila monotónica creciente hace que siempre se ordenen de menor a mayor, cuando no lo hace significa que si o si se encontró su límite derecho de la altura que está en el tope al querer ingresar un valor menor. Por consecuente, también su límite izquierdo es definido por el siguiente tope de la pila. 

### Archivos relevantes
- include/
- src/
- tests/
- demos/
- MyREADME

### Compilación
```bash
cmake -S . -B build
cmake --build build
```

### Ejecución

Algoritmo Principal
```bash
./build/demo_largest_rectangle.exe
```

Tests
```bash
./build/test_largest_rectangle.exe
```

Benchmark
```bash
./build/benchmark_histogram.exe
```

En caso de querer correr el algoritmo Brute Force:
```bash
./build/demo_bruteforce.exe
```

### Casos de prueba
1. **Caso general**: Arreglo de entrada [2, 1, 5, 6, 2, 3] con salida esperada 10.
2. **Caso con valores repetidos**: Arreglo de entrada [2, 2, 2, 2] con salida esperada 8.
3. **Caso vacío**: Arreglo de entrada [ ] con salida esperada 0.

### Historial de commits
Indica que el historial debe verse en el video.

### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.



