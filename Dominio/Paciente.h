#ifndef PACIENTE_H
#define PACIENTE_H
#include "Persona.h"
#include <string>

class Paciente : public Persona {
private:
    std::string id;
    std::string servicioDestino;
public:
    Paciente(std::string id, std::string nombre, int edad, std::string servicioDestino);
    std::string getId() const;
    std::string getServicioDestino() const;
    void imprimirInfo() const;
};

#endif
