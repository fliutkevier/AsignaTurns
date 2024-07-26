#include "ProfesionalArchivo.h"
#include "Profesional.h"
#include <iostream>

ProfesionalArchivo::ProfesionalArchivo()
{
    _nombreArchivo = "profesionales.dat";
}

ProfesionalArchivo::ProfesionalArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool ProfesionalArchivo::grabar(Profesional obj)
{
    if (!abrir("ab"))
    {
        return false;
    }

    fwrite(&obj, sizeof(Profesional), 1, _archivo);
    cerrar();
    return true;
}

int ProfesionalArchivo::getCantidadRegistros()
{
    if(!abrir("rb"))
    {
        return -1;
    }

    fseek(_archivo, 0, SEEK_END);
    int tam = ftell(_archivo);

    cerrar();

    return tam / sizeof(Profesional);
}

Profesional ProfesionalArchivo::leerPosicion(int pos)
{
    Profesional objPro;
    if(!abrir("rb"))
    {
        return objPro;
    }

    fseek(_archivo, pos * sizeof(Profesional), SEEK_SET);
    fread(&objPro, sizeof(Profesional), 1, _archivo);

    cerrar();
    return objPro;
}

int ProfesionalArchivo::buscarPosicionPorLegajo(int legajoBuscado)
{
    Profesional objPro;
    int cant = getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        objPro = leerPosicion(i);
        if (objPro.getLegajo() == legajoBuscado)
        {
            return i;
        }
    }

    return -1;
}

bool ProfesionalArchivo::modificar(Profesional obj, int pos)
{
    if(!abrir("rb+"))
    {
        return false;
    }

    fseek(_archivo, pos * sizeof(Profesional), SEEK_SET);
    int registro = fwrite(&obj, sizeof(Profesional), 1, _archivo);
    cerrar();

    if(registro > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ProfesionalArchivo::crearBkp(std::string nombre)
{
    Profesional obj;
    bool grabado = false;

    ProfesionalArchivo archiBkp(nombre);

    int cant = getCantidadRegistros();
    for(int i = 0; i < cant; i++)
    {
        obj = leerPosicion(i);
        grabado = archiBkp.grabar(obj);
    }

    return grabado;
}

bool ProfesionalArchivo::restaurarBkp(std::string nombre)
{
    if (!abrir("wb"))
    {
        return false;
    }
    Profesional obj;

    ProfesionalArchivo archiBkp(nombre);
    int grabado = 0;

    int cant = archiBkp.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        obj = archiBkp.leerPosicion(i);
        grabado = fwrite(&obj, sizeof(Profesional), 1, _archivo);
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

bool ProfesionalArchivo::restaurarEliminados()
{
    int cant = getCantidadRegistros();

    Profesional obj;

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

bool ProfesionalArchivo::eliminarFisica()
{
    crearBkp("profesionales.bkp");

    if (!abrir("wb"))
    {
        return false;
    }

    Profesional obj;

    ProfesionalArchivo archiBkp("profesionales.bkp");
    int grabado = 0;

    int cant = archiBkp.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        obj = archiBkp.leerPosicion(i);
        if (obj.getEstado())
        {
            grabado = fwrite(&obj, sizeof(Profesional), 1, _archivo);
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
