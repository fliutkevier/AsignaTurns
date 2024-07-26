#ifndef PACIENTEARCHIVO_H
#define PACIENTEARCHIVO_H
#include "Paciente.h"
#include "Archivo.h"

class PacienteArchivo : public Archivo
{
public:
    PacienteArchivo();
    PacienteArchivo(std::string nombreArchivo);

	bool grabar(Paciente obj);
	int getCantidadRegistros();
	int buscarPosicionPorDni(int dniBuscado);
	Paciente leerPosicion(int pos);
	bool modificar(Paciente obj, int pos);

	bool crearBkp(std::string nombre);
	bool restaurarBkp(std::string nombre);
	bool restaurarEliminados();
	bool eliminarFisica();
};

#endif // PACIENTEARCHIVO_H
