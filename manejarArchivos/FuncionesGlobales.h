#pragma once
#include <cstdio>
#include <iostream>

//
void cargarCadena( char* cadena, int tamanio )
{
    fflush(stdin);
    int i = 0;
    for( i = 0; i < tamanio; i++)
    {
        cadena[i] = std::cin.get();

        if(cadena[i] == '\n') break;
    }
    cadena[i] = '\0';
    fflush(stdin);
};

