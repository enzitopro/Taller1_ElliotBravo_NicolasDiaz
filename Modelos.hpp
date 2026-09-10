#ifndef  MODELOS_HPP
#define MODELOS_HPP
#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;
public:
    Persona(std::string nombre, int edad);
    virtual ~Persona();

    std::string getNombre();
    int getEdad();
};

class Paciente : public Persona {
private:
    std::string id;
    std::string servicioDestino;
public:
    Paciente(std::string nombre, int edad, std::string servicioDestino);

    std::string getId();
    std::string getServicioDestino();
    void imprimirInfo();
};

#endif
