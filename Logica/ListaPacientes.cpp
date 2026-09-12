#include "ListaPacientes.h"
#include <iostream>
using namespace std;

ListaPacientes::ListaPacientes() {
    inicio=nullptr;
}


//Destructor 
ListaPacientes::~ListaPacientes() {
    while (inicio != nullptr) {
        NodoPaciente* nodo = inicio->siguiente;
        delete inicio;
        inicio = nodo;
    }
}

void ListaPacientes::agregarPaciente(Paciente *p) {
    //verificamos que este el id del paciente sea valido
    if (p == nullptr) {
        cout << "Paciente no es valido!" << endl;
        return;
    }
    NodoPaciente* nodo = new NodoPaciente(p);

    // si esta vacia la lista el nodo pasa a ser el primero
    if (inicio == nullptr) {
        inicio = nodo;
        return;
    }
    // si no esta vacia la lita, necesitamos encontrar el ultimo para eso creamos un aux que recorra
    NodoPaciente* nodoActual = inicio;

    while (nodoActual->siguiente != nullptr) {
        nodoActual = nodoActual->siguiente;
    }
    nodoActual->siguiente = nodo;
}

void ListaPacientes::mostrarPacientes() const {
    //Verificamos que no este vacia
    if (inicio == nullptr) {
        cout << "No hay pacientes" << endl;
        return;
    }

    NodoPaciente* nodoActual = inicio;
    //Recorremos con un aux y imprimimos su info
    while (nodoActual != nullptr) {
        nodoActual-> paciente -> imprimirInfo();
        nodoActual = nodoActual->siguiente;
    }
}





