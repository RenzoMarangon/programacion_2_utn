#include "Archivo.h"
#include <iostream>
using namespace std;

Archivo::Archivo(const char *n)
{
    strcpy( _nombre, n);
}

bool Archivo::grabarRegistro(Alumno registro)
{
    FILE *p;

    p = fopen( _nombre, "ab" );
    if(p==NULL)
    {
        return false;
    }

    bool escribio = fwrite( &registro, sizeof registro, 1, p );

    fclose(p);


    return escribio;
}

bool Archivo::mostrarRegistros()
{
    Alumno registro;
    FILE *p;
    p = fopen( _nombre, "rb" );
    if( p == NULL )
    {
        return false;
    }
    while( fread(&registro, sizeof registro, 1, p ) == 1 )
    {
        if( registro.getEstado())
        {
            registro.Mostrar();
            std::cout << std::endl;
        }
    }
    fclose(p);
    return true;
}

Alumno Archivo::leerRegistro( int posicion )
{
    Alumno registro;
    registro.setEstado(false);
    FILE *p;

    p = fopen( _nombre, "rb" );
    if( p == NULL )
    {
        return registro;
    }
    fseek( p, sizeof registro*posicion, 0);
    fread( &registro, sizeof registro, 1, p );
    fclose(p);
    return registro;
}

bool Archivo::sobreescribirRegistro( Alumno registro, int posicion)
{

    FILE *p;
    p = fopen(_nombre, "rb+");
    if(p == NULL ) return false;


    fseek( p, sizeof registro*posicion, 0);
    bool escribio = fwrite( &registro, sizeof registro, 1, p);
    fclose(p);
    return escribio;

}

bool Archivo::bajaLogica()
{
    int legajo, pos;
    cout << "Ingresar legajo: ";
    cin >> legajo;

    pos = Archivo::buscarLegajo( legajo );
    if( pos == -1)
    {
        cout << "No existe ese legajo carajo " << endl;
        return false;
    }

    //Traigo el registro del alumno
    Alumno registro;
    registro = Archivo::leerRegistro( pos );

    cout << "Registro a borrar: " << endl;
    registro.Mostrar();
    cout << endl;

    char opcion;
    cout << "Desea borrarlo? (S/N) ";
    cin >> opcion;

    if(opcion == 's' || opcion == 'S')
    {
        registro.setEstado( false );
        ///Sobreescribo el registro
        bool quePaso = Archivo::sobreescribirRegistro(registro, pos);
        return quePaso;
    }

    return false;
}

bool Archivo::bajaFisica(){
    Archivo archivo( _nombre );
    Alumno registro;
    int cantRegistros=archivo.contarRegistros();
    int i;
    FILE *p;
    p=fopen("alumnos.bak", "wb");
    if(p==NULL) return false;
    for(i=0;i<cantRegistros;i++){
        registro=archivo.leerRegistro(i);
        fwrite(&registro, sizeof registro,1, p);
    }
    fclose(p);

    FILE *pBak;
    pBak=fopen("alumnos.bak","rb");
    if(pBak==NULL)return false;

    p=fopen(_nombre,"wb");
    if(p==NULL){
            fclose(pBak);
            return false;
    }
    while(fread(&registro, sizeof registro, 1, pBak)==1){
        if(registro.getEstado()==true){
            fwrite(&registro, sizeof registro, 1, p);
        }
    }
    fclose(pBak);
    fclose(p);
}

bool Archivo::modificarTitulo()
{
    Archivo archivo( _nombre );
    int legajo, pos;
    cout << "Ingresar el legajo del alumno a modificar: ";
    cin >> legajo;
    pos = archivo.buscarLegajo( legajo );
    if( pos == -1)
    {
        cout << "No existe ese legajo" << endl;
        return false;
    }

    Alumno registro;
    registro = archivo.leerRegistro( pos );

    cout << "Registro a modificar" << endl;
    registro.Mostrar();
    cout << endl;

    char opcion;
    cout << "¿Desea modificarlo? (S/N)";
    cin >> opcion;
    char tituloNuevo[30];
    if( opcion == 's' || opcion == 'S')
    {
        cout << "Ingresar nuevo titulo: ";
        cargarCadena( tituloNuevo, 29);
        registro.setTitulo( tituloNuevo );
        bool quePaso = archivo.sobreescribirRegistro( registro, pos );
        return quePaso;
    }
    return false;
}

int Archivo::buscarLegajo( int legajo )
{
    Alumno registro;
    FILE *p;
    p=fopen(_nombre, "rb");
    int pos = 0;
    if( p == NULL )
    {
        return -2;
    }
    while( fread(&registro, sizeof registro, 1, p) == 1)
    {
        if( legajo == registro.getLegajo())
        {
            fclose(p);
            return pos;
        }
        pos++;
    }

    fclose(p);
    return -1;
}

int Archivo::contarRegistros()
{

    int cantRegistros = 0;
    FILE *p;
    p=fopen( _nombre, "rb" );
    if(p==NULL)
    {
        return -1;
    }
    fseek(p,0,2); //Voy hasta el final del archivo y cuento la cantidad de bytes
    int cantBytes = ftell(p);
    /// me dice que cantidad de bytes hay desde el principio del archivo
    ///hasta la posición actual del puntero file

    fclose(p);
    cantRegistros = cantBytes/sizeof(Alumno);
    return cantRegistros;
}

int Archivo::contarRegistrosActivos()
{
    Alumno registro;
    int cantRegistros = 0;
    FILE *p;
    p=fopen( _nombre, "rb" );
    if(p = NULL)
    {
        return -1;
    }
    while( fread(&registro, sizeof registro, 1, p) == 1)
    {
        if( registro.getEstado() ) cantRegistros++;
    }
    fclose(p);
    return cantRegistros;
}



