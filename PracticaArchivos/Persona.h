#pragma once

class Persona
{
    protected:
        int _DNI;
        char _nombre[30];
        char _apellido[30];
        char _email[30]; 
        char _telefono[30];
        char _direccion[30];
        bool _estado;
    public:
        void Cargar();
        void Mostrar();
        bool getEstado() const;
        void setEstado(bool estado);
        int getDNI() const;
        bool setDNI(int DNI);
};
