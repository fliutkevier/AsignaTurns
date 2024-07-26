#ifndef TURNOARCHIVO_H
#define TURNOARCHIVO_H
#include "Archivo.h"
#include "Turno.h"

class TurnoArchivo : public Archivo
{
public:
    TurnoArchivo();
    TurnoArchivo(std::string nombre);
    bool grabar(Turno obj);
    int getCantidadRegistros();
    int buscarPosicionId(int idBuscado);
    int buscarPosicionDni(int dniBuscado);
    int asignarUltimoId();
    Turno leerPosicion(int pos);
    bool modificar(Turno obj, int pos);

    bool crearBkp(std::string nombre);
    bool restaurarBkp(std::string nombre);
    bool restaurarEliminados();
    bool eliminarFisica();
private:
    Turno objTur;
};

#endif // TURNOARCHIVO_H
