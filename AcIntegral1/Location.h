//
//  Location.h
//  AcIntegral1
//
//  Israel Arroyo
//  A01706190
//
#ifndef loc_h
#define loc_h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Location
{
private:
    string name;
    int x;
    int y;
    int distance;
public:
    Location(string, int arr[]);
    Location();
    int getX();
    int getDistance();
    int calcDistance(int arr[]);
    string toString();
    
};
Location::Location()
{
    name = "nan";
    x = 0;
    y = 0;
    distance = 0;
}
Location::Location(string datos, int arr[])
{
//  asigna atributos y calcula distancia
    string tmp;
    stringstream stream(datos);
    vector<string> words;

    while(stream >> tmp)
    {
        words.push_back(tmp);
    }
    
    name = words[0];
    x = stoi(words[1]);
    y = stoi(words[2]);
    distance = calcDistance(arr);
}
string Location::toString()
{
    stringstream aux;
    aux << name <<" ("<<x<<","<<y<<") "<<"distancia: "<< distance<<"m ";
    return aux.str();
}
int Location::calcDistance(int arr[])
{
//    calcula distancia a punto indicado
    int x1 = arr[0];
    int y1 = arr[1];
    int aux1 = pow(x - x1,2);
    int aux2 =pow(y - y1,2);
    int d = sqrt(aux1 + aux2);
    return d;
}
int Location::getX()
{return x;}
int Location::getDistance()
{return distance;}

#endif /* loc_h */

