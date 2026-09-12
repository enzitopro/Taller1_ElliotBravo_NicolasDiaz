#include "Hospital.h"
#include <iostream>
#include <fstream> // libreria para leer
#include <sstream>// libreria para separar
#include <string>

using namespace std;

void Hospital::lecturaPacientes() {

    ifstream archivo("pacientes.txt");
    if (!archivo.is_open()) {
        cout << "no encontrado" << endl;
    }

    string linea;
    while (getline(archivo,linea)) {
        // libreria sstream para separar 
        stringstream streamLinea(linea);

        string id;
        string nombre;
        string edad;
        string servicio;

        getline(streamLinea, id, ';');
        getline(streamLinea, nombre, ';');
        getline(streamLinea, edad, ';');
        getline(streamLinea, servicio,';');

        int edadBueno;

        //para leer el texto
        stringstream stringAInt(edad);

        //guardamos el entero en edadBueno
        stringAInt >> edadBueno;


    }
    archivo.close();
}


