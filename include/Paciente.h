#ifndef PACIENTE_H
#define PACIENTE_H
#include "Persona.h"
#include "Fecha.h"

class Paciente : public Persona
{
public:
    bool setDni(int dni);
	void setFechaDeNacimiento(Fecha fecha) { _fechaDeNacimiento = fecha; }
	bool setCobertura(int cobertura);


	int getDni() { return _dni; }
	Fecha getFechaDeNacimiento() { return _fechaDeNacimiento; }
	int getCobertura() { return _cobertura; }

	bool cargar(bool modificando);
	void mostrar();

private:
    int _dni;
	Fecha _fechaDeNacimiento;
	int _cobertura;
};

#endif // PACIENTE_H
