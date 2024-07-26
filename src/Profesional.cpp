#include "Profesional.h"
#include "ProfesionalArchivo.h"
#include <iostream>

bool Profesional::setEspecialidad(int especialidad)
{
    if (especialidad > 0 && especialidad < 11)
    {
        _especialidad = especialidad;
        return true;
    }
    std::cout << "LEGAJO INVALIDO." << std::endl;
    return false;
}
bool Profesional::setLegajo(int legajo)
{
    if (legajo > 0)
    {
        _legajo = legajo;
        return true;
    }
    std::cout << "LEGAJO INVALIDO." << std::endl;
    return false;
}

bool Profesional::cargar(bool modificando)
{
    if(!modificando)
    {
        ProfesionalArchivo archiPro("profesionales.dat");
        archiPro.abrir("ab");
        int legajo;
        std::cout << "Ingrese el legajo del profesional: ";
        std::cin >> legajo;

        if(!setLegajo(legajo))
        {
            return false;
        }

        if(archiPro.buscarPosicionPorLegajo(_legajo) >= 0)
        {
            archiPro.cerrar();
            std::cout << "YA EXISTE UN PROFESIONAL CON ESTE LEGAJO." << std::endl;
            return false;
        }
    }

	std::cout << "Ingrese los nombres del profesional: ";
	std::cin >> _nombres;

	std::cout << "Ingrese los apellidos del profesional: ";
	std::cin >> _apellidos;

	std::cout << "Ingrese el email del profesional: ";
	std::cin >> _email;

	std::cout << "Ingrese el telefono del profesional: ";
	std::cin >> _telefono;

	std::cout << "Ingrese la direccion del profesional: ";
	std::cin >> _direccion;

	int especialidad;
	std::cout << "Numero de especialidad:"<<std::endl<<std::endl;
    std::cout <<"     1-Ginecologia"<<std::endl;
    std::cout <<"     2-Clinica Medica"<<std::endl;
    std::cout <<"     3-Traumatologia"<<std::endl;
    std::cout <<"     4-Dermatologia"<<std::endl;
    std::cout <<"     5-Urologia"<<std::endl;
    std::cout <<"     6-Pediatria"<<std::endl;
    std::cout <<"     7-Gastroenterologia"<<std::endl;
    std::cout <<"     8-Cardiologia"<<std::endl;
    std::cout <<"     9-Neurologia"<<std::endl;
    std::cout <<"     10-Psiquiatria"<<std::endl<<std::endl;;
    std::cout<<"Ingrese la especialidad del profesional: ";
    std::cin >> especialidad;

    if(!setEspecialidad(especialidad))
    {
        return false;
    }

	_estado = true;
	return _estado;
}

void Profesional::mostrar(bool turno)
{
	if (_estado)
	{
		std::cout << "Legajo: " << _legajo << std::endl;
        std::cout << "Nombres: " << _nombres << std::endl;
		std::cout << "Apellidos: " << _apellidos << std::endl;
		if(!turno)
        {
            std::cout << "Email: " << _email << std::endl;
            std::cout << "Telefono: " << _telefono << std::endl;
            std::cout << "Direccion: " << _direccion << std::endl;
            std::cout << "Especialidad: " << _especialidad << std::endl;
        }
		std::cout << "=================================" << std::endl;
        std::cout << "=================================" << std::endl;
	}

}
