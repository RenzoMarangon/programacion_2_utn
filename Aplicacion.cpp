#include <iostream>
using namespace std;

#include "Aplicacion.h"
#include "MovimientoMenu.h"



void Aplicacion::Ejecutar()
{
    while(true)
    {
        cout << "*******************************" << endl;
        cout << "*********     APP     *********" << endl;
        cout << "*******************************" << endl;
        cout << "1 - Movimientos" << endl;
        cout << "2 - Creditos" << endl;
        cout << "*******************************" << endl;
        cout << "0 - Salir del programa" << endl;

        int opcion;
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                {
                    MovimientoMenu menu;
                    menu.Ejecutar();
                }
                break;
            case 0:
                return;
        }
    }
}
