#include "AjusteManager.h"
#include "PacienteArchivo.h"
#include <iostream>

void AjusteManager::validacionGrabados(bool* v)
{
    if(!v[0])
    {
        std::cout << "NO SE REALIZO LA RESTAURACION DE PACIENTES." << std::endl;
        return;
    }

    if(!v[1])
    {
        std::cout << "NO SE REALIZO LA RESTAURACION DE PROFESIONALES." << std::endl;
        return;
    }

    if(!v[2])
    {
        std::cout << "NO SE REALIZO LA RESTAURACION DE TURNOS." << std::endl;
        return;
    }

    std::cout << "RESTAURACION COMPLETA REALIZADA." << std::endl;
}

bool AjusteManager::validacionSN()
{
    char opcSN;
    while (true)
    {
        std::cout << "Ingrese S/N :" << std::endl;
        std::cin >> opcSN;

        if (opcSN == 's' || opcSN == 'S')
        {
            return true;
        }
        else if (opcSN == 'n' || opcSN == 'N')
        {
            return false;
        }
        else
        {
            std::cout << "Ingrese una opcion valida..." << std::endl;
        }

    }
}

void AjusteManager::crearBackUp()
{
    bool vGrabados[3];
    int opc;
    while(true)
    {
        system("cls");
        std::cout << "==================== BACKUP ====================" << std::endl;
        std::cout << std::endl;
        std::cout << "    1- CREAR COPIA DE SEGURIDAD DE PACIENTES" << std::endl;
        std::cout << "  2- CREAR COPIA DE SEGURIDAD DE PROFESIONALES" << std::endl;
        std::cout << "      3- CREAR COPIA DE SEGURIDAD DE TURNOS" << std::endl;
        std::cout << std::endl;
        std::cout << "      4- CREAR COPIA DE SEGURIDAD DE TODOS" << std::endl;
        std::cout << std::endl;
        std::cout << "                   0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            if(archiPac.crearBkp("pacientes.bkp"))
            {
                std::cout << "COPIA REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA COPIA." << std::endl;
            }
            break;
        case 2:
            if(archiPro.crearBkp("profesionales.bkp"))
            {
                std::cout << "COPIA REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA COPIA." << std::endl;
            }
            break;
        case 3:
            if(archiTur.crearBkp("turnos.bkp"))
            {
                std::cout << "COPIA REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA COPIA." << std::endl;
            }
            break;
        case 4:
            vGrabados[0] = archiPac.crearBkp("pacientes.bkp");
            vGrabados[1] = archiPro.crearBkp("profesionales.bkp");
            vGrabados[2] = archiTur.crearBkp("turnos.bkp");

            if (vGrabados[0])
            {
                if (vGrabados[1])
                {
                    if (vGrabados[2])
                    {
                        std::cout << "COPIA COMPLETA REALIZADA." << std::endl;
                    }
                    else
                    {
                        std::cout << "NO SE REALIZO LA COPIA DE TURNOS." << std::endl;
                    }
                }
                else
                {
                    std::cout << "NO SE REALIZO LA COPIA DE PROFESIONALES." << std::endl;
                }
            }
            else
            {
                std::cout << "NO SE REALIZO LA COPIA DE PACIENTES." << std::endl;
            }

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
}

void AjusteManager::restaurar()
{
    bool vGrabados[3];
    int opc;
    while(true)
    {
        system("cls");
        std::cout << "==================== RESTAURACION ====================" << std::endl;
        std::cout << std::endl;
        std::cout << "     1- RESTAURAR COPIA DE SEGURIDAD DE PACIENTES" << std::endl;
        std::cout << "   2- RESTAURAR COPIA DE SEGURIDAD DE PROFESIONALES" << std::endl;
        std::cout << "      3- RESTAURAR COPIA DE SEGURIDAD DE TURNOS" << std::endl;
        std::cout << std::endl;
        std::cout << "      4- RESTAURAR TODAS LAS COPIAS DE SEGURIDAD" << std::endl;
        std::cout << std::endl;
        std::cout << "     5- RESTAURAR PACIENTES ELIMINADOS (LOGICA)" << std::endl;
        std::cout << "    6- RESTAURAR PROFESIONALES ELIMINADOS (LOGICA)" << std::endl;
        std::cout << "       7- RESTAURAR TURNOS ELIMINADOS (LOGICA)" << std::endl;
        std::cout << std::endl;
        std::cout << "      8- RESTAURAR TODOS LOS ELIMINADOS (LOGICA)" << std::endl;
        std::cout << std::endl;
        std::cout << "                   0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            if(archiPac.restaurarBkp("pacientes.bkp"))
            {
                std::cout << "RESTAURACION REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA RESTAURACION." << std::endl;
            }
            break;
        case 2:
            if(archiPro.restaurarBkp("profesionales.bkp"))
            {
                std::cout << "RESTAURACION REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA RESTAURACION." << std::endl;
            }
            break;
        case 3:
            if(archiTur.restaurarBkp("turnos.bkp"))
            {
                std::cout << "RESTAURACION REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA RESTAURACION." << std::endl;
            }
            break;
        case 4:


            vGrabados[0] = archiPac.restaurarBkp("pacientes.bkp");
            vGrabados[1] = archiPro.restaurarBkp("profesionales.bkp");
            vGrabados[2] = archiTur.restaurarBkp("turnos.bkp");

            validacionGrabados(vGrabados);
            break;
        case 5:
            if(archiPac.restaurarEliminados())
            {
                std::cout << "RESTAURACION REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA RESTAURACION." << std::endl;
            }
            break;
            break;
        case 6:
            if(archiPro.restaurarEliminados())
            {
                std::cout << "RESTAURACION REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA RESTAURACION." << std::endl;
            }
            break;
        case 7:
            if(archiPro.restaurarEliminados())
            {
                std::cout << "RESTAURACION REALIZADA." << std::endl;
            }
            else
            {
                std::cout << "NO SE REALIZO LA RESTAURACION." << std::endl;
            }
            break;
        case 8:
            vGrabados[0] = archiPac.restaurarEliminados();
            vGrabados[1] = archiPro.restaurarEliminados();
            vGrabados[2] = archiTur.restaurarEliminados();

            validacionGrabados(vGrabados);
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
}


void AjusteManager::bajaFisicaParaLogicos()
{
    bool vEliminados[3];
    int opc;
    bool deVuelta;
    while(true)
    {
        deVuelta = false;
        system("cls");
        std::cout << "==================== ELIMINACION ====================" << std::endl;
        std::cout << std::endl;
        std::cout << "        1- BORRAR PACIENTES DADOS DE BAJA" << std::endl;
        std::cout << "       2- BORRAR PROFESIONALES DADOS DE BAJA" << std::endl;
        std::cout << "         3- BORRAR TURNOS DADOS DE BAJA" << std::endl;
        std::cout << std::endl;
        std::cout << "      4- BORRAR TODOS QUE ESTEN DADOS DE BAJA" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            std::cout << "SEGURO QUE DESEA BORRAR LOS PACIENTES DADOS DE BAJA? ES PERMANENTE." << std::endl;
            if(validacionSN())
            {
                if(archiPac.eliminarFisica())
                {
                    std::cout << "PACIENTES DADOS DE BAJA ELIMINADOS" << std::endl;
                }
                else
                {
                    std::cout << "NO SE REALIZO LA ELIMINACION." << std::endl;
                }
            }
            break;
        case 2:
            std::cout << "SEGURO QUE DESEA BORRAR LOS PROFESIONALES DADOS DE BAJA? ES PERMANENTE." << std::endl;
            if(validacionSN())
            {
                if(archiPro.eliminarFisica())
                {
                    std::cout << "PROFESIONALES DADOS DE BAJA ELIMINADOS." << std::endl;
                }
                else
                {
                    std::cout << "NO SE REALIZO LA ELIMINACION." << std::endl;
                }
            }
            break;
        case 3:
            std::cout << "SEGURO QUE DESEA BORRAR LOS TURNOS DADOS DE BAJA? ES PERMANENTE." << std::endl;
            if(validacionSN())
            {
                if(archiTur.eliminarFisica())
                {
                    std::cout << "TURNOS DADOS DE BAJA ELIMINADOS." << std::endl;
                }
                else
                {
                    std::cout << "NO SE REALIZO LA ELIMINACION." << std::endl;
                }
            }
            break;
        case 4:
            vEliminados[0] = archiPac.eliminarFisica();
            vEliminados[1] = archiPro.eliminarFisica();
            vEliminados[2] = archiTur.eliminarFisica();

            std::cout << "SEGURO QUE DESEA BORRAR TODOS LOS ELEMENTOS DADOS DE BAJA? ES PERMANENTE." << std::endl;
            if(validacionSN())
            {
                vEliminados[0] = archiPac.eliminarFisica();
                vEliminados[1] = archiPro.eliminarFisica();
                vEliminados[2] = archiTur.eliminarFisica();
                if (!vEliminados[0])
                {
                    std::cout << "= NO SE REALIZO LA ELIMINACION DE LOS PACIENTES =" << std::endl;
                    break;
                }
                if (!vEliminados[1])
                {
                    std::cout << "= NO SE REALIZO LA ELIMINACION DE LOS PROFESIONALES =" << std::endl;
                    break;
                }
                if (!vEliminados[2])
                {
                    std::cout << "= NO SE REALIZO LA ELIMINACION DE LOS TURNOS =" << std::endl;
                    break;
                }

                std::cout << "= ELIMINACION COMPLETA REALIZADA =" << std::endl;
            }

            break;
        case 0:
            return;
            break;
        default:
            std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
            system("pause");
            break;
        }

        if (!deVuelta)
        {
            system("pause");
        }

    }
}

void AjusteManager::menu()
{
    int opc;
    while(true)
    {
        system("cls");
        std::cout << "==================== AJUSTES ====================" << std::endl;
        std::cout << std::endl;
        std::cout << "           1- CREAR COPIA DE SEGURIDAD" << std::endl;
        std::cout << "               2- RESTAURACION" << std::endl;
        std::cout << "     3- LIMPIAR REGISTROS DADOS DE BAJA (FISICA)" << std::endl;
        std::cout << std::endl;
        std::cout << "                   0- VOLVER" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;

        system("cls");
        switch (opc)
        {
        case 1:
            crearBackUp();
            break;
        case 2:
            restaurar();
            break;
        case 3:
            std::cout << "¿Esta seguro que quiere borrar permanentemente los registros dados de baja?" << std::endl;
            if (validacionSN())
            {
                bajaFisicaParaLogicos();
            }
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
}
