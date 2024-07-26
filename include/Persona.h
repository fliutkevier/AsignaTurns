#ifndef PERSONA_H
#define PERSONA_H
#include <cstring>

class Persona
{
protected:
    char _nombres[30];
    char _apellidos[30];
    char _email[30];
    char _telefono[30];
    char _direccion[30];
    bool _estado;

public:
    void setNombres(const char* nombre) { strcpy(_nombres, nombre); }
	void setApellidos(const char* apellido) { strcpy(_apellidos, apellido); }
	void setEmail(const char* email) { strcpy(_email, email); }
	void setTelefono(const char* telefono) {strcpy(_telefono,telefono);}
	void setDireccion(const char* direccion) { strcpy(_direccion, direccion); }
	void setEstado(bool estado) { _estado = estado; }

	const char* getNombres() { return _nombres; }
	const char* getApellidos() { return _apellidos; }
	const char* getEmail() { return _email; }
	const char* getTelefono() { return _telefono; }
	const char* getDireccion() { return _direccion; }
	bool getEstado() { return _estado; }
};

#endif // PERSONA_H
