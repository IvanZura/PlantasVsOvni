//#############################################################################
// ARCHIVO             : clsFondo.cpp
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
// DESCRIPCION: Es el sprite del campo
//
///////////////////////////////////////////////////////////////////////////////
#include "clsFondo.h"

//=============================================================================
// METODO    : int init(clsScreen*)
// ACCION    : Inicializa el sprite del campo de juego.
// PARAMETROS: clsScreen*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsFondo::init(clsScreen *s)
{
    screen = s;
    setItems(1);
    setI(0);
    error.set(load("images/FONDO.png"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    return error.get();
}
