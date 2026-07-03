### Algoritmos y Estructura de Datos

#### Librería base

```text
https://github.com/kapumota/CC-232/tree/main/Libreria_cc232
```


#### Puntaje máximo

Estos ejercicios corresponden a una participación adicional presencial. La calificación máxima es de **4 puntos**.

La solución debe usar la librería base indicada y debe ser sustentada con código, ejecución y explicación técnica.

#### Reglas generales

Cada estudiante deberá mostrar al inicio de su participación:

git status
git branch --show-current
git log --oneline -3

Cada estudiante debe trabajar en una rama con nombre identificable:

git checkout -b Nombre_rama

Al finalizar su implementación, debe registrar al menos un commit:

git add .
git commit -m "resuelve problema PXX de participacion"

El código debe compilar y ejecutarse en vivo.

No se aceptan participaciones basadas únicamente en teoría, lectura de código o soluciones que no puedan ser explicadas.

No se otorgan puntos automáticos por pasar al frente. 

Se realizará nuevos sorteos para los estudiantes que lleguen tarde.

### P18: Comparador AVL, Red-Black y hash bajo búsqueda intensiva

Construye un experimento con una misma colección de claves y muchas consultas.

Compara:

```text
AVL
Red-Black Tree
tabla hash
```

Las consultas deben incluir:

```text
búsquedas exitosas
búsquedas fallidas
mínimo
máximo
consulta por rango
```

Debes sustentar:

```text
qué estructura responde mejor búsquedas exactas
qué estructura responde mejor consultas ordenadas
por qué hash no resuelve naturalmente mínimo, máximo ni rango
por qué Red-Black puede aceptar más desbalance que AVL
```


Compilar 

```
g++ -std=c++17 -O2 -Iinclude demos/Problema18.cpp -o problema18
```
Ejecutar
```
-o problema18
```
