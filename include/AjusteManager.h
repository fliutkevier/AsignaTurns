#ifndef AJUSTEMANAGER_H
#define AJUSTEMANAGER_H
#include "PacienteArchivo.h"
#include "ProfesionalArchivo.h"
#include "TurnoArchivo.h"
#include "Turno.h"
#include "Paciente.h"
#include "Profesional.h"

class AjusteManager
{
public:
    void validacionGrabados(bool* v);
    bool validacionSN();
    void menu();

    void crearBackUp();
    void restaurar();
    void bajaFisicaParaLogicos();

private:
    PacienteArchivo archiPac;

    ProfesionalArchivo archiPro;

    TurnoArchivo archiTur;
};

#endif // AJUSTEMANAGER_H
