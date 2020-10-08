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
    vector<Location> locations;
    
public:
    Map(vector<string>&, int arr[]);
    Map();
    
    void setLocations(vector<Location>);
    string toString();
    string toStringDistance();
    void sort();
    void mergeSplit(vector<Location>& , vector<Location>& , long , long );
    void copyArray(vector<Location>& , vector<Location>& , long , long );
    void mergeArray(vector<Location>& A, vector<Location>& B, long , long, long);
    Location find(string);
};

Map::Map()
{
//  coloca un objeto vacio
    Location aux;
    locations.push_back(aux);
}
Map::Map(vector<string>& v, int arr[])
{
//  separa datos de un string
    Location aux;
    for(int i = 0; i < v.size(); i++)
    {
        Location aux(v[i], arr);
        locations.push_back(aux);
    }
    
}

void Map::setLocations(vector<Location> vec)
{
//    Agrega una Locaiton al vector
    for(int i = 0; i<vec.size(); i++)
    {
        locations.push_back(vec[i]);
    }
}

string Map::toString()
{
    stringstream aux;
    if(locations.size()>1)
    {
        for (int i = 0; i < locations.size();i++)
        {
            aux << locations[i].toString()<<"\n";
        }
    }
    else
    {
        aux << locations[0].toString()<<"\n";
    }
    return aux.str();
}
string Map::toStringDistance()
{
    /* Devuelve un string con los "name" del vector de Location*/
    stringstream aux;
    if(locations.size()>1)
    {
        for (int i = 1; i < locations.size();i++)
        {
            aux<<" Lugar: "<<locations[i].getName()<<"\n";
        }
    }
    else
    {
        aux << locations[0].toString()<<"\n";
    }
    return aux.str();
}


void Map::sort()
{
//    interfaz de uso para MergeSort
    vector<Location> aux((long)locations.size());
    mergeSplit(locations,aux,0,(long)locations.size()-1);
}


void Map::mergeSplit(vector<Location>& A, vector<Location>& B, long first, long last)
{
//    first = principio de arreglo
//    last = final de arreglo
 
    if(first < last)
    {
        long mid = (first + last) / 2;
        
        mergeSplit(A, B, first, mid);
        mergeSplit(A, B, mid + 1, last);
        mergeArray(A, B, first, last,mid);
        copyArray(A, B, first, last);
    }
    
}


void Map::mergeArray(vector<Location>& A, vector<Location>& B, long first, long last, long mid)
{
    long i = first;
    long j = mid +1;
    long posB = first;

    //    i = principio de 1er arreglo
    //    j = principio de 2o arreglo
    //    mid = final de 1er arreglo
    
    
    while(i <= mid && j <= last)
    {
        if(A[i].getDistance() < A[j].getDistance())
        {
            B[posB] = A[i];
            i++;
        }
        else
        {
            B[posB] = A[j];
            j++;
        }
        posB++;
     }
    
    while(i <= mid)
    {
        B[posB] = A[i];
        posB++;
        i++;
    }
    while(j <= last)
    {
        B[posB] = A[j];
        posB++;
        j++;
    }

     
}


void Map::copyArray(vector<Location>& A, vector<Location>& B, long first, long last)
{

    for (long i = first; i <= last; i++) {
        A[i] = B[i];
    }
}

Location Map::find(string val)
{
// Busqueda secuencial de una Location que cincida con el input dado
    Location aux;

    int size = (int)locations.size();
    bool is_in = true;
    
    for(int i = 0; i<size && is_in; i++)
    {
        if (val == locations[i].getName())
            return locations[i];
    }
    
    return aux;
    
}


#endif /* map_h */
