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

        cin << opcion;
    } while (opcion != 4);
    cout << "Hasta luego :D" << endl;

    return 0;
}