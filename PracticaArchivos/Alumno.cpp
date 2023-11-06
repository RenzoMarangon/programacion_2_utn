#include "Alumno.h"
#include <iostream>
using namespace std;
#include "FuncionesGlobales.h"

bool Alumno::setLegajo(int legajo)
{
    if( legajo > 0)
    {
        _legajo = legajo;
    }else{
        return false;
    }
    return true;
}

const int Alumno::getLegajo(){ return _legajo ;};

bool Alumno::setIDcarrera( int IDcarrera )
{
    if( IDcarrera > 0)
    {
        _IDcarrera = IDcarrera;
    }else{
        cout << "No se pudo cargar el ID de la carrera.";
        return false;
    }
    return true;
}
const int Alumno::getIDcarrera(){ return _IDcarrera; }

void Alumno::setTitulo( const char* t) { strcpy( _tituloSecundario, t);}

void Alumno::Cargar()
{
    Persona::Cargar();
    cout << "Legajo: ";
    int intLegajo;
    cin >> intLegajo;

    if(!setLegajo( intLegajo ))
    {
        cout << "No se pudo cargar el legajo.";
    }

    cout << "ID carrera: ";
    int idCarrera;
    cin >> idCarrera;
    Alumno::setIDcarrera( idCarrera );

    cout << "Titulo secundario :";
    cargarCadena( _tituloSecundario, 29);



}
void Alumno::Mostrar()
{
    Persona::Mostrar();
    std::cout<<"Legajo: " << _legajo << std::endl;
    std::cout<<"ID carrera: " << _IDcarrera << std::endl;
    std::cout<<"Titulo secundario: " << _tituloSecundario << std::endl;

}

