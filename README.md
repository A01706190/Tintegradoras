# Tintegradoras
Tareas integradoras de TC1031.2 2020

## No fue necesario realizar ninguna correción

Este programa presenta un tablero con varias ubicaciones, entre ellas, la del usuraio.
Dichas ubicaciones son dadas como input en un archivo de texto.
Como se muestra en el dibujo:

    |.................................................................................|.  
    |.................................casa1...........................................|.  
    |......casa2......................................................................|.  
    |.................................................................................|.  
    |.......tú....................................casa3...............................|.  
    |.................................................................................|.   

En la carpetas se muestran las versiones del programa, conforme a los temas vistos en clase.

## ActIntegral1
Se implementa la primera versión con merge sort para determinar las ubicaciones mas cercanas, la búsqueda de rango y la interaccion con un archivo de texto. Todo esto almacenado en un vector de objetos.
## ActIntegral2
Se implementa una lista de lugares por visitar, usando un queue de listas ligadas simples. Entonces, se puede agregar un nuevo destino, que se encuentre en el mapa. Al mismo tiempo, se puede eliminar de la lista cuando ya se haya visitado el lugar.
## ActIntegral 3
Se corrigen comentarios en las funciones. Además, se implementa un árbol AVL para almacenarl objetos "localidades" y un árbol Splay. Este último sirve como un registro de los lugares que salen del queue. Esto simboliza una memoria que mantiene los registros mas recientes cerca de la raíz.
El árbol AVL funcionará como ordenamiento, además de almacén, y como estructura implementada extra.
## ActIntegral 4
Se implementa un sistema de grafos para poder calcular rutas entre las localidades del mapa. También se cambia el sistema de almacenamiento de un árbol AVL a uno RED-Black. Se hizo una correción al cálculo de distancias entre la coordenada ingresada y las localidades del mapa para evitar colisiones.
