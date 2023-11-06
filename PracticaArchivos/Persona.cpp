#include <iostream>
#include "Persona.h"
#include "FuncionesGlobales.h"

bool Persona::getEstado() const { return _estado; }
void Persona::setEstado(bool estado) { _estado = estado; }

int Persona::getDNI() const { return _DNI; }

bool Persona::setDNI( int DNI) {

    if(DNI > 0) _DNI = DNI;
    else return false;

    return true;

}
void Persona::Cargar()
{
    std::cout << "Nombre: ";
    cargarCadena( _nombre, 29);

    std::cout << "Apellido: ";
    cargarCadena( _apellido, 29);

    std::cout << "Email: ";
    cargarCadena( _email, 29);

    std::cout << "Telefono: ";
    cargarCadena( _telefono, 29);

    std::cout << "Direccion: ";
    cargarCadena( _direccion, 29);

    std::cout << "DNI: ";
    int documento;
    std::cin >> documento;

    if( !setDNI( documento ))
    {
        std::cout << "No puede haber un DNI negativo" << std::endl;
        return;
    }

    _estado = true;

};

void Persona::Mostrar()
{
    std::cout<<"Nombre: " << _nombre << std::endl;
    std::cout<<"Apellido: " << _apellido << std::endl;
    std::cout<<"Email: " << _email << std::endl;
    std::cout<<"Telefono: " << _telefono << std::endl;
    std::cout<<"Direccion: " << _direccion << std::endl;
    std::cout<<"DNI: " << _DNI << std::endl;
};




