#include <iostream>
#include <cstring>
using namespace std;

#include "parcial2practica.h"


/*
class DeporteClaustros
{
private:
        int _idDeporte, _anioOrigen, _idCategoria;
        char _nombre[30];
        bool _estado;
    public:
        void setIDdeporte( int id ){ _idDeporte = id; }
        void setAnioOrigen( int anioOrigen ){ _anioOrigen = anioOrigen; }
        void setIDcategoria( int idCat ){ _idCategoria = idCat; }

        void setEstado(bool e){_estado=e;}
        void Mostrar(){
   }
};*/

class ArchivoDeportesClaustro
{
    private:
        char _nombre[30];
    public:
        ArchivoDeportesClaustro( const char *n){ strcpy(_nombre, n); }

        Deporte leerRegistro( int pos )
        {
            Deporte reg;

            reg.setEstado(false);

            FILE *p;

            p = fopen(_nombre, "rb");
            if( p == NULL) return reg;

            fseek(p, sizeof(reg)*pos, 0 );
            fread(&reg, sizeof(reg), 1, p);
            fclose(p);
            return reg;

        }

        int contarRegistros()
        {
            Deporte reg;

            FILE *p;

            p = fopen(_nombre, "rb");
            if( p == NULL ) return -1;

            fseek(p, 0, 2);

            int tam = ftell(p);
            fclose(p);

            return tam/sizeof(Deporte);
        }

        bool grabarRegistro( Deporte reg)
        {
            FILE *p;
            p = fopen(_nombre, "ab");
            if( p == NULL ) return -1;

            bool escribio = fwrite(&reg, sizeof(reg), 1, p);
            fclose(p);
            return escribio;
        }
};



bool tieneCuatroClaustros( Deporte deporte)
{
    Jugador jugador;

    ArchivoJugadores archJugadores("jugadores.dat");

    int cantJugadores = archJugadores.contarRegistros();

    int cuatroClaustros[4] = { 0 };

    for( int i = 0; i<cantJugadores; i++)
    {
        jugador = archJugadores.leerRegistro(i);

        if( jugador.getIDdeporte() == deporte.getIDdeporte() )
        {
            cuatroClaustros[jugador.getClaustro()-1] = 1;
        }
    }

    int cont = 0;
    for( int i = 0; i<4; i++)
    {
        cont+=cuatroClaustros[i];
    }

    return cont==4;

}


/**
Hacer un archivo con los deportes que tengan jugadores de todos los claustros.
Los registros del archivo nuevo deben tener el mismo formato que el archivo de deportes.
Crear un vector dinámico con los equipos de nivel inicial. Listar el vector.
*/
void puntoA()
{
    Deporte deporte;

    ArchivoDeportes archDeportes("deportes.dat");

    ArchivoDeportesClaustro archDeportesCuatroClaustros("deportesCuatroClaustros.dat");

    int cantDeportes = archDeportes.contarRegistros();

    for( int i = 0; i<cantDeportes; i++ )
    {
        deporte = archDeportes.leerRegistro(i);

        if( tieneCuatroClaustros( deporte ) )
        {
            archDeportesCuatroClaustros.grabarRegistro(deporte);
        }
    }
}


//Punto b
///Crear un vector dinámico con los equipos de nivel inicial. Listar el vector.

void puntoB()
{
    ArchivoEquipos archivoEquipos("equipos.dat");

    Equipo equipo;

    int cantEquipos = archivoEquipos.contarRegistros();
    if( cantEquipos <=0 ) return;

    int cantEquiposNivelInicial = 0;


    for(int i; i<cantEquipos;i++)
    {
        equipo = archivoEquipos.leerRegistro(i);

        if( equipo.getNivel() == 1) cantEquiposNivelInicial++;
    }

    Equipo *equipoNivelInicial = new Equipo[cantEquiposNivelInicial];

    for( int i = 0; i<cantEquipos;i++ )
    {
        equipo = archivoEquipos.leerRegistro(i);
        if( equipo.getNivel() == 1 ) archivoEquipos.grabarRegistro( equipo );
    }
}

//Punto c

bool Jugador::operator==(  int idClaustro)
{
    if(idClaustro == this->getClaustro()) return true;

    return false;
}

int main()
{
    puntoA();

    Jugador jugador;
    jugador.setClaustro( 1 );

    if(jugador == 1) cout << "SI"; else cout << "no";


return 0;
}
