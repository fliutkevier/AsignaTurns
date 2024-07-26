#include "Paciente.h"
#include "PacienteArchivo.h"
#include <iostream>

bool Paciente::setDni(int dni)
{
    if (dni > 0)
    {
        _dni = dni;
        return true;
    }
    std::cout << "DNI INVALIDO." << std::endl;
    return false;
}

bool Paciente::setCobertura(int cobertura)
{
    if (cobertura > 0 && cobertura < 6)
    {
        _cobertura = cobertura;
        return true;
    }
    std::cout << "COBERTURA INVALIDA." << std::endl;
    return false;
}

bool Paciente::cargar(bool modificando)
{
    if(!modificando)
    {
        PacienteArchivo archiPac("pacientes.dat");
        archiPac.abrir("ab");
        int dni;
        std::cout << "Ingrese el DNI del paciente: ";
        std::cin >> dni;

        if(!setDni(dni))
        {
            return false;
        }

        if(archiPac.buscarPosicionPorDni(_dni) >= 0)
        {
            std::cout << "YA EXISTE UN PACIENTE CON ESTE DNI." << std::endl;
            archiPac.cerrar();
            return false;
        }
    }


    std::cout << "Ingrese los nombres del paciente: ";
    std::cin >> _nombres;

    std::cout << "Ingrese los apellidos del paciente: ";
    std::cin >> _apellidos;

    std::cout << "Ingrese el email del paciente: ";
    std::cin >> _email;

    std::cout << "Ingrese el numero de telefono del paciente: ";
    std::cin >> _telefono;

    std::cout << "Ingrese la direccion del paciente: ";
    std::cin >> _direccion;

    std::cout << "Ingrese la fecha de nacimiento del paciente: ";
    if(!_fechaDeNacimiento.Cargar(false))
    {
        return false;
    }

    int cobertura;
    std::cout << std::endl;
    std::cout << "Numeros de coberturas: "<<std::endl<<std::endl;
    std::cout <<"     1-OSDE"<<std::endl;
    std::cout <<"     2-Swiss Medical"<<std::endl;
    std::cout <<"     3-Omint"<<std::endl;
    std::cout <<"     4-Galeno"<<std::endl;
    std::cout <<"     5-Medicus"<<std::endl<<std::endl;
    std::cout<<"Ingrese la del paciente: ";
    std::cin >> cobertura;

    if(!setCobertura(cobertura))
    {
        return false;
    }

    _estado = true;
    return _estado;
}

void Paciente::mostrar()
{
	if (_estado)
	{
		std::cout << "DNI: " << _dni << std::endl;
		std::cout << "Nombres: " << _nombres << std::endl;
		std::cout << "Apellidos: " << _apellidos << std::endl;
		std::cout << "Email: " << _email << std::endl;
		std::cout << "Telefono: " << _telefono << std::endl;
		std::cout << "Direccion: " << _direccion << std::endl;
		std::cout << "Fecha de nacimiento: ";
		_fechaDeNacimiento.Mostrar();
		std::cout << "Numero de cobertura: " << _cobertura << std::endl;
		std::cout << "=================================" << std::endl;
        std::cout << "=================================" << std::endl;
	}
}
