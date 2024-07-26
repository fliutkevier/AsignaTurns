#include "ProfesionalManager.h"
#include "ProfesionalArchivo.h"
#include "Profesional.h"
#include <iostream>

void ProfesionalManager::cargarNuevoProfesional()
{
    if(objPro.cargar(false))
    {
        if(archiPro.grabar(objPro))
        {
            std::cout << "PROFESIONAL REGISTRADO CON EXITO." << std::endl;
        }
    }
}

void ProfesionalManager::modificarProfesional()
{
    int legajo;
    std::cout << "INGRESE EL LEGAJO DEL PROFESIONAL A MODIFICAR: ";
    std::cin >> legajo;

    system("cls");

    int pos = archiPro.buscarPosicionPorLegajo(legajo);
    if(pos >= 0)
    {
        objPro = archiPro.leerPosicion(pos);
        if (objPro.getEstado())
        {
            menuModificar(objPro);
        }
        else
        {
            std::cout << "EL PROFESIONAL SE ENCUENTRA DADO DE BAJA.";
        }
    }
    else
    {
        std::cout << "EL PROFESIONAL CON ESTE LEGAJO NO EXISTE." << std::endl;
    }
}

void ProfesionalManager::darDeBajaProfesional()
{
    int legajo;

    std::cout << "INGRESE EL LEGAJO DEL PROFESIONAL QUE DESEA ELIMINAR: " << std::endl;
    std::cin >> legajo;
    int pos = archiPro.buscarPosicionPorLegajo(legajo);
    objPro = archiPro.leerPosicion(pos);
    objPro.setEstado(false);
    if(archiPro.modificar(objPro, pos))
    {
        std::cout << "PROFESIONAL DADO DE BAJA." << std::endl;
    }
}

void ProfesionalManager::listarProfesionales()
{
    int cant = archiPro.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        objPro = archiPro.leerPosicion(i);
        objPro.mostrar(false);
    }
}

void ProfesionalManager::listarProfesionalesPorEspecialidad()
{

    int especialidad;

    std::cout << "     == ESPECIALIDADES =="<<std::endl<<std::endl;
    std::cout <<"        1-Ginecologia"<<std::endl;
    std::cout <<"        2-Clinica Medica"<<std::endl;
    std::cout <<"        3-Traumatologia"<<std::endl;
    std::cout <<"        4-Dermatologia"<<std::endl;
    std::cout <<"        5-Urologia"<<std::endl;
    std::cout <<"        6-Pediatria"<<std::endl;
    std::cout <<"        7-Gastroenterologia"<<std::endl;
    std::cout <<"        8-Cardiologia"<<std::endl;
    std::cout <<"        9-Neurologia"<<std::endl;
    std::cout <<"        10-Psiquiatria"<<std::endl<<std::endl;;

    std::cout << "INGRESE LA ESPECIALIDAD POR LA QUE DESEA FILTRAR: ";
    std::cin >> especialidad;

    system("cls");

    std::cout << " == ESPECIALIDAD NUMERO " << especialidad << "==" << std::endl << std::endl;

    if (especialidad > 0 && especialidad < 11)
    {
        int cant = archiPro.getCantidadRegistros();
        for (int i = 0; i < cant; i++)
        {
            objPro = archiPro.leerPosicion(i);
            if (objPro.getEspecialidad() == especialidad)
            {
                objPro.mostrar(false);
            }
        }
    }
    else
    {
        std::cout << "ESPECIALIDAD INGRESADA INVALIDA" << std::endl;
    }
}

void ProfesionalManager::listarProfesionalPorLegajo()
{
    int legajo;
    std::cout << "INGRESE EL LEGAJO QUE DESEA BUSCAR: ";
    std::cin >> legajo;

    int pos = archiPro.buscarPosicionPorLegajo(legajo);

    if (pos >= 0)
    {
        objPro = archiPro.leerPosicion(pos);
        if (objPro.getEstado())
        {
            objPro.mostrar(false);
        }
        else
        {
            std::cout << "EL PROFESIONAL SE ENCUENTRA DADO DE BAJA." << std::endl;
        }
    }
    else
    {
        std::cout << "EL LEGAJO BUSCADO NO EXISTE." << std::endl;
    }
}

void ProfesionalManager::menu()
{
    int opc;
    bool deVuelta;
    while(true)
    {
        deVuelta = false;
        system("cls");
        std::cout << "====================MENU DE PROFESIONALES====================" << std::endl;
        std::cout << std::endl;
        std::cout << "                   1- AGREGAR PROFESIONAL" << std::endl;
        std::cout << "              2- BUSCAR PROFESIONAL POR LEGAJO" << std::endl;
        std::cout << "                  3- LISTAR PROFESIONALES" << std::endl;
        std::cout << "         4- LISTAR PROFESIONALES FILTRO ESPECIALIDAD" << std::endl;
        std::cout << "                  5- MODIFICAR PROFESIONAL" << std::endl;
        std::cout << "                 6- DAR DE BAJA PROFESIONAL" << std::endl;
        std::cout << std::endl;
        std::cout << "                        0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            cargarNuevoProfesional();
            break;
        case 2:
            listarProfesionalPorLegajo();
            break;
        case 3:
            listarProfesionales();
            break;
        case 4:
            listarProfesionalesPorEspecialidad();
            break;
        case 5:
            deVuelta = true;
            modificarProfesional();
            break;
        case 6:
            darDeBajaProfesional();
            break;
        case 0:
            return;
            break;
        default:
            std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
            system("pause");
        }
        //no frena el menu de modificar.
        if(!deVuelta)
        {
            system("pause");
        }

    }
}

void ProfesionalManager::menuModificar(Profesional obj)
{
    int opc;
    int pos = archiPro.buscarPosicionPorLegajo(obj.getLegajo());
    char nuevoValor[30];
    int nuevoValorEntero;
    int legajo;
    while(true)
    {
        system("cls");
        std::cout << "=============MENU MODIFICACION DEL PROFESIONAL LEGAJO " << obj.getLegajo() << "=============" << std::endl;
        std::cout << std::endl;
        std::cout << "                 1- MODIFICACION COMPLETA (MENOS LEGAJO)" << std::endl;
        std::cout << "                      2- MODIFICAR NOMBRE/S" << std::endl;
        std::cout << "                     3- MODIFICAR APELLIDO/S" << std::endl;
        std::cout << "                       4- MODIFICAR LEGAJO" << std::endl;
        std::cout << "                      5- MODIFICAR EMAIL" << std::endl;
        std::cout << "                     6- MODIFICAR TELEFONO" << std::endl;
        std::cout << "                     7- MODIFICAR DIRECCION" << std::endl;
        std::cout << "                   8- MODIFICAR ESPECIALIDAD" << std::endl;
        std::cout << std::endl;
        std::cout << "                        0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            std::cout << "---INGRESE LOS NUEVOS DATOS DEL PROFESIONAL---" << std::endl;
            legajo = obj.getLegajo();
            if(obj.cargar(true))
            {
                obj.setLegajo(legajo);
                if(archiPro.modificar(obj, pos))
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

            if(archiPro.modificar(obj, pos))
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

            if(archiPro.modificar(obj, pos))
            {
                std::cout << "APELLIDO/S MODIFICADO/S." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 4:
            std::cout << "INGRESE EL NUEVO LEGAJO: " << std::endl;
            std::cin >> nuevoValorEntero;
            obj.setLegajo(nuevoValorEntero);

            if(archiPro.modificar(obj, pos))
            {
                std::cout << "LEGAJO MODIFICADO." << std::endl;
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

            if(archiPro.modificar(obj, pos))
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

            if(archiPro.modificar(obj, pos))
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
            if(archiPro.modificar(obj, pos))
            {
                std::cout << "DIRECCION MODIFICADA." << std::endl;
            }
            else
            {
                std::cout << "PROBLEMA EN LA MODIFICACION." << std::endl;
            }
            break;
        case 8:
            std::cout << "INGRESE LA NUEVA ESPECIALIDAD: " << std::endl;
            std::cin >> nuevoValorEntero;
            obj.setEspecialidad(nuevoValorEntero);
            if(archiPro.modificar(obj, pos))
            {
                std::cout << "ESPECIALIDAD MODIFICADA." << std::endl;
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

void ProfesionalManager::listarTodosTurnosDeProfesional(int legajo)
{
    int cant = archiTur.getCantidadRegistros();

    objTur.setId(-1);

    for (int i = 0; i < cant; i++)
    {
        objTur = archiTur.leerPosicion(i);
        if(objTur.getLegajo() == legajo && objTur.getDniPaciente() != 0)
        {
            objTur.mostrarPaciente();
        }
    }

    if (objTur.getId() == -1)
    {
        std::cout << "NO TIENE TURNOS ASIGNADOS." << std::endl;
    }
}

void ProfesionalManager::listarTurnoDeProfesionalPorFecha(int legajo)
{
    Fecha fechaBuscada;
    std::cout << "=INGRESE LA FECHA A FILTRAR=" << std::endl;
    fechaBuscada.Cargar(true);

    int cant = archiTur.getCantidadRegistros();

    int encontrado = 0;

    for (int i = 0; i < cant; i++)
    {
        objTur = archiTur.leerPosicion(i);
        if(objTur.getLegajo() == legajo)
        {
            encontrado = 1;
            if (fechaBuscada == objTur.getFecha())
            {
                encontrado = 2;
                objTur.mostrarPaciente();
            }
        }

    }

    if(encontrado == 0)
    {
        std::cout << "NO HAY TURNOS REGISTRADOS." << std::endl;
    }
    else if(encontrado == 1)
    {
        std::cout << "NO HAY TURNOS REGISTRADOS CON ESTA FECHA." << std::endl;
    }
}

void ProfesionalManager::menuParaProfesional()
{
    int legajo;
    int opc;
        system("cls");
        std::cout << "====================MENU DE PROFESIONAL====================" << std::endl;
        std::cout << std::endl;
        std::cout << "                Ingrese su numero de legajo" << std::endl;
        std::cout << "                       0 para volver" << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "                    _________________" << std::endl;
        std::cout << "                     ";
        std::cin >> legajo;

    while(true)
    {
        if (archiPro.buscarPosicionPorLegajo(legajo) >= 0)
        {
            system("cls");
            std::cout << "====================MENU DEL PROFESIONAL " << legajo << "====================" << std::endl;
            std::cout << std::endl;
            std::cout << "                  1- LISTAR TODOS SUS TURNOS" << std::endl;
            std::cout << "                  2- LISTAR TURNOS POR FECHA" << std::endl;
            std::cout << std::endl;
            std::cout << "                  0- VOLVER AL MENU PRINCIPAL" << std::endl;
            std::cout << std::endl;

            std::cout << "Ingrese una opcion: ";
            std::cin >> opc;

            system("cls");

            switch (opc)
            {
            case 1:
                listarTodosTurnosDeProfesional(legajo);
                break;
            case 2:
                listarTurnoDeProfesionalPorFecha(legajo);
                break;
            case 0:
                return;
                break;
            default:
                std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
                system("pause");
                break;
            }
        }
        else
        {
            if (legajo == 0)
            {
                return;
            }
            std::cout << "======EL LEGAJO INGRESADO NO EXISTE.======" << std::endl;
        }
        system("pause");

    }
}
