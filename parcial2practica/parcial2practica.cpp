
#include "parcial2practica.h"





class Equipos10
{
    private:
        int _IDequipo, _IDcategoria;
        char _nombre[30];
        bool _estado;
    public:
        void setIDequipo( int IDequipo){ _IDequipo = IDequipo;}
        void setIDcategoria( int IDcategoria){ _IDcategoria = IDcategoria;}

        void setNombre( const char *nombre ){ strcpy(_nombre, nombre) ;}

        void setEstado( bool estado){ _estado = estado;}

        int getID(){return _IDequipo;};

        void Mostrar(){
            cout<<"EQUIPO "<<_IDequipo<<endl;
            cout<<"NOMBRE "<<_nombre<<endl;
            cout<<"CATEGORIA "<<_IDcategoria<<endl;
        }
};

class ArchivoEquipos10
{
    private:
        char _nombre[30];
    public:
        ArchivoEquipos10( const char *nombre){ strcpy(_nombre, nombre); }

        Equipos10 leerRegistro(int pos)
        {
            Equipos10 reg;
            reg.setEstado(false);
            FILE *p;
            p = fopen(_nombre, "rb");
            if( p == NULL) return reg;
            fseek(p, sizeof reg*pos, 0);
            fread(&reg, sizeof reg, 1, p);
            fclose(p);
            return reg;
        }

        int contarRegistro()
        {
            FILE *p;
            p=fopen(_nombre, "rb");
            if(p == NULL) return 0;

            fseek(p, 0, 2);
            int tam = ftell(p);
            fclose(p);
            return tam/sizeof(Equipos10);
        }

        bool grabarRegistro( Equipos10 reg){

            FILE *p;
            p = fopen(_nombre, "ab");
            if(p == NULL) return false;

            int escribio = fwrite(&reg, sizeof(reg), 1, p);
            fclose(p);

            return escribio;
        }
};

int contarJugadores( int equipo )
{
    ArchivoJugadores archivoJug("jugadores.dat");

    int cantJugadores = 0, cantRegistrosJug;

    Jugador reg;

    cantRegistrosJug = archivoJug.contarRegistros();

    for( int i = 0; i<cantRegistrosJug; i++)
    {
        reg = archivoJug.leerRegistro(i);
        if(reg.getIDequipo() == equipo)
        {
            cantJugadores++;
        }
    }

    return cantJugadores;
}

int buscarDeporte( int idEquipo )
{
    Jugador jugador;

    ArchivoJugadores archJugadores("jugadores.dat");

    int cantRegistros = archJugadores.contarRegistros();

    for( int i = 0; i < cantRegistros; i++)
    {
        jugador = archJugadores.leerRegistro( i );
        if( jugador.getIDequipo() == idEquipo ) return jugador.getIDdeporte();
    }

    return -1;
}

int buscarCategoria( int idDeporte )
{
    Deporte deporte;

    ArchivoDeportes archDeportes("deportes.dat");

    int cantRegistros = archDeportes.contarRegistros();

    for(int i = 0; i<cantRegistros; i++)
    {
        deporte = archDeportes.leerRegistro(i);

        if( deporte.getIDdeporte() == idDeporte ) return deporte.getIDcategoria();
    }

    return -1;
}

/**
Generar un archivo con los equipos que tengan al menos 10 jugadores inscriptos.
Cada registro debe tener el ID de equipo, el nombre del equipo, y la categoría del deporte al que pertenece el equipo.
*/
void puntoA()
{
    Equipos10 equipoDiez;
    ArchivoEquipos10 archEquiposDiez("equiposDiez.dat");

    ArchivoEquipos archivoEquipos("equipos.dat");

    Equipo regEquipo;

    int cantEquipos, cantJugadores, categoria, deporte;

    cantEquipos = archivoEquipos.contarRegistros();

    for( int i = 0; i < cantEquipos; i++)
    {
        regEquipo = archivoEquipos.leerRegistro(i);
        cantJugadores = contarJugadores( regEquipo.getIDequipo() );

        if( cantJugadores >= 10)
        {
            deporte = buscarDeporte( regEquipo.getIDequipo() );
            categoria = buscarCategoria( deporte );
            equipoDiez.setIDcategoria( categoria );
            equipoDiez.setIDequipo( regEquipo.getIDequipo() );
            equipoDiez.setNombre( regEquipo.getNombre());

            archEquiposDiez.grabarRegistro( equipoDiez );
        }
    }
}

///Hacer un vector dinámico para listar el archivo del punto anterior.
void puntoB()
{
    ArchivoEquipos10 archDeportes("equiposDiez.dat");

    int cantRegistros = archDeportes.contarRegistro();



    if( cantRegistros == 0)
    {
        cout << "No hay registros en el archivo";
        return;
    }

    Equipos10 *equipos = new Equipos10[ cantRegistros ];

    if (equipos == NULL) return;

    for(int i = 0; i<cantRegistros; i++)
    {
        equipos[i] = archDeportes.leerRegistro(i);
    }

    for(int i = 0; i<cantRegistros; i++)
    {
        equipos[i].Mostrar();
    }

    delete equipos;
}

/**
Sobrecargar el operador == para comparar un objeto Jugador con un objeto Deporte.
Debe devolver verdadero cuando coinciden los Id de deporte
*/

//punto C

bool operator==( Jugador &objJugador,  Deporte &objDeporte )
{
    if(objJugador.getIDdeporte() == objDeporte.getIDdeporte()) return true;

    return false;
}

bool operator==( Deporte &objDeporte, Jugador &objJugador )
{
    if(objJugador.getIDdeporte() == objDeporte.getIDdeporte()) return true;

    return false;
}



int main()
{
   puntoA();
   puntoB();
   Jugador jugador;
   Deporte deporte;

   if(deporte == jugador) cout << "bichis"; else cout << "No bichis";


    return 0;
}



