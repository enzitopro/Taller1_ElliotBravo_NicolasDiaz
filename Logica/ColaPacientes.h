
#ifndef TALLER1_ELLIOTBRAVO_NICOLASDIAZ_COLAPACIENTES_H
#define TALLER1_ELLIOTBRAVO_NICOLASDIAZ_COLAPACIENTES_H
#include "NodoPaciente.h"

class ColaPacientes {
private:
    NodoPaciente* inicio;
    NodoPaciente* fin;


public:
    ColaPacientes();
    ~ColaPacientes();


    void push(Paciente* paciente);
    void pop();
    Paciente* front();
    void mostrarPacientes();



};

#endif //TALLER1_ELLIOTBRAVO_NICOLASDIAZ_COLAPACIENTES_H
