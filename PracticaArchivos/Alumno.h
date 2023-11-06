#pragma once
#include <cstring>
#include "Persona.h"
class Alumno : public Persona
{
    private:
        int _legajo;
        int _IDcarrera;
        char _tituloSecundario[30];
    public:
        void Cargar();
        void Mostrar();

        bool setLegajo( int legajo );
        const int getLegajo();

        bool setIDcarrera( int IDcarrera );
        const int getIDcarrera();

        void setTitulo( const char* t);

};
