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
    ofstream doc(newFileName);
    doc<<texto;
    doc.close();
}

#endif /* file_h */

