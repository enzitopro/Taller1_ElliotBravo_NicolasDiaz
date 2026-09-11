#ifndef SERVICIO_H
#define SERVICIO_H
#include <string>
#include "../Logica/ListaPacientes.h"

class Servicio {
private:
    std::string nombre;
    ListaPacientes pacientes;
public:
    Servicio(std::string nombre);
    std::string getNombre() const;
    void recibirPaciente(Paciente* p);
    void mostrarEstado() const;
};

#endif