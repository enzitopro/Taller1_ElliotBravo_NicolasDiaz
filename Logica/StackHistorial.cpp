#include "StackHistorial.h"

#include <iostream>
using namespace std;

StackHistorial::StackHistorial() {
    Primero=nullptr;
}

void StackHistorial::push(Paciente* paciente) {
    if (paciente==nullptr) {
        return;
    }
     NodoPaciente* nodo= new NodoPaciente(paciente);
     nodo -> siguiente= Primero;
     Primero=nodo;
}

