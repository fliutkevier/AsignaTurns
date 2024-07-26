#include "PacienteManager.h"
#include "Paciente.h"
#include "PacienteArchivo.h"
#include "TurnoManager.h"
#include <iostream>

void PacienteManager::cargarNuevoPaciente()
{
    if(objPaci.cargar(false))
    {
        if(archiPac.grabar(objPaci))
        {
            std::cout << "PACIENTE REGISTRADO CON EXITO." << std::endl;
        }
    }
}

void PacienteManager::buscarPorDNI()
{
    int dniBuscado;

    std::cout << "Ingrese el DNI del paciente que busca: " << std::endl;
    std::cin >> dniBuscado;

    int pos = archiPac.buscarPosicionPorDni(dniBuscado);
    if (pos >= 0)
    {
        objPaci = archiPac.leerPosicion(pos);
        if (objPaci.getEstado())
        {
            objPaci.mostrar();
        }
        else
        {
            std::cout << "EL PACIENTE SE ENCUENTRA DADO DE BAJA." << std::endl;
        }
    }
    else
    {
        std::cout << "EL DNI BUSCADO NO EXISTE." << std::endl;
    }

}

void PacienteManager::listarTodosLosPacientesRegistrados()
{
    int cant = archiPac.getCantidadRegistros();
    if(cant > 0)
    {
        for(int i = 0; i < cant; i++)
        {
            objPaci = archiPac.leerPosicion(i);
            objPaci.mostrar();
        }
    }
    else
    {
        std::cout << "NO HAY PACIENTES REGISTRADOS." << std::endl;
    }

}

void PacienteManager::modificarDatosDelPaciente()
{
    int dniModificar;
    std::cout << "INGRESE EL DNI DEL PACIENTE A MODIFICAR: ";
    std::cin >> dniModificar;

    system("cls");
    int pos = archiPac.buscarPosicionPorDni(dniModificar);
    if(pos >= 0)
    {
        objPaci = archiPac.leerPosicion(pos);
        if (objPaci.getEstado())
        {
            menuModificar(objPaci);
        }
        else
        {
            std::cout << "EL PACIENTE SE ENCUENTRA DADO DE BAJA.";
        }
    }
    else
    {
        std::cout << "EL PACIENTE CON ESTE DNI NO EXISTE." << std::endl;
        system("pause");
    }
}

void PacienteManager::darDeBajaPaciente()
{
    int dniBuscado;

    std::cout << "INGRESE EL DNI DEL PACIENTE QUE DESEA ELIMINAR: " << std::endl;
    std::cin >> dniBuscado;
    int pos = archiPac.buscarPosicionPorDni(dniBuscado);
    if (pos != -1)
    {
        objPaci = archiPac.leerPosicion(pos);
        objPaci.setEstado(false);
        if(archiPac.modificar(objPaci, pos))
        {
            std::cout << "PACIENTE DADO DE BAJA." << std::endl;
        }
        else
        {
            std::cout << "NO SE PUDO DAR DE BAJA AL PACIENTE." << std::endl;
        }
    }
    else
    {
        std::cout << "EL PACIENTE CON ESTE DNI NO EXISTE." << std::endl;
    }
}

void PacienteManager::menu()
{
    bool banderaMenuModificar;
    int opc;
    TurnoManager turnoMan;
    while(true)
    {
        banderaMenuModificar = false;
        system("cls");
        std::cout << "====================MENU DE PACIENTES====================" << std::endl;
        std::cout << std::endl;
        std::cout << "                 1- CARGAR NUEVO PACIENTE" << std::endl;
        std::cout << "                    2- BUSCAR POR DNI" << std::endl;
        std::cout << "          3- LISTAR TODOS LOS PACIENTES REGISTRADOS" << std::endl;
        std::cout << "             4- MENU PARA MODIFICAR AL PACIENTE" << std::endl;
        std::cout << "                5- DAR DE BAJA PACIENTE" << std::endl;
        std::cout << std::endl;
        std::cout << "                       0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            cargarNuevoPaciente();
            break;
        case 2:
            buscarPorDNI();
            break;
        case 3:
            listarTodosLosPacientesRegistrados();
            break;
        case 4:
            banderaMenuModificar = true;
            modificarDatosDelPaciente();
            break;
        case 5:
            darDeBajaPaciente();
            break;
        case 0:
            return;
            break;
        default:
            std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
            system("pause");
            break;
        }
        if(!banderaMenuModificar)
        {
            system("pause");
        }
    }
}

void PacienteManager::menuModificar(Paciente obj)
{
    int opc;
    int pos = archiPac.buscarPosicionPorDni(obj.getDni());
    char nuevoValor[30];
    int nuevoValorEntero;
    Fecha nuevaFecha;
    int dni;
    while(true)
    {
        system("cls");
        std::cout << "=============MENU MODIFICACION DEL PACIENTE DNI " << obj.getDni() << "=============" << std::endl;
        std::cout << std::endl;
        std::cout << "                     1- MODIFICACION COMPLETA (MENOS DNI)" << std::endl;
        std::cout << "                      2- MODIFICAR NOMBRE/S" << std::endl;
        std::cout << "                     3- MODIFICAR APELLIDO/S" << std::endl;
        std::cout << "                       4- MODIFICAR DNI" << std::endl;
        std::cout << "                      5- MODIFICAR EMAIL" << std::endl;
        std::cout << "                     6- MODIFICAR TELEFONO" << std::endl;
        std::cout << "                     7- MODIFICAR DIRECCION" << std::endl;
        std::cout << "                 8- MODIFICAR FECHA DE NACIMIENTO" << std::endl;
        std::cout << "               9- MODIFICAR NUMERO DE COBERTURA" << std::endl;
        std::cout << std::endl;
        std::cout << "                        0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            std::cout << "---INGRESE LOS NUEVOS DATOS DEL PACIENTE---" << std::endl;
            dni = obj.getDni();
            if(obj.cargar(true))
            {
                obj.setDni(dni);
                if(archiPac.modificar(obj, pos))
                {
                    std::cout << "PACIENTE MODIFICADO" << std::endl;
                }
                else
                {
                    std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;

                }
            }
            break;
        case 2:
            std::cout << "INGRESE EL/LOS NUEVO/S NOMBRE/S: " << std::endl;
            std::cin >> nuevoValor;
            obj.setNombres(nuevoValor);

            if(archiPac.modificar(obj, pos))
            {
                std::cout << "NOMBRE/S MODIFICADO/S." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 3:
            std::cout << "INGRESE EL/LOS NUEVO/S APELLIDO/S: " << std::endl;
            std::cin >> nuevoValor;
            obj.setApellidos(nuevoValor);

            if(archiPac.modificar(obj, pos))
            {
                std::cout << "APELLIDO/S MODIFICADO/S." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 4:
            std::cout << "INGRESE EL NUEVO DNI: " << std::endl;
            std::cin >> nuevoValorEntero;
            obj.setDni(nuevoValorEntero);

            if(archiPac.modificar(obj, pos))
            {
                std::cout << "DNI MODIFICADO." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 5:
            std::cout << "INGRESE EL NUEVO EMAIL: " << std::endl;
            std::cin >> nuevoValor;
            obj.setEmail(nuevoValor);

            if(archiPac.modificar(obj, pos))
            {
                std::cout << "EMAIL MODIFICADO." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 6:
            std::cout << "INGRESE EL NUEVO TELEFONO: " << std::endl;
            std::cin >> nuevoValor;
            obj.setTelefono(nuevoValor);

            if(archiPac.modificar(obj, pos))
            {
                std::cout << "TELEFONO MODIFICADO." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 7:
            std::cout << "INGRESE LA NUEVA DIRECCION: " << std::endl;
            std::cin >> nuevoValor;
            obj.setDireccion(nuevoValor);
            if(archiPac.modificar(obj, pos))
            {
                std::cout << "DIRECCION MODIFICADA." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 8:
            std::cout << "INGRESE LA NUEVA FECHA DE NACIMIENTO: " << std::endl;
            nuevaFecha.Cargar(false);
            obj.setFechaDeNacimiento(nuevaFecha);
            if(archiPac.modificar(obj, pos))
            {
                std::cout << "FECHA DE NACIMIENTO MODIFICADA." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 9:
            std::cout << "INGRESE EL NUEVO NUMERO DE COBERTURA: " << std::endl;
            std::cin >> nuevoValorEntero;
            obj.setCobertura(nuevoValorEntero);
            if(archiPac.modificar(obj, pos))
            {
                std::cout << "NUMERO DE COBERTURA MODIFICADO." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
        case 0:
            return;
            break;
        default:
            std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
            system("pause");
        }
        system("pause");

    }
}

