#include "Fecha.h"
#include <iostream>
#include <ctime>

Fecha::Fecha()
{
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int d, int m, int a)
{
    _dia = d;
    _mes = m;
    _anio = a;
}

void Fecha::setDia(int dia)
{
    _dia = dia;
}
void Fecha::setMes(int mes)
{
    _mes = mes;
}
void Fecha::setAnio(int anio)
{

    _anio = anio;
}

bool Fecha::Cargar(bool futura) {

    time_t actual = time(nullptr);
    struct tm *fecha = localtime(&actual);
    int diaActual = fecha->tm_mday;
    int mesActual = fecha->tm_mon + 1;
    int anioActual = fecha->tm_year + 1900;

    std::cout << "Ingrese dia: ";
    std::cin >> _dia;
    if (_dia < 1 || _dia > 31)
    {
        std::cout << "DIA INVALIDO." << std::endl;
        return false;
    }

    std::cout << "Ingrese mes: ";
    std::cin >> _mes;
    if (_mes < 1 || _mes > 12)
    {
        std::cout << "MES INVALIDO." << std::endl;
        return false;
    }

    std::cout << "Ingrese anio: ";
    std::cin >> _anio;

    if (!futura)
    {
        if (_anio < anioActual && _anio > 1800)
        {
            return true;
        }else if(_anio == anioActual)
        {
            if (_mes < mesActual)
            {
                return true;
            }else if(_mes == mesActual)
            {
                if(_dia <= diaActual)
                {
                    return true;
                }
            }

        }


    }
    else
    {
        if (_anio > anioActual)
        {
            return true;
        }
        else if (_anio == anioActual)
        {
            if (_mes > mesActual)
            {
                return true;
            }
            else if (_mes == mesActual)
            {
                if (_dia >= diaActual)
                {
                    return true;
                }
            }
        }
    }

    std:: cout << "FECHA INVALIDA." << std::endl;
    return false;

}

void Fecha::Mostrar() {

    std::cout << _dia << "/" << _mes << "/" << _anio << std::endl;
}

bool Fecha::operator==(Fecha obj)
{
    if (obj.getDia() == _dia && obj.getMes() == _mes && obj.getAnio() == _anio)
    {
        return true;
    }
    return false;
}
