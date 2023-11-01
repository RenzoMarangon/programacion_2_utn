#ifndef MOVIMIENTOARCHIVO_H_INCLUDED
#define MOVIMIENTOARCHIVO_H_INCLUDED
#include <string>
#pragma once
#include "Movimiento.h"

class MovimientoArchivo
{
    public:
        MovimientoArchivo( std::string nombre);
        bool Guardar(Movimiento reg);
        bool Guardar(Movimiento reg, int posicion);
        int Buscar( int IDMovimiento);
        int contarRegistros();
        Movimiento Leer(int nroRegistro);


    private:
        std::string _nombreArchivo;
};


#endif // MOVIMIENTOARCHIVO_H_INCLUDED
