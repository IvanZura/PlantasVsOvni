//#############################################################################
// ARCHIVO             : clsPuntos.h
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
// DESCRIPCION: Esta clase maneja todos los puntos.
//
///////////////////////////////////////////////////////////////////////////////
#ifndef CLSPUNTOS_H
#define CLSPUNTOS_H
#include <cstdio>
#include <cstring>
#include <clsScreen.h>
#include <clsText.h>
#include <clsError.h>
#include <clsPunto.h>

class clsPuntos
{
    public:
        void init();
        int TotalPuntos();
        int Sort();
        void mostrarPuntos(clsScreen*);

    protected:

    private:
        clsPunto *todos;


};

#endif // CLSPUNTOS_H
