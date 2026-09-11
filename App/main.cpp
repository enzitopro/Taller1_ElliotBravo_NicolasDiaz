#include <iostream>
#include "../Dominio/hospital.h"
using namespace std;

int main() {

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
                break;
            case 2:
                break;
            case 3:
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