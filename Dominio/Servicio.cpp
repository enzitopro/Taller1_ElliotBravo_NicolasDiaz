#include "Servicio.h"

#include "Paciente.h"
using namespace std;

Servicio::Servicio(std::string n) {
    nombre = n;
}

string Servicio::getNombre() const {
    return nombre;
}

void Servicio::recibirPaciente(Paciente* p) {

}

void Servicio::mostrarEstado() const {

}