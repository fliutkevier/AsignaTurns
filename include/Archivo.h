#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <string>

class Archivo
{
protected:
    std::string _nombreArchivo;
    FILE* _archivo;


public:
    bool abrir(const char* modo);
    bool reset();
    void cerrar();
};

#endif // ARCHIVO_H
