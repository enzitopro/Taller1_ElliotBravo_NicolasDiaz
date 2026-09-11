#include "Hospital.h"
#include <iostream>
#include <fstream>

using namespace std;

void Hospital::lecturaPacientes() {

    ifstream archivo("pacientes.txt");
    string linea;
    while (getline(archivo,linea)) {
        cout << linea << endl;
    }
}


