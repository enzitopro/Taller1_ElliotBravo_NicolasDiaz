
#ifndef TALLER1_ELLIOTBRAVO_NICOLASDIAZ_HOSPITAL_H
#define TALLER1_ELLIOTBRAVO_NICOLASDIAZ_HOSPITAL_H
#include "../Logica/ColaPacientes.h"


class Hospital {
    private:
    ColaPacientes colaPacientes;





public:
    void lecturaPacientes();
    void mostarPacientes();
};

#endif
