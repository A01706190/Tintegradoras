//
//  Map.h
//  AcIntegral1
//
//  Israel Arroyo
//  A01706190
//
#ifndef map_h
#define map_h

#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>
#include <cmath>
#include "Location.h"

using namespace std;

class Map
{
    /* Contiene un vector con objetos Location y esta encargada de ordenar, imprimir y encontrar algun valor*/
private:
    Avl locationsTree;
    
public:
    Map(vector<string>&, int arr[]);
    Map();
    
    void setLocations(vector<Location>);
    string toString();
    string toStringDistance();
    Location find(int);
};
Map::Map(){Avl locationsTree;}

Map::Map(vector<string>& v, int arr[])
{
//  separa datos de un string
    Location aux;
    for(int i = 0; i < v.size(); i++)
    {
        Location aux(v[i], arr);
        locationsTree.add(aux);
    }
    
}

void Map::setLocations(vector<Location> vec)
{
//    Agrega una Locaiton al vector
    /*
     Precondition:
     Postcontidion:
     Input:
     Output:
     */
    for(int i = 0; i<vec.size(); i++)
    {
        locationsTree.add(vec[i]);
    }
}

string Map::toString()
{
    /*
     Precondition:
     Postcontidion:
     Input:
     Output:
     */
    stringstream aux;
    if(!locationsTree.empty())
        aux<<locationsTree.inorderList();
    
    return aux.str();
}
string Map::toStringDistance()
{
    /*
     Precondition:
     Postcontidion:
     Input:
     Output:
     */
    stringstream aux;
    if(!locationsTree.empty())
        aux<<locationsTree.inorderListDistance();
    
    return aux.str();
}

Location Map::find(int val)
{
    /*
     Precondition: avl valido
     Postcontidion:
     Input: valor a buscar
     Output: objeto Location encontrado
     */
    return locationsTree.find(val);
}


#endif /* map_h */
