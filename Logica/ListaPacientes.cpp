#include "ListaPacientes.h"
#include <iostream>
using namespace std;

Listapaciente::ListaPacientes() {
    inicio=nullptr;
}

Listapaciente::~ListaPacientes() {

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





