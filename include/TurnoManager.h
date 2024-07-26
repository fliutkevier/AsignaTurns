#ifndef TURNOMANAGER_H
#define TURNOMANAGER_H
#include "Turno.h"
#include "TurnoArchivo.h"
#include "PacienteArchivo.h"
#include "ProfesionalArchivo.h"

class TurnoManager
{
public:
    void menu();

    void agregarTurnoParaPaciente();
    void modificarTurno();
    void cancelarTurno();
    void eliminarTurno();
    void listarTodosLosTurnos();
    void buscarTurnoId();
    void listarTurnosDisponibles();
    void agregarTurnosDisponibles();

private:
    TurnoArchivo archiTur;
    Turno objTur;
    PacienteArchivo archiPac;
    ProfesionalArchivo archiPro;

};

#endif // TURNOMANAGER_H
