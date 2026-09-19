#include "Servicio.h"

#include <iostream>
#include <ostream>

#include "Paciente.h"

using namespace std;

Servicio::Servicio(std::string n) {
    nombre = n;
}

string Servicio::getNombre() const {
    return nombre;
}

void Servicio::recibirPaciente(Paciente* p) {
    pacientes.agregarPaciente(p);
}

void Servicio::mostrarEstado() const {
    cout << "=== ESTADO " << nombre << " ===" << endl;
    cout << "Pacientes en el departamento de " << nombre << ": " << pacientes.getCantidad() << endl;
    pacientes.mostrarPacientes();
}

Paciente *Servicio::buscarPaciente(std::string id) {
    return pacientes.buscarPaciente(id);
}
