#ifndef PACIENTEMANAGER_H
#define PACIENTEMANAGER_H
#include "Paciente.h"
#include "PacienteArchivo.h"

class PacienteManager
{
public:
    void menu();

    void cargarNuevoPaciente();
    void buscarPorDNI();
    void listarTodosLosPacientesRegistrados();
    void modificarDatosDelPaciente();
    void darDeBajaPaciente();
    void menuModificar(Paciente obj);
private:
    PacienteArchivo archiPac;
    Paciente objPaci;
};

#endif // PACIENTEMANAGER_H
