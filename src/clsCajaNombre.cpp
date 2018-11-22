//#############################################################################
// ARCHIVO             : clsCajaNombre.cpp
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
// DESCRIPCION: Es el sprite de la caja de nombre del jugador
//
///////////////////////////////////////////////////////////////////////////////
#include "clsCajaNombre.h"

//=============================================================================
// METODO    : int init(clsScreen*, int, int)
// ACCION    : Inicializa el sprite de la caja de nombre
// PARAMETROS: clsScreen*, int, int.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
int clsCajaNombre::init(clsScreen *s, int x, int y)
{
    setItems(1);
    setI(0);
    setX(x);
    setY(y);
    load("images/caja.png");
    paste(s->getPtr());
}
