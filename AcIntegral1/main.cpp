//
//  main.cpp
//  AcIntegral1
//
//  Israel Arroyo
//  A01706190
//

#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"
#include "File.h"
#include "Location.h"
using namespace std;

void menu(int& opcion)
{
    cout <<"¿Que deseas hacer?"<<endl;
    cout <<"1.- Cargar localizaciones\n"<<"2.- Ordenar(de mas cercano a mas lejano)\n"
    <<"3.- Buscar rango\n"<<"4.- Imprimir en pantalla\n"<<"5.- Guardar en txt\n"<<"6.- Salir\n";
    cin>>opcion;
}

int main(int argc, const char * argv[])
{
    int x,y,from,to;
    int opcion = 0;
    bool sorted = false;
    string fileName;
    cout <<"MAPA DE LA CIUDAD\n\n"<<"Ingresa tu ubicacion\n"<<
    "Ubicacion en X: ";
    cin >> x;
    cout<<"Ubicacion en Y: ";
    cin >> y;
    
    int point[2] = {x,y}; //punto inicial(x,y)
    vector<string> v;
    Map busca;
    File file("mapa.txt");
    v = file.read();
    Map mapita(v,point);
//    cout <<mapita.toString();
    
    while(opcion!=6)
    {
        menu(opcion);
        switch (opcion) {
            case 1:
                cout<<"Listo\n";
                break;
                
            case 2:
                mapita.sort();
                sorted = true;
                cout<<"Listo\n";
                break;
            case 3:
                from = 0;
                to = 0;
                cout<<"De (m): ";
                cin>>from;
                cout<<"Hasta (m): ";
                cin>>to;
                if(!sorted)
                    mapita.sort();
                mapita.find(from, to, busca);
                cout<<"\nUbicaciones encontradas:\n"<<busca.toString()<<"\n\n";
                break;
                
            case 4:
                cout <<mapita.toString();
                break;
            case 5:
                cout<<"Guardar como: \n";
                cin>>fileName;
                if(!sorted)
                    mapita.sort();
                file.write(mapita.toString(), fileName);
                cout<<"Listo\n";
                break;
                
            default:
                opcion = 6;
                break;
        }
        
    }
   
   
    
    return 0;
}
