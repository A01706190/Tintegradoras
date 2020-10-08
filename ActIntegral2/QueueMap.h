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

using namespace std;
class QueueMap;

class Node
{
    /*Nodos de la lista, almacenan la direccion del siguiente nodo y un valor Location*/
private:
    Node();
    Node(Location&);
    Node(Location&, Node*);
    Location value;
    Node* next;
    
    friend class QueueMap;
};

Node:: Node()
{
    Location value;
    next = 0;
}

Node:: Node(Location& source)
{
    value = source;
    next = 0;
}
Node:: Node(Location& v, Node* n): value(v), next(n){}

class QueueMap
{
    /* Lista de ubicaciones por reconocer, es posible agregar ubucaciones al final(enqueue) o eliminar la primera en la lista (dequeue)*/
private:
    Node* head;
    Node* tail;
    int size;
public:
    QueueMap();
    int qFind(string);
    void enqueue(Location);
    void dequeue();
    string toString() const;
 
};

QueueMap::QueueMap():head(0), size(0){}// lista vacia


void QueueMap::enqueue(Location newVal)
{
    /* Agrega un objeto Nodo al ultimo lugar en la lista. Recibe un objeto Location que se asignara como su valor*/
    Node *newLink;
    newLink = new Node(newVal);
    
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
    if(head == 0)
        return -1;
    Node* p;
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

void QueueMap::dequeue()
{
    /* Elimina el primer el emento de la lista*/
    if (head == 0) // if empty
        return;
    Node* p;
    p = head;
    head = p->next; // head se mueve a siguiente elemento
    delete p;
    size--;
    
}



string QueueMap::toString() const
{
    if (head == 0) // if empty
        return "empty";
    stringstream aux;
    Node *p;
    p = head;
    aux << "[";
    while (p != 0)
    {
//        recorrido de la lista
        aux << p->value.toString();
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
