//#############################################################################
// ARCHIVO             : clsPlanta.cpp
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
// DESCRIPCION: Esta clase maneja el sprite de la planta y sus funciones
//
///////////////////////////////////////////////////////////////////////////////
#include "clsPlanta.h"

//=============================================================================
// METODO    : void setSalud(char*)
// ACCION    : Establece el nombre que le pasaron a la clase
// PARAMETROS: char*.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPlanta::setSalud(char* sal)
{
    strcpy(this->salud, sal);
}
//=============================================================================
// METODO    : int strLen(char*)
// ACCION    : Devuelve la cantidad de caracteres que tiene una palabra que se le pase
// PARAMETROS: char*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsPlanta::strLen (char *palabra)

{
    int i=0;
    while (palabra[i]!='\0')
    {
        i++;
    }
    return i;
}
//=============================================================================
// METODO    : int strToInt(char*)
// ACCION    : Devuelve en numero entero la cadena que se le pase
// PARAMETROS: char*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsPlanta::strToInt(char *cadena)
{
    int x=1;
    int resultado=0;
    int tam=strLen(cadena)-1;
    for (int c1=tam; c1>=0; c1--)
    {
        resultado+=((cadena[c1]-48)*x);
        x*=10 ;
    }
    return resultado;
}
//=============================================================================
// METODO    : int init(clsScreen*)
// ACCION    : Inicializa el sprite de la planta
// PARAMETROS: clsScreen*.
// DEVUELVE  : int.
//-----------------------------------------------------------------------------
int clsPlanta::init(clsScreen *s)
{
    strcpy(this->salud, "100");
    if(error.get()) return error.get();

    screen = s;
    setItems(1);
    setI(0);
    error.set(load("images/plants3-100-100.png"));
    if(error.get())
    {
        error.show(true);
        return error.get();
    }
    return error.get();
}
//=============================================================================
// METODO    : char* getSalud()
// ACCION    : Devuelve la salud de la planta
// PARAMETROS: ninguno.
// DEVUELVE  : char*.
//-----------------------------------------------------------------------------
char* clsPlanta::getSalud()
{
    return this->salud;
}
//=============================================================================
// METODO    : bool fueClick(int,int)
// ACCION    : Devuelve true si las coodenadas pasadas estan dentro del sprite
// PARAMETROS: int,int.
// DEVUELVE  : bool.
//-----------------------------------------------------------------------------
bool clsPlanta::fueClick(int x, int y)
{
    bool result = false;

    if(x >= getX() && x <= getX()+getWidth() &&
       y >= getY() && y <= getY()+getHeight())
    {
        result = true;
    }
    return result;
}
//=============================================================================
// METODO    : bool toco(clsSprite*)
// ACCION    : Devuelve true si el sprite pasado esta dentro del sprite planta
// PARAMETROS: clsSprite*.
// DEVUELVE  : bool.
//-----------------------------------------------------------------------------
bool clsPlanta::toco(clsSprite *spr)
{
    return this->getContact(spr);
}
//=============================================================================
// METODO    : void setChoqueCero()
// ACCION    : Reestablece el atributo choque a 0
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPlanta::setChoqueCero()
{
    this->choque = 0;
}
//=============================================================================
// METODO    : void lastima(clsScreen*)
// ACCION    : Su funcion es restar vida a la planta o "eliminarla" si esta en 0
// PARAMETROS: clsScreen*.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPlanta::lastima(clsScreen *s)
{
    if(this->choque == 0)
    {
        strcpy(this->salud, "75");
        this->choque = 1;
    }
    else if(this->choque == 1)
    {
        strcpy(this->salud, "50");
        this->choque = 2;
    }
    else if(this->choque == 2)
    {
        strcpy(this->salud, "25");
        this->choque = 3;
    }
    else if(this->choque == 3)
    {
        strcpy(this->salud, "0");
        this->choque = 4;
    }

    if(strcmp(this->salud,"0"))
    {
        setY(-100);
        paste(s->getPtr());
    }
    //load("images/plants3-100-100-lastimado.png");

}
