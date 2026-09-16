#include "Hospital.h"
#include <iostream>
#include <fstream> // libreria para leer
#include <sstream>// libreria para separar
#include <string>

#include "Paciente.h"
#include "Servicio.h"
#include "../Logica/ColaPacientes.h"
using namespace std;

void Hospital::lecturaPacientes() {

    ifstream archivo("../Dominio/pacientes.txt");
    if (!archivo.is_open()) {
        cout << "no encontrado" << endl;
        return;
    }

    string linea;
    while (getline(archivo,linea)) {
        // libreria sstream para separar 
        stringstream streamLinea(linea);

        string id;
        string nombre;
        string edad;
        string servicio;

        getline(streamLinea, id, ';');
        getline(streamLinea, nombre, ';');
        getline(streamLinea, edad, ';');
        getline(streamLinea, servicio,';');

        int edadBueno;

        //para leer el texto
        stringstream stringAInt(edad);

        //guardamos el entero en edadBueno
        stringAInt >> edadBueno;

        Paciente* p = new Paciente(id,nombre,edadBueno,servicio);
        colaPacientes.push(p);


    }
    archivo.close();
}

void Hospital::mostrarPacientes() {
    colaPacientes.mostrarPacientes();
}

void Hospital::atenderPacientes(int cantidad) {
    cout << "=== ATENDIENDO PACIENTES ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        Paciente * pacienteObjetivo = colaPacientes.front();
        if (pacienteObjetivo == nullptr) {
            cout << "No quedan pacientes por atender" << endl;
            break;
        } else {
            string servicioObjetivo = pacienteObjetivo->getServicioDestino();
            Servicio* servicioADerivar = buscarServicio(servicioObjetivo);
            if (servicioADerivar == nullptr) {
                cout << "El servicio buscado no existe en el Hospital" << endl;
                break;
            }
            pacienteObjetivo->imprimirInfo();
            servicioADerivar->recibirPaciente(pacienteObjetivo);
            cout << "Paciente enviado a " << servicioADerivar->getNombre() << "." << endl;
            cout << "" << endl;
            colaPacientes.pop();
        }
    }
}

Servicio* Hospital::buscarServicio(string nombreBuscado) {
    NodoServicio* cursor = inicioServicios;
    while (cursor != nullptr) {
        if (cursor->servicio->getNombre() == nombreBuscado) {
            return cursor->servicio;
        } else {
            cursor = cursor->siguiente;
        }
    }
    return nullptr;
}

void Hospital::agregarServicio(std::string nombre) {
    Servicio* nuevoServicio = new Servicio(nombre);
    NodoServicio* servicio = new NodoServicio(nuevoServicio);
    servicio->siguiente = inicioServicios;
    inicioServicios = servicio;
}

void Hospital::verDepartamento() {
    cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    string nombresOpciones[] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };
    int opcion;
    cout << "1. Urgencias" << endl
        << "2. Medicina General" << endl
        << "3. Cardiologia" << endl
        << "4. Neurologia" << endl
        << "5. Traumatologia" << endl
        << "6. Cirugia" << endl
        << "7. Pediatria" << endl
        << "8. Hospitalizacion" << endl
        << "Seleccionar opcion: ";
    cin >> opcion;
    if (1 <= opcion && opcion <= 8) {
        Servicio* s = buscarServicio(nombresOpciones[opcion-1]);
        if (s != nullptr) {
            s->mostrarEstado();
    } else {
        cout << "Opcion inválida" << endl;
        }
    }
}

Hospital::Hospital() {
    inicioServicios = nullptr;
    string nombres[] = {
        "Urgencias", "Cardiologia", "Cirugia", "Pediatria", "Traumatologia", "Neurologia", "Medicina General", "Hospitalizacion"
    };
    for (int i = 0; i < 8; i++) {
        agregarServicio(nombres[i]);
    }
}

Hospital::~Hospital() {
    NodoServicio* cursor = inicioServicios;
    NodoServicio* aux = nullptr;
    while (cursor != nullptr) {
        aux = cursor;
        cursor = cursor->siguiente;
        delete aux->servicio; delete aux;
    }
}


