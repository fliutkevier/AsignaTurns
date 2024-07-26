#include "RecepcionistaManager.h"
#include "PacienteManager.h"
#include "ProfesionalManager.h"
#include "TurnoManager.h"
#include "AjusteManager.h"
#include <iostream>

void RecepcionistaManager::menu()
{
    int opc;
    PacienteManager pacMan;
    ProfesionalManager proMan;
    TurnoManager turMan;
    AjusteManager ajuMan;
    while(true)
    {
        system("cls");
        std::cout << "====================MENU DE RECEPCIONISTA====================" << std::endl;
        std::cout << std::endl;
        std::cout << "                       1- PACIENTES" << std::endl;
        std::cout << "                     2- PROFESIONALES" << std::endl;
        std::cout << "                        3- TURNOS" << std::endl;
        std::cout << "                       4- AJUSTES" << std::endl;
        std::cout << std::endl;
        std::cout << "                0- VOLVER AL MENU PRINCIPAL" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;
        system("cls");

        switch (opc)
        {
        case 1:
            pacMan.menu();
            break;
        case 2:
            proMan.menu();
            break;
        case 3:
            turMan.menu();
            break;
        case 4:
            ajuMan.menu();
            break;
        case 0:
            return;
        default:
            std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
            system("pause");
            break;
        }

    }
}
