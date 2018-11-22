//#############################################################################
// ARCHIVO             : clsPunto.h
// AUTOR               : Ivan Alejandro Zura.
// VERSION             : v. 14.11 estable.
// FECHA DE CREACION   : 1/11/2018.
// ULTIMA ACTUALIZACION: 22/11/2018.          .
// LICENCIA            : GPL (General Public License) - Version 3.
//=============================================================================
// SISTEMA OPERATIVO   : Linux / Windows.
// IDE                 : Code::Blocks.
// COMPILADOR          : GNU GCC Compiler (Linux) / MinGW (Windows).
//=============================================================================
// DESCRIPCION: Esta clase maneja los puntos al momento de jugar.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSPUNTO_H
#define CLSPUNTO_H
#include <cstring>
#include <cstdio>

class clsPunto
{
    public:
        int getPuntos();
        char* getNombre();
        void setPuntos(int);
        void setNombre(char*);
        void Guardar();

    protected:

    private:
        char nombre[30];
        int puntos;
};

#endif // CLSPUNTO_H
