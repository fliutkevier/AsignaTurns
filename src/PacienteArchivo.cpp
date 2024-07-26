#include "PacienteArchivo.h"
#include "Paciente.h"
#include <iostream>

PacienteArchivo::PacienteArchivo()
{
    _nombreArchivo = "pacientes.dat";
}

PacienteArchivo::PacienteArchivo(std::string nombreArchivo)
{
	_nombreArchivo = nombreArchivo;
}

bool PacienteArchivo::grabar(Paciente obj)
{
	if (!abrir("ab"))
	{
	    std::cout << "ERROR EN EL ARCHIVO" << std::endl;
	    return false;
	}

	fwrite(&obj, sizeof(Paciente), 1, _archivo);
	cerrar();
    return true;
}

int PacienteArchivo::getCantidadRegistros()
{
	if (!abrir("rb"))
	{
	    return -1;
	}

	fseek(_archivo, 0, SEEK_END);
	int tam = ftell(_archivo);

	cerrar();

	return tam / sizeof(Paciente);
}

Paciente PacienteArchivo::leerPosicion(int pos)
{
	Paciente obj;
	if (!abrir("rb"))
	{
		return obj;
	}

	fseek(_archivo, pos * sizeof(Paciente), SEEK_SET);
    fread(&obj, sizeof(Paciente), 1, _archivo);

	cerrar();
	return obj;

}

int PacienteArchivo::buscarPosicionPorDni(int dniBuscado)
{
    Paciente obj;
    int cant = getCantidadRegistros();

    for(int i = 0; i < cant; i++)
    {
        obj = leerPosicion(i);
        if (obj.getDni() == dniBuscado)
        {
            return i;
        }
    }
    return -1;
}

bool PacienteArchivo::modificar(Paciente obj, int pos)
{
    if(!abrir("rb+"))
    {
        std::cout << "NO HAY DATOS CARGADOS." << std::endl;
        return false;
    }

    fseek(_archivo, pos * sizeof(Paciente), SEEK_SET);
    int modificado = fwrite(&obj, sizeof(Paciente), 1, _archivo);
    cerrar();

    if(modificado > 0)
    {
        return true;
    }
    else
    {
        return false;
    }


}

bool PacienteArchivo::crearBkp(std::string nombre)
{
    Paciente obj;
    bool grabado = false;

    PacienteArchivo archiBkp(nombre);

    int cant = getCantidadRegistros();
    for(int i = 0; i < cant; i++)
    {
        obj = leerPosicion(i);
        grabado = archiBkp.grabar(obj);
    }

    return grabado;
}

bool PacienteArchivo::restaurarBkp(std::string nombre)
{
    if (!abrir("wb"))
    {
        return false;
    }
    Paciente obj;

    PacienteArchivo archiBkp(nombre);
    int grabado = 0;

    int cant = archiBkp.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        obj = archiBkp.leerPosicion(i);
        grabado = fwrite(&obj, sizeof(Paciente), 1, _archivo);
    }

    cerrar();

    if(grabado > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool PacienteArchivo::restaurarEliminados()
{
    int cant = getCantidadRegistros();

    Paciente obj;

    for(int i = 0; i < cant; i++)
    {
        obj = leerPosicion(i);
        if (!obj.getEstado())
        {
            obj.setEstado(true);
            modificar(obj, i);
        }
    }

    return true;
}

bool PacienteArchivo::eliminarFisica()
{
    crearBkp("pacientes.bkp");

    if (!abrir("wb"))
    {
        return false;
    }

    Paciente obj;

    PacienteArchivo archiBkp("pacientes.bkp");
    int grabado = 0;

    int cant = archiBkp.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        obj = archiBkp.leerPosicion(i);
        if (obj.getEstado())
        {
            grabado = fwrite(&obj, sizeof(Paciente), 1, _archivo);
        }
    }

    cerrar();

    if(grabado > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
