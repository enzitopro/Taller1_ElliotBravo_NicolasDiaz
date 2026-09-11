cmake_minimum_required(VERSION 4.3)
project(Taller1_ElliotBravo_NicolasDiaz)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller1_ElliotBravo_NicolasDiaz App/main.cpp
        Dominio/Persona.h
        Dominio/Persona.cpp
        Dominio/Paciente.cpp
        Dominio/Paciente.h
        Logica/NodoPaciente.h
        Logica/NodoServicio.h
        Dominio/Servicio.h
        Dominio/Servicio.cpp
        Logica/ListaPacientes.h
        Logica/ListaPacientes.cpp
        Dominio/Hospital.h
        Dominio/Hospital.cpp
)
