# Actividad Integral 1
Israel Iván Arroyo Parada
A01706190
## Tabla de contenidos
* [Información general](#información-general)
* [File.h](#File.h)
* [Location.h](#Location.h)
* [Map.h](#Map.h)
* [Casos de prueba](#casos_de_prueba)

## Información general
Este programa presenta un tablero con varias ubicaciones, entre ellas, la del usuraio.
Dichas ubicaciones son dadas como input en un archivo de texto.
Como se muestra en el dibujo:

|..................................................................................|.  
|.................................casa1...........................................|.  
|......casa2......................................................................|.  
|..................................................................................|.  
|.......tú....................................casa3..............................|.  
|..................................................................................|.  

Entonces, el programa está encargado de leer dicho archivo, almacenar cada ubicacion como un objeto; dentro de un vector, ordenarlo; de ubicación más cercana a más lejana, permitir la búsqueda e imprimirlo en otro archivo de texto.

La comlejidad del programa, en general, es de O(n^2) si tomamos en cuenta los procesos que lleva a cabo. El ordenamiento y la búsqueda corren en tiempos de O(n*logn) y O(n^2), respectivamente. A grandes rasgos, el programa corre en un tiempo de O(n^2).

## File.h
Lee un archivo txt y escribe un nuevo archivo la lista de ubicaciones ordenadas. El formato debe ser:
- "Nombre" "X" "Y"

El formato de salida es:
- "Nombre" "(X,Y)" "Distancia del punto dado"

## Location.h
Objeto que almacena el nombre de la ubicación y las coordenadas de dicho lugar. Despés calcula la disrtancia con respecto a una ubicación dada.
### calcDistance
Toma los valores de X y de Y de un punto dado y los propios del objeto. Con esto, usando el teorema de pitágoras, se calcula la distancia entre los dos puntos y se asigna a la propiedad "distance".

## Map.h
Almacena una lista de objetos "Location" en un vector, junto con las siguientes operaciones.
### sort
Ordena la lista de "Locations" del objeto Map utilizando el algoritmo "Merge Sort". No recibe ni devuelve nada. Este método llama los siguientes métodos, que realizan todo el trabajo:
- mergeSplit
- copyArray
- mergeArray

El "sort" tiene un tiempo de **O(n*logn)**. "mergeSplit" corre en un tiempo O(n), pues se divide todo hasta llegar a arreglos de un solo elemento (si asumimos que se divide todo el arreglo antes de todo). La operación "mergeArray" debe comparar los elementos de dos arreglos y decidir cuál es menor. Esto está hecho en tiempo O(n), pero la operacion se hace con menos frecuencia en cada llamada iterativa. Este comportamiento es de O(logn) se divide el trabajo a la mitad mientras se mueve hacia arriba en los niveles del árbol recursivo. Por lo tanto, el tiempo es O(n*logn), el tiempo de "split" se descarta.
### find
Recibe dos ints para indicar rango de búsqueda para buscar y una referencia a un objeto Map. En el objeto Map se concatenan las ubicaciones encontradas. Se utiliza la búsqueda secuencial para enontrar facilmente ubicaciones contiguas. Pero, como se debe realizar la búsqueda para cada valor del rango dado, se convierte en una función de **O(n^2**).
La búsqueda secuencial corre en O(n). Aunque se parta del supesto de un arreglo ordenado, en el peor de los casos se recorren todos los elementos hasta encontrar uno en particular. Consta de un solo "for loop"que recorre el arreglo. Por lo tanto, es O(n).
Si agregamos el otro recorrido, podemos concluir que la función find corre en **O(n^2).**

## Casos de prueba
### Caso 1
#### Input: 
Coordenadas iniciales (1,1)
##### Output(ordenamiento): 
tiendita_de_la_esquina (1,0) distancia: 1m 
restaurante (2,3) distancia: 2m 
casa_de_carnicero (1,5) distancia: 4m 
casa_blanca (2,10) distancia: 9m 
casa_varde (1,10) distancia: 9m 
puente (6,16) distancia: 15m 
dulceria (20,20) distancia: 26m 
casa_azul (1,30) distancia: 29m 
panaderia (70,10) distancia: 69m 
casa_naranja (10,100) distancia: 99m 

### Caso 2
#### Input: 
Coordenadas iniciales (-10,-50)
##### Output(ordenamiento): 
restaurante (2,3) distancia: 54m 
casa_de_carnicero (1,5) distancia: 56m 
casa_blanca (2,10) distancia: 61m 
casa_varde (1,10) distancia: 61m 
puente (6,16) distancia: 67m 
dulceria (20,20) distancia: 76m 
casa_azul (1,30) distancia: 80m 
panaderia (70,10) distancia: 100m 
casa_naranja (10,100) distancia: 151m 

### Caso 3
#### Input:
Coordenadas iniciales (100, 200)
##### Output(ordenamiento): 
casa_naranja (10,100) distancia: 134m 
panaderia (70,10) distancia: 192m 
dulceria (20,20) distancia: 196m 
casa_azul (1,30) distancia: 196m 
puente (6,16) distancia: 206m 
casa_blanca (2,10) distancia: 213m 
casa_varde (1,10) distancia: 214m 
casa_de_carnicero (1,5) distancia: 218m 
restaurante (2,3) distancia: 220m 
tiendita_de_la_esquina (1,0) distancia: 223m 

### Caso 4
#### Input
Coordenadas iniciales (1,1)
1. Rango de 0m a 0m
2. Rango de 0m a 10m
3. Rango de 10m a 100m
4. Rango de -10m a -10m (a la redonda, por lo tanto, se toma como positivos)

##### Output (busqueda): 
1. nan (0,0) distancia: 0m 
2. tiendita_de_la_esquina (1,0) distancia: 1m , restaurante (2,3) distancia: 2m , casa_de_carnicero (1,5) distancia: 4m ,casa_varde (1,10) distancia: 9m , casa_blanca, (2,10) distancia: 9m 
3. puente (6,16) distancia: 15m, dulceria (20,20) distancia: 26m , casa_azul (1,30) distancia: 29m , panaderia (70,10) distancia: 69m , casa_naranja (10,100) distancia: 99m 
4. nan (0,0) distancia: 0m 
