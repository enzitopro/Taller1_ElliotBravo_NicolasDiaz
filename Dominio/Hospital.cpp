#include "Hospital.h"
#include <iostream>
#include <fstream> // libreria para leer
#include <sstream>// libreria para separar
#include <string>

#include "Paciente.h"
#include "../Logica/ColaPacientes.h"
using namespace std;

void Hospital::lecturaPacientes() {

    ifstream archivo("../Dominio/pacientes.txt");
    if (!archivo.is_open()) {
        cout << "no encontrado" << endl;
        return;
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

        Paciente* p = new Paciente(id,nombre,edadBueno,servicio);
        colaPacientes.push(p);


    }
    archivo.close();
}

void Hospital::mostrarPacientes() {
    colaPacientes.mostrarPacientes();
}

void Hospital::atenderPacientes() {
    Paciente * pacienteObjetivo = colaPacientes.front();
    string servicioObjetivo = pacienteObjetivo->getServicio();

}

Servicio* Hospital::buscarServicio(string nombreBuscado) {
    NodoServicio* cursor = inicioServicios;
    while (cursor != nullptr) {
        if (cursor->servicio->getNombre() == nombreBuscado) {
            return cursor->servicio;
        } else {
            cursor = cursor->siguiente;
        }
    }
    return nullptr;
}

Hospital::Hospital() {

}


