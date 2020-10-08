//
//  main.cpp
//  ActIntegral2
//
//  Created by Israel Arroyo on 06/10/20.
// A01706190

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include "File.h"
#include "Location.h"
#include "QueueMap.h"
#include "Map.h"

void menu(int& opcion)
{

    cout
    <<"\n\n1.- Ordenar(de mas cercano a mas lejano)\n"
    <<"2.- Imprimir mapa\n"
    <<"3.- Guardar en txt\n"
    <<"----RECONOCIMIENTO (queue)----\n"
    <<"4.- Agregar a lista(enqueue)\n"
    <<"5.- Visita terminada(dequeue)\n"
    <<"6.- Imprimir queue\n"
    <<"7.- Buscar en queue\n"
    <<"0.- Salir\n";
    cout <<"Ingresa opcion valida: ";
    cin>>opcion;
    cout<<endl;

}

int main(int argc, const char * argv[])
{
    int x,y;
    QueueMap queue;
    int opcion = 10;
    bool sorted = false;
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
        switch (opcion) {
            case 1:
                mapita.sort();
                sorted = true;
                cout<<"Listo\n";
                break;

            case 2:
                cout <<mapita.toString();
                break;
            case 3:
                cout<<"Guardar como: \n";
                cin>>fileName;
                if(!sorted)
                    mapita.sort();
                file.write(mapita.toString(), fileName);//guardar datos de mapa
                file.write(queue.toString(),fileName);//guardar queue debajo
                cout<<"Listo\n";
                break;

            case 4:
            {
                cout << mapita.toStringDistance();
                cout<<"Ingresa nombre: ";
                cin>>d;
                Location aux = mapita.find(d);
                queue.enqueue(aux);
                break;
            }
            case 5:
                queue.dequeue();
                cout<<"Listo\n";
                break;
            case 6:
                cout<<queue.toString();
                break;
            case 7:
                cout<<"Nombre a buscar: ";
                cin>>qFind;
                cout<<"Indice: "<<queue.qFind(qFind);
                break;
            default:
                opcion = 0;
                break;
        }
    }

}
