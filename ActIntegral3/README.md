# Actividad Integral 3
Israel Iván Arroyo Parada
A01706190
## Table of contents
* [Información general](#información-general)
* [QueueMap.h](#queuemap.h)
* [Casos de prueba](#casos_de_prueba)

## Información general
Este programa presenta un tablero con varias ubicaciones, entre ellas, la del usuraio.
En esta enrega se cambia la manera de almacenar las ubicaciones en el mapa, ahora se ordena y almacena con un arbol AVL. También se integra una memoria de los lugares que se han visitado en forma de un Splay Tree.

## Map.h
Map cambia, con respecto a sus versiones anteriores, con la implementacion de un árbol AVL (discutido más a fondo en su respectiva sección) para almacenar todas las locaciones dadas por el archivo txt.
### find()
Esta operación está garantizada a ser **O(logn)**, utiliza como apoyo el find de  AVL.h. Al tener las restricciones de un árbol AVL, no se presentan casos degenerados. El peor de los casos se sigue tratando con un árbol balanceado.
## AVL.h (Nueva estructura de datos)
### Investigación
Este árbol parte de un BST y agrega restricciones nuevas para evitar casos degenrados, en donde se tenga, basicamente, una lista larga y se deban recorrer todos los elementos. Para lograr esto se tienen restricciones estrictas, en donde no se permiten cargas mayores del lado derecho o izquierdo, en cualquier nodo. Entonces, se hace un chequeo con cada inserción y eliminación de nodos. Después de esto se hacen rotaciones hasta llegar a un árbol balanceado.
### Ejemplos
https://www.quora.com/What-are-some-real-world-applications-of-AVL-trees-today?share=1
Los árboles auto balanceados son muy utilizados en el almacenaje de datos, pues se pueden hacer búsquedas e inserciones rápidas a pesar de tener muchos datos.
Los árboles AVL hacen operaciones muy costosas que pueden llegar a ser O(n), por esto no son tan utilizados. Algunos ejemplos de árboles AVL son:
- Búsquedas rápidas: En una base de datos pequeña en el que sea necesario tener los datos mucho más cerca de la raíz.
- Alta capacidad de cómputo: Un sistema como una Raspberry con mayor cantidad de cómputo que deba mantener datos de manera ordenada.
### find()
Esta función tiene un tiempo de **O(logn)**, como se habia mencionado en la anterior sección. Sin tomar en cuenta la función check().
### remove() y add()
Ocurre los mismo que con la función find(), tiene un tienmpo de **O(logn)**. El recorrido de buscar el valor y eliminarlo está garantizado a ser logn. Esto es, sin considerar que se manda a llamar a check, que tiene otra complejidad.
### check()
Tiene una complejidad de **O(logn)**. Con la implementación de parent en los nodos, se logra recorrer solo la rama modificada. Se toma el nodo añadido o eliminado y se hace un recorrido hasta el nodo
### balance()
https://www.geeksforgeeks.org/avl-tree-set-1-insertion/
Su complejidad es constante **O(1)**. Cada operación de rotación mueve una cantidad definida de apuntadores. Dependiendo del caso aumenta la cantidad de apuntadores que se mueven, pero esto es independiente del tamaño del árbol.
## Splay.h
De acuerdo con https://www.geeksforgeeks.org/splay-tree-set-1-insert/, cualquier operacion de un Splay tree tiene un tiempo de **O(logn)**. Pero es importante aclarar que se puede llegar a un caso **O(n)**, si las inserciones llevan a un árbol degenerado. En este caso, se tomará un caso común con un árbol balanceado con complejidad promedio de O(logn).
### Splay()
Tiene una complejidad **O(logn)**. Esto se debe al recorrido que se debe hacer para llevar un nodo a la raíz. En el peor de los casos se haría un Splay en una hoja y se tendría que hacer un recorrido por cada nivel, resultando en un tiempo de O(logn)
### find()
Si tenemos en cuenta un árbol balanceado, se trata de una complejidad de **O(logn)**. Este es el caso promedio, solo solo se sigue el camino para llegar a el nodo deseado, haciendo una operacion por cada nivel.
### remove() y add()
Igualmente, tienen un tiempo de **O(logn)**. Sucede lo mismo que con find(). En estos tres casos se debe aclarar que no se toma en cuenta la operación Splay.

## Node.h
Contiene los nodos utilizados por las estructuras AVL y SplayTree. Contiene las funciones auxiliares para hacer búsquedas, eliminaciones, impresiones, etc. Estas funciones auxiliares tienen la complejidad discutida en cada árbol que la utiliza.
## QueueMap.h
### qFind()
La función de find en una lista ligada corre en un tiempo de **O(n)**. Solo es posible recorrer esta estructura de nodo a nodo, hasta encontrar el valor deseado o haber recorrido la lista entera. 
### enqueue()
Agregar un elemento a la lista tiene un tiempo de **O(1)**. Ya que en un queue solo es posible añadir elementos hasta el final de la lista, el tiempo es estrictamente constante.
### dequeue()
El tiempo de dequeue es  **O(1)**. Al igual que enqueue, solo se peude acceder a una localidad de la lista. En este caso solo se elimina el primer elemento de la lista.
## Location.h
Objeto que almacena el nombre de la ubicación y las coordenadas de dicho lugar. Despés calcula la disatancia con respecto a una ubicación dada.
### calcDistance
Toma los valores de X y de Y de un punto dado y los propios del objeto. Con esto, usando el teorema de pitágoras, se calcula la distancia entre los dos puntos y se asigna a la propiedad "distance".
## File.h
Lee un archivo txt y escribe un nuevo archivo la lista de ubicaciones ordenadas. El formato debe ser:
> "Nombre" "X" "Y"
El formato de salida es:
> "Nombre" "(X,Y)" "Distancia del punto dado"

# test.cpp(casos de prueba)
Los casos de pureba se encuentran en el archivo test.cpp. Ahí se hacen pruebas para las funciones más imortatntes.
## Caso 1
### Input: 
Coordenadas iniciales (0,0)
#### Locaciones ingresadas:
"miCasa 56 64" distancia 85
"tuCasa 24 80" distancia 83
"vineria 100 100" distancia 141
"cafeteria 60 20" distancia 63
#### Output: 
Caso 1 Enqueue
[miCasa 56 64, tuCasa 24 80, vineria 100 100, cafeteria 60 20]


## Caso 2
### Input: 
Coordenadas iniciales (0,0)
(Output pasado) [miCasa 56 64, tuCasa 24 80, vineria 100 100, cafeteria 60 20]
#### Dequeue 2 veces.
### Output: 
Caso 2 Dequeue
[vineria 100 100, cafeteria 60 20]

## Caso 3
### Input:
Coordenadas iniciales (0, 0)
#### Locaciones ingresadas:
"miCasa 56 64" distancia 85
"tuCasa 24 80" distancia 83
"vineria 100 100" distancia 141
"cafeteria 60 20" distancia 63
### Output
#### Construcción de árbol
//        85 miCasa
        /    \
      /        \
  83 tuCasa  141 vineria
 /
63 cafeteria
Caso 3 AVL add
1. in order: [cafeteria 60 20 , tuCasa 24 80 , miCasa 56 64 , vineria 100 100]
2. pre order: [miCasa 56 64 , tuCasa 24 80 , cafeteria 60 20 , vineria 100 100]

## Caso 4
### Input
Coordenadas iniciales (0,0)
1. Encontrar 83
2. Eliminar tuCasa
### Output
Caso 4 AVL find & remove
1. tuCasa 24 80
2. in order: [cafeteria 60 20 , miCasa 56 64 , vineria 100 100]
2. pre order:[miCasa 56 64 , cafeteria 60 20 , vineria 100 100]

## Caso 5
### Input
Coordenadas iniciales (0,0)
#### Locaciones ingresadas:
"miCasa 56 64" distancia 85
"tuCasa 24 80" distancia 83
"vineria 100 100" distancia 141
"cafeteria 60 20" distancia 63
#### Output 
//     63 cafeteria
        \
         141 vineria
         /
        85 miCasa
         \
          83 tuCasa
1. in order: [cafeteria 60 20 , tuCasa 24 80 , miCasa 56 64 , vineria 100 100]
2. pre order: [cafeteria 60 20 , vineria 100 100 , tuCasa 24 80 , miCasa 56 64]

## Caso 6
### Input
Coordenadas iniciales (0,0)
1. Encontrar tuCasa
2. Eliminar tuCasa
#### Output 
Caso 6 SplayTree find & remove
1. in order:  [cafeteria 60 20 , tuCasa 24 80 , miCasa 56 64 , vineria 100 100]
1. pre order: [tuCasa 24 80 , cafeteria 60 20 , vineria 100 100 , miCasa 56 64]
2. in order: [cafeteria 60 20 , miCasa 56 64 , vineria 100 100]
2. pre order: [cafeteria 60 20 , vineria 100 100 , miCasa 56 64]
