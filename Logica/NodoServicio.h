#ifndef NODOSERVICIO_H
#define NODOSERVICIO_H
#include "Servicio.h"

struct NodoServicio {
    Servicio* servicio;
    NodoServicio* siguiente;

    NodoServicio(Servicio* s) {
        servicio = s;
        siguiente = nullptr;
    }
};

#endif