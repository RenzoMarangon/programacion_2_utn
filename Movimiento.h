#pragma once
#include <string>

class Movimiento
{
    private:
        int _id;
        float _importe;
        int _tipoMovimiento; // 1 - Ingreso, 2 - Salida
        char _descripcion[100];
        char _referencia[100];
        bool _estado;
    public:
        Movimiento();

        int getId() const;
        void setId( int id);

        float getImporte() const;
        void setImporte( float importe);

        int getTipoMovimiento() const;
        void setTipoMovimiento( int tipoMovimiento );

        std::string getReferencia() const;
        void setReferencia( std::string referencia);

        std::string getDescripcion() const;
        void setDescripcion( std::string descripcion);

        bool getEstado() const;
        void setEstado( bool estado);


};
