//
//  test.cpp
//  ActIntegral2
//
//  Created by Israel Arroyo on 06/10/20.
// A01706190

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>
#include "File.h"
#include "Location.h"
#include "QueueMap.h"
#include "Map.h"
#include "Node.h"
#include "Splay.h"
#include "RBT.h"
#include "graph.h"

int main(int argc, const char * argv[])
{

   int arr4[2] = {0,0};// ubicacion actual
   Location L1("miCasa 56 64",arr4);//distancia 85
   Location L2("tuCasa 24 80",arr4);//distancia 83
   Location L3("vineria 100 100",arr4);//distancia 141
   Location L4("cafeteria 60 20",arr4);//distancia 63
   // Location L5 ("pianta_village 7 10",arr4);
   // Location L6 ("noki_bay 5 9",arr4);
   // Location L7 ("sirena_beach 4 6",arr4);
   // Location L8 ("bianco_hills 11 7",arr4);
   // Location L9 ("pina_park 5 2",arr4);
   // Location L10 ("ricco_harbor 10 5",arr4);
   // Location L11( "corona_mountain 14 8",arr4);
   // Location L12 ("delfino_plaza 15 4",arr4);
   // Location L13 ("gelato_beach 7 7",arr4);

//    Caso 1 Queue enqueue
   cout<<"Caso 1 Enqueue"<< endl;
   QueueMap queue;
   queue.enqueue(L1);
   queue.enqueue(L2);
   queue.enqueue(L3);
   queue.enqueue(L4);
   cout<<queue.toString()<<endl;

//     Caso 2 Queue dequeue
   cout<<"Caso 2 Dequeue"<< endl;
       Rbt arbolA;// arbol auxiliar
       queue.dequeue(arbolA);
       queue.dequeue(arbolA);
   cout<<queue.toString()<<endl<<endl;


//   Caso 3 RBT add
   cout<<"Caso 3 RBT add"<< endl;
   Rbt avlTree;
   avlTree.add(L1);
   avlTree.add(L2);
   avlTree.add(L3);
   avlTree.add(L4);

   // avlTree.add(L5);
   // avlTree.add(L6);
   // avlTree.add(L7);
   // avlTree.add(L8);
   // avlTree.add(L9);
   // avlTree.add(L10);
   // avlTree.add(L11);
   // avlTree.add(L12);
   // avlTree.add(L13);

//        85 miCasa
//      /    \
//    /        \
//   83 tuCasa  141 vineria
//  /
// 63 cafeteria

   cout<< avlTree.inorder()<<endl;
   cout<< avlTree.preorder()<<endl;

//    Caso 4 AVL find & remove
    cout<<"Caso 4 RBT find & remove"<< endl;
    Location found = avlTree.find(83);
    cout<<found.toString()<<endl;
   avlTree.remove(L2);
   cout<< avlTree.inorder()<<endl;
   cout<< avlTree.preorder()<<endl<<endl;

//    cout<<found.toString();

//    Caso 5 SplayTree add
   cout<<"Caso 5 SplayTree add"<< endl;
   SplayTree splayTree;
   splayTree.add(L1);
   splayTree.add(L2);
   splayTree.add(L3);
   splayTree.add(L4);
//       63 cafeteria
//        \
//         141 vineria
//         /
//        85 miCasa
//         \
//          83 tuCasa
   cout<< splayTree.inorder()<< endl;
   cout<< splayTree.preorder()<<endl;

//    Caso 6 SplayTree find & remove
   cout<<"Caso 6 SplayTree find & remove"<< endl;
   splayTree.find(L2);
   cout<<"find"<< endl;
   cout<< splayTree.inorder()<< endl;
   cout<< splayTree.preorder()<<endl;
   splayTree.remove(L2);
   cout<<"remove"<< endl;
   cout<< splayTree.inorder()<<endl;
   cout<< splayTree.preorder()<<endl;
   
  //    Caso 7 grafo
    cout<<"Caso 7 Graph"<< endl;
    Graph grafo;
    grafo.loadGraphMat("grafo.txt",5,8);
    cout<<grafo.printAdjMat();

   return 0;
}
