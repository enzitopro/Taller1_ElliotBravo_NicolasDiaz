#include <iostream>

using namespace std;

int main() {

    int opcion;
    do {
        cout << "=== HOSPITAL MARMAJA ===" << endl;
        cout << "A. Atender pacientes" << endl;
        cout << "B. Ver departamento" << endl;
        cout << "C. Revisar historial de atencion" << endl;
        cout << "D. Salir" << endl;
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