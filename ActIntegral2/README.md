# Actividad Integral 2
Israel Iván Arroyo Parada
A01706190
## Table of contents
* [Información general](#información-general)
* [QueueMap.h](#queuemap.h)
* [Casos de prueba](#casos_de_prueba)

## Información general
Este programa presenta un tablero con varias ubicaciones, entre ellas, la del usuraio.
Dichas ubicaciones son dadas como input en un archivo de texto.
Como se muestra en el dibujo:
______________________________________
|                                                                   |  
|                                  casa1                       |  
|       casa2                                                   |  
|                                                                   |  
|       tú                                      casa3          |  
| _____________________________________|  

Además de ordenar un vector, se implementó una estructura de listas ligadas para simular el recorrido de lugares. Entonces se agrega una ubicacion por visitar a la lista con cada enqueue. Por lo tanto, atiende en el orden de entrada. Así, al terminar de visitar un lugar de la lista, se elimina con un dequeue.
En este README se discute más a fondo las nuevas funciones implementadas con respecto a listas ligadas en Queue.
## QueueMap.h
### qFind()
La función de find en una lista ligada corre en un tiempo de **O(n)**. Solo es posible recorrer esta estructura de nodo a nodo, hasta encontrar el valor deseado o haber recorrido la lista entera. 
### enqueue()
Agregar un elemento a la lista tiene un tiempo de **O(1)**. Ya que en un queue solo es posible añadir elementos hasta el final de la lista, el tiempo es estrictamente constante.
### dequeue()
El tiempo de dequeue es  **O(1)**. Al igual que enqueue, solo se peude acceder a una localidad de la lista. En este caso solo se elimina el primer elemento de la lista.

## Casos de prueba
Los casos de pureba se encuentran en el archivo test.cpp. Ahí se hacen pruebas para las funciones más imortatntes; como el Merge sort, Find(dentro de un vector), Enqueue, Dequeue, find (de linked list). 
