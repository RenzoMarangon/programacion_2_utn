#include <iostream>
#include <cstring>
#include "parcial2practica.h"
using namespace std;

class JugadorMatriculaMil
{
    private:
        int _DNI, _claustro;
        char _nombre[30], _apellido[30], _nombreDeporte[30];

    public:
        void setDNI( int dni){ _DNI = dni; }
        void setClaustro( int claustro ){ _claustro = claustro;}
        void setNombre( char *nombre ){ strcpy(_nombre, nombre); }
        void setApellido( char *apellido ){ strcpy(_apellido, apellido); }
        void setNombreDeporte( char *nombreDeporte ){ strcpy(_nombreDeporte, nombreDeporte); }
        int getClaustro(){ return _claustro; }
};

class ArchivoJugadoresMatriculaMil

int main()
{

    return 0;
}
