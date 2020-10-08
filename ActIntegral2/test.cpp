//
//  test.cpp
//  ActIntegral2
//
//  Created by Israel Arroyo on 06/10/20.
// A01706190

#include <stdio.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include "Location.h"
#include "QueueMap.h"
#include "Map.h"

int main(int argc, const char * argv[])
{
    
    
    int arr4[2] = {1,1};// ubicacion actual
    string l1("miCasa 56 64");
    string l2("tuCasa 24 80");
    string aa("nuestraCasa 40 20");
    string l3("vineria 100 100");
    string l4("cafeteria 60 20");
    
//    Caso 1

    cout<<endl<<"MergeSort"<< endl;
    vector<string> vec;//vector de almacenamiento
    
    vec.push_back(l1);
    vec.push_back(aa);
    vec.push_back(l3);
//    vec.push_back(l4);
    
    Map mapa1(vec,arr4);
    cout<<"\nAntes de ordenamiento\n"<<mapa1.toString();
    mapa1.sort();
    cout<<"\nDespues de ordenamiento\n"<<mapa1.toString();

    /* miCasa 56 64
     cafeteria 60 20
     vineria 100 100*/
    
//   Caso 2
    cout<<endl<<"MapFind(vector)"<< endl;
        
    Map mapa4(vec,arr4);
    mapa4.sort();
    cout <<"1. "<< mapa4.find("casa_azul").toString()<<endl;
    cout <<"2. "<< mapa4.find("cafeteria").toString()<<endl;

//    Caso 3
    Location L1("miCasa 56 64",arr4);
    Location L2("tuCasa 24 80",arr4);
    Location L3("vineria 100 100",arr4);
    Location L4("cafeteria 60 20",arr4);

    cout<<endl<<"Enqueue"<< endl;
    QueueMap queue;
    queue.enqueue(L1);
    queue.enqueue(L2);
    queue.enqueue(L3);
    queue.enqueue(L4);
    cout<<queue.toString()<<endl;
    

//    Caso 4
    cout<<endl<<"Dequeue"<< endl;
    queue.dequeue();
    
    cout<<queue.toString()<<endl;
//    Caso 5
    cout<<endl<<"QueueFind(LinkedList)"<< endl;
    cout<<queue.qFind("miCasa")<<endl;//no esxiste este valor, = -1
    cout<<queue.qFind("cafeteria")<<endl;// imprime 2


    return 0;
}
