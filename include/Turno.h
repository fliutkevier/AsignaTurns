#ifndef TURNO_H
#define TURNO_H
#include "Fecha.h"

class Turno
{
public:
    bool cargar();
    void mostrar(bool mostrarDni);
    void mostrarPaciente();

    void setDniPaciente(int dni) { _dniDelPaciente = dni; }
    bool setLegajo(int legajo);
    void setFecha(Fecha fecha) { _fechaTurno = fecha; }
    void setId(int id) { _id = id; }
    void setEstado(bool e) { _estado = e; }

    int getId() { return _id; }
    int getDniPaciente() { return _dniDelPaciente; }
    int getLegajo() { return _legajoDelProfesionalAsignado; }
    Fecha getFecha() { return _fechaTurno; }
    bool getEstado() { return _estado; }
private:
    int _id;
    int _dniDelPaciente;
    int _legajoDelProfesionalAsignado;
    Fecha _fechaTurno;
    bool _estado;
};

#endif // TURNO_H
