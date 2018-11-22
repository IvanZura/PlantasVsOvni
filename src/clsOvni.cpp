//#############################################################################
// ARCHIVO             : clsOvni.cpp
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
// DESCRIPCION: Esta clase maneja el sprite del ovni y sus funciones
//
///////////////////////////////////////////////////////////////////////////////
#include "clsOvni.h"

//=============================================================================
// METODO    : clsOvni clsOvni()
// ACCION    : Inicializa el sprite del ovni
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
clsOvni::clsOvni()
{
    setItems(1);
    setI(0);
    load("images/ovni-80-80.png");
    this->velocidad = 0;

}
//=============================================================================
// METODO    : int init(clsScreen*)
// ACCION    : Inicializa la posicion RANDOM del ovni
// PARAMETROS: clsScreen*.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
int clsOvni::init(clsScreen *s)
{
    this->initia = 1;
    //setX(1524);
    switch(random.getNumber(5))
    {
        case 0:
        {
            setY(60);
        }break;
        case 1:
        {
            setY(160);
        }break;
        case 2:
        {
            setY(260);
        }break;
        case 3:
        {
            setY(360);
        }break;
        case 4:
        {
            setY(460);
        }break;
    }
    paste(s->getPtr());
}
//=============================================================================
// METODO    : int getInitia()
// ACCION    : Devuelve el estado de inicializacion del sprite
// PARAMETROS: ninguno.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsOvni::getInitia()
{
    return this->initia;
}
//=============================================================================
// METODO    : int getInitia(int, clsScreen*)
// ACCION    : Establece el estado de inicializacion del sprite
// PARAMETROS: int, clsScreen*.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsOvni::setInitia(int num, clsScreen *s)
{
    this->initia = 0;
    setX(1524);
    paste(s->getPtr());
}
//=============================================================================
// METODO    : bool toco(clsSprite*)
// ACCION    : Devuelve true si el sprite que se paso toca con el sprite ovni
// PARAMETROS: clsSprite*.
// DEVUELVE  : bool.
//-----------------------------------------------------------------------------
bool clsOvni::toco(clsSprite *spr)
{
    return this->getContact(spr);
}
