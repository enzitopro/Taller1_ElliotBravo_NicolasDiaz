#include "Hospital.h"
#include <iostream>
#include <fstream> // libreria para leer
#include <sstream>// libreria para separar
#include <string>

#include "Paciente.h"
#include "Servicio.h"
#include "../Logica/ColaPacientes.h"
using namespace std;

void Hospital::limpiarCampo(std::string &campo) {
    if (campo.empty()) return;
    char* inicio = &campo[0];
    char* fin = inicio + campo.size() - 1;

    while (fin >= inicio && (*fin == '\r' || *fin == '\n' || *fin == ' ')) {
        fin--;
    }

    long nuevaLongitud = (fin - inicio) + 1;
    campo.resize(nuevaLongitud);
}

void Hospital::lecturaPacientes() {
    ifstream archivo("../Dominio/pacientes.txt");
    if (!archivo.is_open()) {
        cout << "Error: no se encontro el archivo pacientes.txt" << endl;
        return;
    }

    string linea;
    int numeroLinea = 0;
    while (getline(archivo,linea)) {
        numeroLinea++;
        if (linea.empty()) continue;

        stringstream streamLinea(linea);
        string id, nombre, edad, servicio;

        if (!getline(streamLinea, id, ';') ||
        !getline(streamLinea, nombre, ';') ||
        !getline(streamLinea, edad, ';') ||
        !getline(streamLinea, servicio, ';')) {
            cout << "Linea " << numeroLinea << " invalida (formato incorrecto), se omite: " << linea << endl;
            continue;
        }

        limpiarCampo(id);
        limpiarCampo(nombre);
        limpiarCampo(edad);
        limpiarCampo(servicio);

        if (id.empty() || nombre.empty() || edad.empty() || servicio.empty()) {
            cout << "Linea " << numeroLinea << " invalida (campo vacio), se omite: "  << linea << endl;
            continue;
        }

        stringstream stringAInt(edad);
        int edadBueno;
        stringAInt >> edadBueno;
        if (stringAInt.fail() || !stringAInt.eof() || edadBueno < 0) {
            cout << "Linea " << numeroLinea << " invalida (edad no numerica), se omite: " << linea << endl;
            continue;
        }

        if (buscarServicio(servicio) == nullptr) {
            cout << "Linea " << numeroLinea << " invalida (servicio '" << servicio << "' no existe), se omite: " << linea << endl;
            continue;
        }

        if (buscarPaciente(id) != nullptr) {
            cout << "ID existente " << id << ". Paciente no registrado: " << nombre << endl;
            continue;
        }

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
                cout << "El servicio buscado no existe en el Hospital. Se omite este paciente" << endl;
                colaPacientes.pop();
                delete pacienteObjetivo;
                continue;
            }
            pacienteObjetivo->imprimirInfo();
            servicioADerivar->recibirPaciente(pacienteObjetivo);
            cout << "Paciente enviado a " << servicioADerivar->getNombre() << "." << endl;
            cout << "" << endl;
            colaPacientes.pop();
            historial.push(pacienteObjetivo);
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

void Hospital::mostrarHistorial() {
    historial.mostrarHistorial();

}
Paciente* Hospital::buscarPaciente(string id) {
    Paciente* pacienteObjetivo = colaPacientes.buscarPaciente(id);
    if (pacienteObjetivo != nullptr) {
        return pacienteObjetivo;
    }
    NodoServicio* nodo = inicioServicios;

    while (nodo != nullptr) {
        pacienteObjetivo= nodo->servicio->buscarPaciente(id);
        if (pacienteObjetivo != nullptr) {
            return pacienteObjetivo;
        }

        nodo = nodo->siguiente;
    }
    return nullptr;
}

void Hospital::preguntarId() {
    string idObjetivo;
    cout << "Ingrese ID a buscar" << endl;
    cout << "ID:  ";

    cin >> idObjetivo;
    Paciente* paciente = buscarPaciente(idObjetivo);

    if (paciente == nullptr) {
        cout << "Paciente no encontrado" << endl;
        return;
    }
    paciente->imprimirInfo();
}



