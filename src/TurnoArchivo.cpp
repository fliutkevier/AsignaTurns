#include "TurnoArchivo.h"
#include <iostream>

TurnoArchivo::TurnoArchivo()
{
    _nombreArchivo = "turnos.dat";
}

TurnoArchivo::TurnoArchivo(std::string nombre)
{
    _nombreArchivo = nombre;
}

bool TurnoArchivo::grabar(Turno obj)
{
    if(!abrir("ab"))
    {
        return false;
    }

    int escrito = fwrite(&obj, sizeof(Turno), 1, _archivo);
    cerrar();

    if (escrito > 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int TurnoArchivo::getCantidadRegistros()
{
    if(!abrir("rb"))
    {
        return -1;
    }

    fseek(_archivo, 0, SEEK_END);
    int tam = ftell(_archivo);

    cerrar();
    return tam / sizeof(Turno);
}

int TurnoArchivo::buscarPosicionId(int idBuscado)
{
    int cant = getCantidadRegistros();

    for(int i = 0; i < cant; i++)
    {
        objTur = leerPosicion(i);
        if (idBuscado == objTur.getId())
        {
            return i;
        }
    }

    return -1;
}

int TurnoArchivo::buscarPosicionDni(int dniBuscado)
{
    int cant = getCantidadRegistros();

    for(int i = 0; i < cant; i++)
    {
        objTur = leerPosicion(i);
        if (dniBuscado == objTur.getDniPaciente())
        {

            return i;
        }
    }

    return -1;
}

int TurnoArchivo::asignarUltimoId()
{
    int posUltimo = getCantidadRegistros();
    if (posUltimo < 0)
    {
        return 1;
    }
    else
    {
        objTur = leerPosicion(posUltimo - 1);
        return objTur.getId() + 1;
    }
}

Turno TurnoArchivo::leerPosicion(int pos)
{
    objTur.setId(-1);

    if(!abrir("rb"))
    {
        return objTur;
    }

    fseek(_archivo, pos * sizeof(Turno), SEEK_SET);
    fread(&objTur, sizeof(Turno), 1, _archivo);
    cerrar();
    return objTur;
}

bool TurnoArchivo::modificar(Turno obj, int pos)
{
    if(!abrir("rb+"))
    {
        return false;
    }

    fseek(_archivo, pos * sizeof(Turno), SEEK_SET);
    int modificado = fwrite(&obj, sizeof(Turno), 1, _archivo);
    cerrar();

    if (modificado > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TurnoArchivo::crearBkp(std::string nombre)
{
    Turno obj;
    bool grabado = false;

    TurnoArchivo archiBkp(nombre);

    int cant = getCantidadRegistros();
    for(int i = 0; i < cant; i++)
    {
        obj = leerPosicion(i);
        grabado = archiBkp.grabar(obj);
    }

    return grabado;
}

bool TurnoArchivo::restaurarBkp(std::string nombre)
{
    if (!abrir("wb"))
    {
        return false;
    }
    Turno obj;

    TurnoArchivo archiBkp(nombre);
    int grabado = 0;

    int cant = archiBkp.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        obj = archiBkp.leerPosicion(i);
        grabado = fwrite(&obj, sizeof(Turno), 1, _archivo);
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

bool TurnoArchivo::restaurarEliminados()
{
    int cant = getCantidadRegistros();

    Turno obj;

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

bool TurnoArchivo::eliminarFisica()
{
    crearBkp("turnos.bkp");

    if (!abrir("wb"))
    {
        return false;
    }

    Turno obj;

    TurnoArchivo archiBkp("turnos.bkp");
    int grabado = 0;

    int cant = archiBkp.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        obj = archiBkp.leerPosicion(i);
        if (obj.getEstado())
        {
            grabado = fwrite(&obj, sizeof(Turno), 1, _archivo);
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
