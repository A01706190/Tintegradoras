# Actividad Integral 1
Israel Iván Arroyo Parada
A01706190
## Table of contents
* [Información general](#información-general)
* [File.h](#file.h)
* [Location.h](#location.h)
* [Map.h](#map.h)

## Información general
Este programa presenta un tablero con varias ubicaciones, entre ellas, la del usuraio.
Dichas ubicaciones son dadas como input en un archivo de texto.
Como se muestra en el dibujo:

|..............................................................|
|................................. casa1.......................|
|.......casa2..................................................|
|..............................................................|
|.......tú......................................casa3..........|
|..............................................................|

Entonces, el programa está encargado de leer dicho archivo, almacenar cada ubicacion como un objeto; dentro de un vector, ordenarlo; de ubicación más cercana a más lejana, permitir la búsqueda e imprimirlo en otro archivo de texto.
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
Recibe dos ints para indicar rango de búsqueda para buscar y una referencia a un objeto Map. En el objeto Map se concatenan las ubicaciones encontradas. Se utiliza la búsqueda secuencial para enontrar facilmente ubicaciones contiguas.
La búsqueda secuencial corre en **O(n)**. Aunque se parta del supesto de un arreglo ordenado, en el peor de los casos se recorren todos los elementos hasta encontrar uno en particular. Consta de un solo "for loop"que recorre el arreglo. Por lo tanto, es O(n).
