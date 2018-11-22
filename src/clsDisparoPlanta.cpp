//#############################################################################
// ARCHIVO             : clsDisparoPlanta.cpp
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
// DESCRIPCION: Es el sprite del disparo de la manzana.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsDisparoPlanta.h"

//=============================================================================
// METODO    : clsDisparoPlanta clsDisparoPlanta()
// ACCION    : Inicializa el sprite del disparo de la manzana con la imagen
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
clsDisparoPlanta::clsDisparoPlanta()
{
    setItems(1);
    setI(0);

    load("images/disparo1.png");

}
//=============================================================================
// METODO    : int init(clsScreen*, int, int)
// ACCION    : Inicializa el sprite del disparo de la manzana.
// PARAMETROS: clsScreen*, int, int.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsDisparoPlanta::init(clsScreen *s, int x, int y)
{
    setX(x);
    setY(y);
    this->initia = 1;
    paste(s->getPtr());
}
//=============================================================================
// METODO    : int getInitia()
// ACCION    : Devuelve el estado de inicializacion del sprite.
// PARAMETROS: ninguno.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsDisparoPlanta::getInitia()
{
    return this->initia;
}
//=============================================================================
// METODO    : void setInitia(int, clsScreen*)
// ACCION    : Establece el estado de inicializacion del sprite.
// PARAMETROS: int, clsScreen*.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsDisparoPlanta::setInitia(int num, clsScreen *s)
{
    this->initia = num;
    setX(-500);
    paste(s->getPtr());
}
//=============================================================================
// METODO    : bool toco(clsSprite*)
// ACCION    : devuelve true si el sprite pasado toca al sprite del disparo
// PARAMETROS: clsSprite*.
// DEVUELVE  : bool.
//-----------------------------------------------------------------------------
bool clsDisparoPlanta::toco(clsSprite *spr)
{
    return this->getContact(spr);
}
