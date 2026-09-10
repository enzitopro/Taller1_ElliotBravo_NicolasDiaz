#ifndef PERSONA_H
#define PERSONA_H
#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;
public:
    Persona(std::string nombre, int edad);
    virtual ~Persona() = default;

    std::string getNombre() const;
    int getEdad() const;
};

#endif