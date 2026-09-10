#include "Paciente.h"
#include <iostream>

using namespace std;

Paciente::Paciente(string i, string n, int e, string s) : Persona(n, e){
    id = i;
    servicioDestino = s;
}

string Paciente::getId() const {
    return id;
}

string Paciente::getServicioDestino() const {
    return servicioDestino;
}

void Paciente::imprimirInfo() const {
    cout << "ID: " << id
    << " | Nombre: " << nombre
    << " | Edad: " << edad
    << " | Servicio: " << servicioDestino << endl;
}
