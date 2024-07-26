#include "AppManager.h"
#include "RecepcionistaManager.h"
#include "ProfesionalManager.h"
#include <iostream>

void AppManager::menu()
{
    int opc;
    ProfesionalManager prof;
    RecepcionistaManager recep;
    while(true)
    {
        system("cls");
        std::cout << "====================MENU PRINCIPAL====================" << std::endl;
        std::cout << std::endl;
        std::cout << "                   1- RECEPCIONISTA" << std::endl;
        std::cout << "                    2- PROFESIONAL" << std::endl;
        std::cout << std::endl;
        std::cout << "                      0- SALIR" << std::endl;
        std::cout << std::endl;

        std::cout << "Ingrese una opcion: ";
        std::cin >> opc;
        system("cls");

        switch (opc)
        {
        case 1:

            recep.menu();
            break;
        case 2:

            prof.menuParaProfesional();
            break;
        case 0:
            exit(0);
            break;
        default:
            std::cout << "INGRESE UNA OPCION VALIDA..." << std::endl;
            system("pause");
            break;
        }

    }
}
