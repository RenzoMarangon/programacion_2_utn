#include <iostream>
using namespace std;
#include <cstdlib>
#include <cstring>

using namespace std;


#include "FuncionesGlobales.h"
#include "Archivo.h"
#include "Persona.h"
#include "Alumno.h"




int main()
{

    Archivo archivo("alumnis.dat");

    system("cls");
    int opc;
    while(true)
    {
        system("cls");

        cout<<"MENU ALUMNOS "<<endl;
        cout<<"1. AGREGAR REGISTRO "<<endl;
        cout<<"2. BAJA LOGICA "<<endl;
        cout<<"3. MODIFICAR TITULO SECUNDARIO "<<endl;
        cout<<"4. MOSTRAR REGISTROS "<<endl;
        cout<<"5. BAJA FISICA "<<endl;
        cout<<"0. SALIR DEL PROGRAMA "<<endl;
        cout<<"********************** "<<endl;
        cout<<"Elegir una opcion: "<<endl;
        cin >>opc;

        system("cls");
        switch(opc)
        {
            case 1: {
                Alumno alumno;
                alumno.Cargar();
                if( archivo.grabarRegistro( alumno )) cout << "Registro agregado" << endl;
                else cout << "No se pudio agregar el registro";
                break;
            }
            case 2:{
                if( !archivo.bajaLogica()) cout << "Error al dar de baja el registro";
                else cout << "Registro dado de baja" << endl;
                break;
            }
            case 3:{
                if( !archivo.modificarTitulo()) cout << "Error al modificar le titulo";
                else cout << "Registro modificatres "<< endl;
                break;
            }
            case 4:{
                if( !archivo.mostrarRegistros()) cout << "Error al leer los registros de alumnos";
                break;
            }
            case 5:{
                if( !archivo.bajaFisica()) cout << "Error al leer el archivo de alumnos "<< endl;
                break;
            }
            case 0:{
                return 0;
                break;
            }
        }
            system("pause");
    }
    system("pause");
    return 0;
}

