#include "StackHistorial.h"

#include <iostream>
using namespace std;

StackHistorial::StackHistorial() {
    Primero=nullptr;
}


void StackHistorial::mostrarHistorial() {
    if (Primero==nullptr) {
        cout << "No hay historial" << endl;
        return;
    }
    NodoPaciente* nodo = Primero;

    while (nodo!=nullptr) {
        nodo->paciente->imprimirInfo();
        nodo = nodo->siguiente;

    }



}

//Los tres metodos estandar para el LIFO
void StackHistorial::push(Paciente* paciente) {
    if (paciente==nullptr) {
        return;
    }
     NodoPaciente* nodo= new NodoPaciente(paciente);
     nodo -> siguiente= Primero;
     Primero=nodo;
}
void StackHistorial::pop() {
    if (Primero==nullptr) {
        return;
    }
    NodoPaciente* nodo= Primero;
    Primero = Primero->siguiente;

    delete nodo;
}
StackHistorial::~StackHistorial() {
    while (Primero!=nullptr) {
        pop();
    }
}
Paciente* StackHistorial::top() {
    if (Primero==nullptr) {
        return nullptr;
    }
    return Primero->paciente;
}




