#include "Turno.h"
#include "ProfesionalArchivo.h"
#include "PacienteArchivo.h"
#include "Paciente.h"
#include <iostream>

bool Turno::setLegajo(int legajo)
{
    if (legajo >= 0)
    {
        _legajoDelProfesionalAsignado = legajo;
        return true;
    }
    std::cout << "LEGAJO INVALIDO." << std::endl;
    return false;
}

bool Turno::cargar()
{
    std::cout << "Ingrese el DNI del paciente: ";
    std::cin >> _dniDelPaciente;
    if (_dniDelPaciente <= 0)
    {
        std::cout << "DNI INVALIDO." << std::endl;
        return false;
    }

    PacienteArchivo archiPac("pacientes.dat");
    if (archiPac.buscarPosicionPorDni(_dniDelPaciente) == -1)
    {
        std::cout << "EL DNI INGRESADO NO EXISTE." << std::endl;
        return false;
    }

    int legajo;
    std::cout << "Ingrese el legajo del profesional asignado al paciente DNI " << _dniDelPaciente << ": ";
    std::cin >> legajo;

    if(!setLegajo(legajo))
    {
        return false;
    }

    ProfesionalArchivo archiPro("profesionales.dat");
    if (archiPro.buscarPosicionPorLegajo(legajo) == -1)
    {
        std::cout << "EL PROFESIONAL INGRESADO NO EXISTE." << std::endl;
        return false;
    }

    std::cout << "Ingrese la fecha del turno: ";
    if(_fechaTurno.Cargar(true))
    {
        _estado = true;
        return true;
    }
    else
    {
        return false;
    }

}

void Turno::mostrar(bool mostrarDni)
{
    if (_estado)
    {
        std::cout << "ID: " << _id << std::endl;
        if (mostrarDni)
        {
            std::cout << "DNI del paciente: " << _dniDelPaciente << std::endl;
        }
        std::cout << "Legajo del profesional asignado: " << _legajoDelProfesionalAsignado << std::endl;
        std::cout << "Fecha del turno: ";
        _fechaTurno.Mostrar();
        std::cout << "=================================" << std::endl;
        std::cout << "=================================" << std::endl;
    }
}

void Turno::mostrarPaciente()
{
    if (_estado)
    {
        PacienteArchivo archiPac;

        int pos = archiPac.buscarPosicionPorDni(_dniDelPaciente);
        Paciente objPac = archiPac.leerPosicion(pos);

        std::cout << "ID: " << _id << std::endl;
        std::cout << "DNI del paciente: " << _dniDelPaciente << std::endl;
        std::cout << "Nombre del paciente: " << objPac.getNombres() << std::endl;
        std::cout << "Apellido del paciente: " << objPac.getApellidos() << std::endl;
        std::cout << "Fecha del turno: ";
        _fechaTurno.Mostrar();
        std::cout << "=================================" << std::endl;
        std::cout << "=================================" << std::endl;
    }
}
