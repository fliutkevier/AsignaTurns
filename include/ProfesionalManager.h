#ifndef PROFESIONALMANAGER_H
#define PROFESIONALMANAGER_H
#include "ProfesionalArchivo.h"
#include "Profesional.h"
#include "TurnoArchivo.h"
#include "Turno.h"
#include "Fecha.h"

class ProfesionalManager
{
public:

    void menu();

    void cargarNuevoProfesional();
    void modificarProfesional();
    void menuModificar(Profesional obj);
    void darDeBajaProfesional();
    void listarProfesionales();
    void listarProfesionalesPorEspecialidad();
    void listarProfesionalPorLegajo();

    void menuParaProfesional();

    void listarTodosTurnosDeProfesional(int legajo);
    void listarTurnoDeProfesionalPorFecha(int legajo);

private:
    ProfesionalArchivo archiPro;
    Profesional objPro;
    TurnoArchivo archiTur;
    Turno objTur;
};

#endif // PROFESIONALMANAGER_H
