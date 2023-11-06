#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Vendedor{
private:
        char _codVendedor[5];
        char _nombre[30];
        int _provincia; //1 a 24
        int _calificacion; //1 a 10

    public:

        Vendedor()
        {
            strcpy(_codVendedor, "Jorge");
            _nombre = "Jorge";
            _calificacion = 5;
            _provincia = 10;
        };
        const char *getCodVendedor(){ return _codVendedor;};
        const char *getNombreVendedor(){ return _nombre;};
        int getProvinciaVendedor(){ return _provincia;};
        int getCalificacionVendedor(){ return _calificacion;};


};


class Usuario
{
    char _codUsuario[5];
    char _nombre[30];
    int _provincia;
    int _calificacion;

    const char *getCodUsuario(){ return _codUsuario;};
    const char *getNombreUsuario(){ return _nombre;};
    int getProvinciaUsuario(){ return _provincia;}
    int getCalificacionUsuario(){ return _calificacion;}
};

class Ventas
{
    int _numeroCompra;
    char _codVendedor[5];
    char _codUsuario[5];
    float importe;
    int tipoPago; //1-credito 2-mp 3-pago facilongo
};

bool guardarVendedor(Vendedor vendedor)
{
    FILE * p;

    p = fopen("vendedores.dat", "ab");
    if( p == NULL )
    {
        return false;
    }
    bool escribio = fwrite( &vendedor, sizeof(Vendedor), 1, p);

    return escribio;
}


int main()
{
    Vendedor jorge;
    guardarVendedor( jorge );
    return 0;
}
