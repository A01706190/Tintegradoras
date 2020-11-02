//
//  File.h
//  AcIntegral1
//
//  Israel Arroyo
//  A01706190
//
#ifndef file_h
#define file_h

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

class File
{
    /* Manejo de archivos. Leer, escribir en un txt dado*/
private:
    string fileName;
    
public:
    File(string);
    vector<string> read();
    void write(string, string);
    
};
File:: File(string name)
{
    fileName = name;
}

vector<string> File::read()
{
/* lee archivo txt y regresa cada línea como vector*/
    /*
     Precondition: archivo txt con formato
     Postcontidion:
     Input: archivo txt
     Output: vector con strings
     */
    vector<string> vec;
    ifstream doc(fileName);
    if (doc.is_open())
    {
        string aux;
        while(getline(doc,aux))
        {
            vec.push_back(aux);

        }
    }
    doc.close();
    return vec;
}
void File::write(string texto,string newFileName)
{
    /* recibe el nombre de un archivo txt y un string para guardar*/
    /*
     Precondition: nombre valido
     Postcontidion: archivo txt con string dado
     Input: string a guardar
     Output:
     */
    ofstream doc(newFileName);
    doc<<texto;
    doc.close();
}

#endif /* file_h */

