#include "ColaPacientes.h"
#include <iostream>
using namespace std;
ColaPacientes::ColaPacientes() {
    inicio=nullptr;
    fin=nullptr;
}

//Insertamos el dato al final de la cola
void ColaPacientes::push(Paciente *paciente) {
    if (paciente==nullptr) {
        return;
    }

    NodoPaciente* nodo=new NodoPaciente(paciente);

    if (inicio==nullptr) {
        inicio=nodo;
        fin=nodo;
    }
    else {
        fin->siguiente=nodo;
        fin=nodo;
    }
}
//Elminamos el dato que esa al inicio
void ColaPacientes::pop() {
    if (inicio==nullptr) {
        return;
    }
    //Guardamos el nodo que queremos borrar
    NodoPaciente* nodo=inicio;
    inicio=inicio->siguiente;
    //BVerificamos si la cola esta vacia ambos deberian quedar en null
    if (inicio==nullptr) {
        fin=nullptr;

    }
    delete nodo;
}

//Obetemos el dato que esta al inicio de la cola
Paciente *ColaPacientes::front() {
    if (inicio==nullptr) {
        return nullptr;
    }
    return inicio->paciente;
}
ColaPacientes::~ColaPacientes() {
    while (inicio!=nullptr) {
        //Reutilizamos el metodo que creamos mientras queden nodos vamos quitando el primero
        pop();
    }
}

void ColaPacientes::mostrarPacientes() {
if (inicio==nullptr) {
    return;
}

NodoPaciente* nodo=inicio;
    while (nodo!=nullptr) {
      nodo->paciente->imprimirInfo();
        nodo=nodo->siguiente;
    }
}
