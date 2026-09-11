#ifndef TALLER1_ELLIOTBRAVO_NICOLASDIAZ_LISTAPACIENTES_H
#define TALLER1_ELLIOTBRAVO_NICOLASDIAZ_LISTAPACIENTES_H


#include "NodoPaciente.h"

class ListaPacientes {
 private:
   NodoPaciente* inicio;

 public:
   ListaPacientes();

   ~ListaPacientes();
    //metodos
   void agregarPaciente(Paciente* p);
   void mostrarPacientes() const;

};

#endif