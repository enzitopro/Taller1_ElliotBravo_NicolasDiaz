#include <iostream>
#include "../Dominio/Hospital.h"
using namespace std;

int main() {
    Hospital hospital;
    hospital.lecturaPacientes();
    int opcion;
    do {
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "1. Atender pacientes" << endl;
        cout << "2. Ver departamento" << endl;
        cout << "3. Revisar historial de atencion" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccionar opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                hospital.
                break;
            case 2:
                break;
            case 3:
                hospital.mostrarPacientes();
                break;
            case 4:
                cout << "Hasta luego :D" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opcion != 4);

    return 0;
}