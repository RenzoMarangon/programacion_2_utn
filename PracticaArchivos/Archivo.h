#include <cstring>
#include "Alumno.h"
#include "FuncionesGlobales.h"
class Archivo
{
    private:
        char _nombre[30];
    public:
        Archivo(const char *n);


        bool mostrarRegistros();
        bool grabarRegistro( Alumno );
        int buscarLegajo( int legajo );
        Alumno leerRegistro(int posicion );
        bool sobreescribirRegistro( Alumno registro, int posicion );
        int contarRegistrosActivos();
        int contarRegistros();
        bool bajaLogica();
        bool bajaFisica();
        bool modificarTitulo();
};


