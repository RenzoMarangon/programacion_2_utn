#include <cstdio>
#include "MovimientoArchivo.h"
#include <iostream>

MovimientoArchivo::MovimientoArchivo( std::string nombre)
{
    _nombreArchivo = nombre;
}

bool MovimientoArchivo::Guardar(Movimiento reg)
{
    bool pudoEscribir;
    FILE *p = fopen(_nombreArchivo.c_str(), "ab");
    if( p == nullptr)
    {
        return false;
    }

    pudoEscribir = fwrite( &reg, sizeof(Movimiento), 1, p);

    fclose(p);

    return pudoEscribir;
}


bool MovimientoArchivo::Guardar(Movimiento reg, int posicion)
{
    bool pudoEscribir;
    FILE *p = fopen(_nombreArchivo.c_str(), "rb+    ");
    if( p == nullptr )
    {
        return false;
    }

    fseek(p, posicion*sizeof(Movimiento), SEEK_SET);
    pudoEscribir = fwrite( &reg, sizeof(Movimiento), 1, p);

    fclose(p);

    return pudoEscribir;
}


int MovimientoArchivo::Buscar( int IDMovimiento)
{


    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    if( p == nullptr )
    {
        return -1;
    }
    Movimiento reg;
    int i=0;
    while( fread(&reg, sizeof(Movimiento), 1, p) > 0)
    {
        if(reg.getId() == IDMovimiento)
        {

            fclose(p);
            return i;
        }
        i++;

    }
    fclose(p);
    return -1;

}


int MovimientoArchivo::contarRegistros()
{
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");

    if( p == nullptr)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);
    return bytes/sizeof(Movimiento);

}
Movimiento MovimientoArchivo::Leer(int nroRegistro)
{
    FILE *p = fopen(_nombreArchivo.c_str(), "rb");
    Movimiento reg;
    if(p == nullptr)
    {
        return reg;
    }
    fseek(p, nroRegistro*sizeof(Movimiento), SEEK_SET );
    fread(&reg, sizeof(Movimiento), 1, p );
    fclose(p);

    return reg;
}
