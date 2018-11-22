//#############################################################################
// ARCHIVO             : clsMenu.cpp
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
// DESCRIPCION: Es el sprite del menu y los botones
//
///////////////////////////////////////////////////////////////////////////////
#include "clsMenu.h"

//=============================================================================
// METODO    : int init(clsScreen*)
// ACCION    : Inicializa el sprite del menu.
// PARAMETROS: clsScreen*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsMenu::init(clsScreen *s)
{
    error.set(0);
    screen = s;
    setItems(1);
    setI(0);
    return error.get();
}
//=============================================================================
// METODO    : bool fueClick(int, int)
// ACCION    : Devuelve true si las coordenadas pasadas tocan el sprite
// PARAMETROS: int, int.
// DEVUELVE  : bool.
//-----------------------------------------------------------------------------
bool clsMenu::fueClick(int x, int y)
{
    bool result = false;

    if(x >= getX() && x <= getX()+getWidth() &&
       y >= getY() && y <= getY()+getHeight())
    {
        result = true;
    }
    return result;
}
