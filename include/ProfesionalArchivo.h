#ifndef PROFESIONALARCHIVO_H
#define PROFESIONALARCHIVO_H
#include "Profesional.h"
#include "Archivo.h"
#include <string>

class ProfesionalArchivo : public Archivo
{
public:
    ProfesionalArchivo();
    ProfesionalArchivo(std::string nombreArchivo);

    bool grabar(Profesional obj);
    int getCantidadRegistros();
    int buscarPosicionPorLegajo(int legajoBuscado);
    Profesional leerPosicion(int pos);
    bool modificar(Profesional obj, int pos);

    bool crearBkp(std::string nombre);
    bool restaurarBkp(std::string nombre);
    bool restaurarEliminados();
    bool eliminarFisica();
};

#endif // PROFESIONALARCHIVO_H
