
#ifndef TALLER1_ELLIOTBRAVO_NICOLASDIAZ_HOSPITAL_H
#define TALLER1_ELLIOTBRAVO_NICOLASDIAZ_HOSPITAL_H
#include "../Logica/ColaPacientes.h"
#include "../Logica/NodoServicio.h"


class Hospital {
    private:
    ColaPacientes colaPacientes;
    NodoServicio* inicioServicios;
    Servicio* buscarServicio(std::string nombreBuscado);
    Hospital();
    ~Hospital();
public:
    void lecturaPacientes();
    void mostrarPacientes();
    void atenderPacientes();
};

#endif
