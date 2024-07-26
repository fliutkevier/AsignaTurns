#include "Archivo.h"
#include <iostream>

bool Archivo::abrir(const char* modo)
{
    _archivo = fopen(_nombreArchivo.c_str(), modo);
    if(_archivo == nullptr)
    {
        return false;
    }

    return true;
}

bool Archivo::reset()
{
    if(!abrir("wb"))
    {
        return false;
    }

    return true;
    cerrar();
}

void Archivo::cerrar()
{
	fclose(_archivo);
}


