#ifndef NODOPACIENTE_H
#define NODOPACIENTE_H
#include "../Dominio/Paciente.h"

struct NodoPaciente {
    Paciente* paciente;
    NodoPaciente* siguiente;

    NodoPaciente(Paciente* p) {
        paciente = p;
        siguiente = nullptr;
    }
};

#endif