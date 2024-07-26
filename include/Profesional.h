#ifndef PROFESIONAL_H
#define PROFESIONAL_H
#include "Persona.h"

class Profesional : public Persona
{
public:
	bool setEspecialidad(int especialidad);
	bool setLegajo(int legajo);

	int getEspecialidad() { return _especialidad; }
	int getLegajo() { return _legajo; }

	bool cargar(bool modificando);
	void mostrar(bool turno);

private:
	int _especialidad;
	int _legajo;
};

#endif // PROFESIONAL_H
