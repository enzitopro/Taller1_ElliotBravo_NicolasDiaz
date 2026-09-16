//
// Created by nicol on 16-09-2026.
//

#ifndef TALLER1_ELLIOTBRAVO_NICOLASDIAZ_STACKHISTORIAL_H
#define TALLER1_ELLIOTBRAVO_NICOLASDIAZ_STACKHISTORIAL_H
#Include "NodoPaciente.h"
#include "NodoPaciente.h"

class StackHistorial {
private:
    NodoPaciente* Primero;

    public:
    StackHistorial();
    ~StackHistorial();

    void push(Paciente* paciente);
    void pop();
    Paciente* top();


    void mostrarHistorial();
}

















#endif //TALLER1_ELLIOTBRAVO_NICOLASDIAZ_STACKHISTORIAL_H
