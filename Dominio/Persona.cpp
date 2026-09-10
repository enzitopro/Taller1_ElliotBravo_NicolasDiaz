#include "Persona.h"
using namespace std;

Persona::Persona(string n, int e) {
    nombre = n;
    edad = e;
}

string Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}
