#include "Modelos.hpp"
#include <iostream>

using namespace std;

Persona::Persona(string n, int e) {
    nombre = n;
    edad = e;
}

string Persona::getNombre() {
    return nombre;
}
int Persona::getEdad() {
    return edad;
}

Paciente::Paciente(string i, string n, int e, string s) : Persona(n, e) {
    id = i;
    servicioDestino = s;
}

string Paciente::getId() {
    return id;
}

string Paciente::getServicioDestino() {
    return servicioDestino;
}

void Paciente::imprimirInfo() {
    cout << "ID: " << id
        << "| Nombre: " << nombre
        << "| Edad: " << edad
        << "| Servicio " << servicioDestino
}




