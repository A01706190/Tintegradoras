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
void prueba()
{
    vector<string> v;
    File file("mapa.txt");
    v = file.read();
    
//    Caso 1
    cout<<endl<<"CASO 1"<< endl;
    int arr1[2] = {1,1};
    Map mapa1(v,arr1);
    mapa1.sort();
    cout<<mapa1.toString();
//    Caso 2
    cout<<endl<<"CASO 2"<< endl;
    int arr2[2] = {-10,-50};
    Map mapa2(v,arr2);
    mapa2.sort();
    cout<<mapa2.toString();
//    Caso 3
    cout<<endl<<"CASO 3"<< endl;
    int arr3[2] = {1,1};
    Map mapa3(v,arr3);
    mapa3.sort();
    cout<<mapa3.toString();
//    Caso 4
    cout<<endl<<"CASO 4"<< endl;
    int arr4[2] = {1,1};
    Map mapa4(v,arr4);
    Map res4_1;
    Map res4_2;
    Map res4_3;
    Map res4_4;
    mapa4.sort();
    mapa4.find(0,0,res4_1);
    mapa4.find(0,10,res4_2);
    mapa4.find(10,100,res4_3);
    mapa4.find(-10,-10,res4_4);
    cout <<"1. "<< res4_1.toString();
    cout <<"2. "<< res4_2.toString();
    cout <<"3. "<< res4_3.toString();
    cout <<"4. "<< res4_4.toString();
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

    while(opcion!=6)
    {
        Map busca;
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
    
//   prueba();
   
    
    return 0;
}
