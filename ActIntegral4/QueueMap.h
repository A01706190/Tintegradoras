//
//  QueueMap.h
//  ActIntegral2
//
//  Created by Israel Arroyo on 06/10/20.
// A01706190

#ifndef QueueMap_h
#define QueueMap_h

#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <math.h>
#include <cmath>
#include "Location.h"
#include "RBT.h"

using namespace std;
class QueueMap;

class NodeQ
{
    /*Nodos de la lista, almacenan la direccion del siguiente nodo y un valor Location*/
private:
    NodeQ();
    NodeQ(Location&);
    NodeQ(Location&, NodeQ*);
    Location value;
    NodeQ* next;

    friend class QueueMap;
};

NodeQ:: NodeQ()
{
    Location value;
    next = 0;
}

NodeQ:: NodeQ(Location& source)
{
    value = source;
    next = 0;
}
NodeQ:: NodeQ(Location& v, NodeQ* n): value(v), next(n){}

class QueueMap
{
    /* Lista de ubicaciones por reconocer, es posible agregar ubucaciones al final(enqueue) o eliminar la primera en la lista (dequeue)*/

private:
    NodeQ* head;
    NodeQ* tail;
    int size;
public:
    QueueMap();
    int qFind(string);
    void enqueue(Location);
    void dequeue(SplayTree&);
    string toString() const;

};

QueueMap::QueueMap():head(0), size(0){}// lista vacia


void QueueMap::enqueue(Location newVal)
{
    /* Agrega un objeto Nodo al ultimo lugar en la lista. Recibe un objeto Location que se asignara como su valor*/
    /*
     Precondition: Lista queue valida
     Postcontidion: lista queue con dato agregado
     Input: valor a agregar
     Output:
     */
    NodeQ *newLink;
    newLink = new NodeQ(newVal);

    if(head == 0)
    {
//        add empty
        // head y tail se mueven a nuevo elemento
        head = newLink;
        tail = newLink;
    }
    else
    {
//       add last
        tail->next = newLink;
        tail = newLink;
    }

    size++;
}

int QueueMap::qFind(string val)
{
    /* Busqueda secuencial de la lista que devuelve el inidce del valor, si es encontrado. De lo contrario devolverá un -1*/
    /*
     Precondition: queue valido
     Postcontidion:
     Input: valor a buscar
     Output: indice de valor
     */
    if(head == 0)
        return -1;
    NodeQ* p;
    p = head;
    int position = 0;
    while(position < size)
    {
//    Recorrido de la lista hasta size-1
        if (val == p->value.getName())
            return position;

        position++;
        p = p->next;
    }
    return -1;
}

void QueueMap::dequeue(SplayTree& tree)
{
    /* Elimina el primer el emento de la lista*/
    /*
     Precondition: queue valido
     Postcontidion: queue con dato eliminado
     Input: splay tree para añadir dato eliminado
     Output:
     */
    if (head == 0) // if empty
        return;

    NodeQ* p;
    p = head;
    head = p->next; // head se mueve a siguiente elemento

    tree.add(p->value);
//    cout<<p->value.getDistance();
    delete p;
    size--;

}



string QueueMap::toString() const
{
    /*
     Precondition: queue valido
     Postcontidion:
     Input:
     Output: string de queue
     */
    if (head == 0) // if empty
        return "empty";
    stringstream aux;
    NodeQ *p;
    p = head;
    aux << "[";
    while (p != 0)
    {
//        recorrido de la lista
        aux << p->value.toString();
//        aux <<"Distancia" <<p->value.getDistance();
        if (p->next != 0)
        {
            aux << ", ";
        }
        p = p->next;
    }
    aux << "]";
    return aux.str();
}

#endif /* QueueMap_h */
