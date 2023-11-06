#include <iostream>
using namespace std;
#include <cstring>

#include "Movimiento.h"

Movimiento::Movimiento()
{
    _estado = true;
}

int Movimiento::getId() const
{
    return _id;
}
void Movimiento::setId( int id)
{
    _id = id;
}

float Movimiento::getImporte() const
{
    return _importe;
}
void Movimiento::setImporte( float importe)
{
    _importe = importe;
}

int Movimiento::getTipoMovimiento() const
{
    return _tipoMovimiento;
}
void Movimiento::setTipoMovimiento( int tipoMovimiento )
{
    _tipoMovimiento = tipoMovimiento;
}



std::string Movimiento::getReferencia() const
{
    return _referencia;
}
void Movimiento::setReferencia( std::string referencia)
{
    strcpy(_referencia, referencia.c_str());
}



std::string Movimiento::getDescripcion() const
{
    return _descripcion;
}


void Movimiento::setDescripcion( std::string descripcion)
{
    strcpy(_descripcion, descripcion.c_str());
}

bool Movimiento::getEstado() const
{
    return _estado;
}
void Movimiento::setEstado( bool estado)
{
    _estado = estado;
}
