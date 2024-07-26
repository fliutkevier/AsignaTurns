#include "TurnoManager.h"
#include <iostream>

void TurnoManager::agregarTurnoParaPaciente()
{
    int cant = archiTur.getCantidadRegistros();
    if (cant == -1)
    {
        std::cout<<"NO EXISTEN TURNOS PARA ASIGNAR"<<std::endl;
        return;
    }

    int especialidad;
	std::cout << "Numero de especialidad:"<<std::endl<<std::endl;
    std::cout <<"     1-Ginecologia"<<std::endl;
    std::cout <<"     2-Clinica Medica"<<std::endl;
    std::cout <<"     3-Traumatologia"<<std::endl;
    std::cout <<"     4-Dermatologia"<<std::endl;
    std::cout <<"     5-Urologia"<<std::endl;
    std::cout <<"     6-Pediatria"<<std::endl;
    std::cout <<"     7-Gastroenterologia"<<std::endl;
    std::cout <<"     8-Cardiologia"<<std::endl;
    std::cout <<"     9-Neurologia"<<std::endl;
    std::cout <<"     10-Psiquiatria"<<std::endl<<std::endl;;
    std::cout<<"Ingrese la especialidad deseada: ";
    std::cin >> especialidad;

    system("cls");
    if (especialidad < 1 || especialidad > 10)
    {
        std::cout<<"ESPECIALIDAD INVALIDA."<<std::endl;
        return;
    }

    Profesional objPro;
    bool profesionalEncontrado = false;
    int cantPro = archiPro.getCantidadRegistros();
    if (cantPro > 0)
    {
        std::cout << " - PROFESIONALES DISPONIBLES -" << std::endl;
    }

    for (int i = 0; i < cantPro; i++)
    {
        objPro = archiPro.leerPosicion(i);
        if (objPro.getEspecialidad() == especialidad && objPro.getEstado())
        {
            profesionalEncontrado = true;
            objPro.mostrar(true);
        }
    }

    if(!profesionalEncontrado)
    {
        std::cout<<"NO HAY PROFESIONAL PARA ESTA ESPECIALIDAD."<<std::endl;
        return;
    }

    int legajo;
    std::cout << "Ingrese el legajo del profesional seleccionado: ";
    std::cin >> legajo;

    system("cls");
    std::cout << " - TURNOS DISPONIBLES DEL PROFESIONAL -" << std::endl;
    bool turnoLegajoEncontrado = false;
    for (int i = 0; i < cant; i++)
    {
        objTur = archiTur.leerPosicion(i);
        if (objTur.getDniPaciente() == 0 && objTur.getLegajo() == legajo && objTur.getEstado())
        {
            turnoLegajoEncontrado = true;
            objTur.mostrar(false);
        }
    }

    if(!turnoLegajoEncontrado)
    {
        std::cout<<"NO SE ENCONTRARON TURNOS PARA ESTE PROFESIONAL."<<std::endl;
        return;
    }

    int id;
    std::cout << "Ingrese el ID del turno deseado: ";
    std::cin >> id;

    int posTur = archiTur.buscarPosicionId(id);
    if(posTur == -1)
    {
        std::cout << "NO SE ENCONTRO AL TURNO." << std::endl;
        return;
    }



    int dni;
    std::cout << "Ingrese el DNI del paciente para asignarle el turno: ";
    std::cin >> dni;

    int pos = archiPac.buscarPosicionPorDni(dni);
    if(pos == -1)
    {
        std::cout << "NO SE ENCONTRO EL DNI DEL PACIENTE." << std::endl;
        return;
    }
    Paciente objPac;
    objPac = archiPac.leerPosicion(pos);
    if (objPac.getEstado())
    {
        objTur = archiTur.leerPosicion(posTur);
        objTur.setDniPaciente(dni);
        if(archiTur.modificar(objTur, posTur))
        {
            std::cout << "EL TURNO SE ASIGNO EXITOSAMENTE." << std::endl;
        }
        else
        {
            std::cout << "NO SE PUDO ASIGNAR EL TURNO." << std::endl;
        }
    }
}

void TurnoManager::modificarTurno()
{
    int id;
    std::cout << "Ingrese el ID del turno a modificar: ";
    std::cin >> id;
    std::cout << "=INGRESE LOS NUEVOS DATOS=" << std::endl;

    int pos = archiTur.buscarPosicionId(id);

    if(pos != -1)
    {
        objTur = archiTur.leerPosicion(pos);
        if(objTur.cargar())
        {
            objTur.setId(id);
            if(archiTur.modificar(objTur, pos))
            {
                std::cout << "TURNO MODIFICADO." << std::endl;
            }
            else
            {
                std::cout << "NO SE PUEDO MODIFICAR AL NUEVO TURNO." << std::endl;
            }
        }
        else
        {
            std::cout << "NO SE PUDO CARGAR EL TURNO MODIFICADO." << std::endl;

        }
    }
    else
    {
        std::cout << "NO EXISTE UN PACIENTE CON ESTE DNI." << std::endl;
    }
}

void TurnoManager::eliminarTurno()
{
    int id;
    Fecha fechaTurnoEliminar;
    std::cout << "Ingrese el id del turno a eliminar: ";
    std::cin >> id;

    int pos = archiTur.buscarPosicionId(id);
    objTur = archiTur.leerPosicion(pos);
    if(pos != -1)
    {
        objTur.setEstado(false);
        if(archiTur.modificar(objTur, pos))
        {
            std::cout << "TURNO ELIMINADO." << std::endl;
        }
        else
        {
            std::cout << "NO SE PUDO ELIMINAR EL TURNO." << std::endl;

        }
    }
    else
    {
        std::cout << "NO EXISTE EL TURNO CON ID " << id << "." << std::endl;
    }
}

void TurnoManager::listarTodosLosTurnos()
{
    int cant = archiTur.getCantidadRegistros();

    for (int i = 0; i < cant; i++)
    {
        objTur = archiTur.leerPosicion(i);
        objTur.mostrar(true);
    }
}

void TurnoManager::buscarTurnoId()
{
    int cant = archiTur.getCantidadRegistros();

    if (cant <= 0)
    {
        std::cout << "NO HAY TURNOS." << std::endl;
        return;
    }

    int idBuscada;
    std::cout << "Ingrese el ID del turno a buscar: ";
    std::cin >> idBuscada;

    int pos = archiTur.buscarPosicionId(idBuscada);


    if (pos >= 0)
    {
        objTur = archiTur.leerPosicion(pos);
        if (objTur.getEstado())
        {
            objTur.mostrar(true);
        }
        else
        {
            std::cout << "EL TURNO ESTA DADO DE BAJA." << std::endl;
        }
    }
    else
    {
        std::cout << "EL TURNO NO EXISTE." << std::endl;
    }
}

void TurnoManager::agregarTurnosDisponibles()
{
    int legajo;
    std::cout<<"Legajo del profesional encargado del turno: ";
    std::cin >> legajo;


    int pos = archiPro.buscarPosicionPorLegajo(legajo);

    if (pos == -1)
    {
        std::cout << "NO EXISTE PROFESIONAL CON ESTE LEGAJO." << std::endl;
        return;
    }

    Profesional objPro;
    objPro = archiPro.leerPosicion(pos);

    if (!objPro.getEstado())
    {
        std::cout << "ESTE PROFESIONAL ESTA DADO DE BAJA." << std::endl;
        return;
    }

    if(!objTur.setLegajo(legajo))
    {
        return;
    }


    Fecha objFecha;
    if(objFecha.Cargar(true))
    {
        objTur.setFecha(objFecha);
    }
    else
    {
        return;
    }

    objTur.setDniPaciente(0);
    objTur.setEstado(true);
    objTur.setId(archiTur.asignarUltimoId());

    if(archiTur.grabar(objTur))
    {
        std::cout << "TURNO DISPONIBLE CARGADO." << std::endl;
    }
    else
    {
        std::cout << "NO SE CARGO EL TURNO." << std::endl;
    }
}

void TurnoManager::listarTurnosDisponibles()
{
    int cant = archiTur.getCantidadRegistros();
    if(cant < 0)
    {
        std::cout << "NO EXISTEN TURNOS DISPONIBLES." << std::endl;
        return;
    }

    for (int i = 0; i < cant; i++)
    {
        objTur = archiTur.leerPosicion(i);
        if (objTur.getDniPaciente() == 0)
        {
            objTur.mostrar(false);
        }
    }

}

void TurnoManager::cancelarTurno()
{
    int cant = archiTur.getCantidadRegistros();

    if (cant <= 0)
    {
        std::cout << "NO HAY TURNOS." << std::endl;
        return;
    }

    int idBuscada;
    std::cout << "Ingrese el ID del turno a cancelar: ";
    std::cin >> idBuscada;

    int pos = archiTur.buscarPosicionId(idBuscada);


    if (pos >= 0)
    {
        objTur = archiTur.leerPosicion(pos);
        if (objTur.getEstado())
        {
            objTur.setDniPaciente(0);
            std::cout << "EL TURNO FUE CANCELADO CON EXITO." << std::endl;
        }
        else
        {
            std::cout << "EL TURNO ESTA DADO DE BAJA." << std::endl;
        }
    }
    else
    {
        std::cout << "EL TURNO NO EXISTE." << std::endl;
    }
}

void TurnoManager::menu()
{
    int opc;
    while(true)
    {
        system("cls");
        std::cout << "====================MENU DE TURNOS====================" << std::endl;
        std::cout << std::endl;
        std::cout << "           1- AGENDAR TURNO PARA UN PACIENTE" << std::endl;
        std::cout << "                 2- MODIFICAR TURNO" << std::endl;
        std::cout << "                 3- CANCELAR TURNO" << std::endl;
        std::cout << "                 4- ELIMINAR TURNO" << std::endl;
        std::cout << "              5- LISTAR TODOS LOS TURNOS" << std::endl;
        std::cout << "              6- BUSCAR TURNO POR ID" << std::endl;
        std::cout << "        7- LISTAR TODOS LOS TURNOS DISPONIBLES" << std::endl;
        std::cout << "            8- AGREGAR TURNOS DISPONIBLES" << std::endl;
        std::cout << std::endl;
        std::cout << "                        0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            agregarTurnoParaPaciente();
            break;
        case 2:
            modificarTurno();
            break;
        case 3:
            cancelarTurno();
            break;
        case 4:
            eliminarTurno();
            break;
        case 5:
            listarTodosLosTurnos();
            break;
        case 6:
            buscarTurnoId();
            break;
        case 7:
            listarTurnosDisponibles();
            break;
        case 8:
            agregarTurnosDisponibles();
            break;
        case 0:
            return;
            break;
        default:
            std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
            system("pause");
            break;
        }
        system("pause");
    }
}
