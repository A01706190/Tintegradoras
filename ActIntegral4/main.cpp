//
//  main.cpp
//  ActIntegral2
//
//  Created by Israel Arroyo on 06/10/20.
// A01706190

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include "Location.h"
#include "QueueMap.h"
#include "Map.h"
#include "Splay.h"
#include "graph.h"
#include "RBT.h"

void menu(int& opcion)
{
    cout
    <<"\n\n1.- Buscar lugar visitado(find Splay)\n"
    <<"2.- Borrar lugar visitado(delete Splay)\n"
    <<"3.- Imprimir mapa(RBT)\n"
    <<"4.- Guardar en txt(RBT)\n"
    <<"5.- Agregar a lista(enqueue)\n"
    <<"6.- Visita terminada(dequeue)\n"
    <<"7.- Imprimir queue\n"
    <<"8.- Buscar en queue\n"
    <<"9.- Calcular ruta(grafo)\n"
    <<"0.- Salir\n";
    cout <<"Ingresa opcion valida: ";
    cin>>opcion;
    cout<<endl;
}

int main(int argc, const char * argv[])
{
    int x,y;
    SplayTree arbolSplay;
    QueueMap queue;
    int opcion = 10;
    string fileName,qFind,d;
    cout <<"\nMAPA DE LA CIUDAD\n\n"<<"Ingresa tu ubicacion\n"<<

    "Ubicacion en X: ";
    cin >> x;
    cout<<"Ubicacion en Y: ";
    cin >> y;
    cout<<"CARGANDO ARCHIVO...\n LISTO\n";

    int point[2] = {x,y}; //punto inicial(x,y)
    vector<string> v;
//    Map busca;
    File file("mapa.txt");
    v = file.read();
    Map mapita(v,point);

    while(opcion!=0)
    {
        Map busca;
        menu(opcion);
        switch (opcion)
        {
            case 1:
            {
                cout<<"Ingresa distancia:";
                int distancia;
                cin>>distancia;
                Location res = mapita.find(distancia);
                bool respuesta = false;
                respuesta = arbolSplay.find(res);

                if(respuesta)
                    cout<<"Visitado";
                else
                    cout<<"No visitado";

                break;
            }
            case 2:
            {
                cout<<"Ingresa distancia:";
                int distancia;
                cin>>distancia;
                Location res = mapita.find(distancia);
                bool respuesta = false;
                respuesta = arbolSplay.find(res);

                if(respuesta)
                    cout<<"Borrado";
                else
                    cout<<"Aun no visitado";

                break;
            }

            case 3:
                cout <<mapita.toStringDistance();
                break;
            case 4:
                cout<<"Guardar como: \n";
                cin>>fileName;
                file.write(mapita.toString(), fileName);//guardar datos de mapa
                cout<<"Listo\n";
                break;

            case 5:
            {
                cout << mapita.toStringDistance();
                cout<<"Ingresa distancia: ";
                cin>>d;
                Location aux = mapita.find(std::stoi(d));
                queue.enqueue(aux);
                break;
            }
            case 6:
            {
                queue.dequeue(arbolSplay);
                cout<<"Listo\n";
                break;
            }
            case 7:
                cout<<queue.toString();
                break;
            case 8:
                cout<<"Nombre a buscar: ";
                cin>>qFind;
                cout<<"Indice: "<<queue.qFind(qFind);
                break;
            case 9:
            {
                int from;
                int to;
                Graph routes;
                routes.loadGraphMat("routes.txt", 9, 9);
                cout<<"\n"<<routes.printNodes();
                cout<<"Ingresa tu origen: ";
                cin>>from;
                cout<<"Ingresa tu destino: ";
                cin>>to;
                if(from>=0 && from<=8 && to>=0 && to<=8)
                {cout<<routes.DFS(from,to);
                cout<<routes.BFS(from,to);}
                break;
              }

            default:
                opcion = 0;
                break;
        }
    }

 }
