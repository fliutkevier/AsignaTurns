#ifndef FECHA_H
#define FECHA_H

class Fecha
{
    private:

        int _dia;
        int _mes;
        int _anio;

    public:

        bool Cargar(bool futura);
        void Mostrar();

        Fecha();
        Fecha(int d, int m, int a);

        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);

        int getDia() { return _dia; }
        int getMes() { return _mes; }
        int getAnio() { return _anio; }

        bool operator==(Fecha obj);
};

#endif // FECHA_H
