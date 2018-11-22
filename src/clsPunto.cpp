//#############################################################################
// ARCHIVO             : clsPunto.cpp
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
#include "clsPunto.h"
const char F_PUNTOS[90] = "./archivos/puntos.dat";

//=============================================================================
// METODO    : int getPuntos()
// ACCION    : Devuelve los puntos almacenados en la clase.
// PARAMETROS: ninguno.
// DEVUELVE  : int - puntos.
//-----------------------------------------------------------------------------
int clsPunto::getPuntos()
{
    return this->puntos;
}
//=============================================================================
// METODO    : char* getNombre()
// ACCION    : Devuelve el nombre almacenado en la clase.
// PARAMETROS: ninguno.
// DEVUELVE  : char* - nombre.
//-----------------------------------------------------------------------------
char* clsPunto::getNombre()
{
    return this->nombre;
}
//=============================================================================
// METODO    : void setNombre(char*)
// ACCION    : Establece el nombre que le pasan a la clase
// PARAMETROS: char*.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPunto::setNombre(char* nombre)
{
    strcpy(this->nombre, nombre);
}
//=============================================================================
// METODO    : void setPuntos(int)
// ACCION    : Establece los puntos que le pasan a la clase
// PARAMETROS: int.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPunto::setPuntos(int puntos)
{
    this->puntos = puntos;
}
//=============================================================================
// METODO    : void Guardar()
// ACCION    : Guarda el nombre y los puntos de la clase en el archivo.
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPunto::Guardar()
{
    FILE *filePuntos;
    filePuntos = fopen(F_PUNTOS, "ab");
    if(filePuntos != NULL)
    {
        if(fwrite(this, sizeof(clsPunto), 1, filePuntos))
        {
            fclose(filePuntos);
        }
        else
        {
            fclose(filePuntos);
        }

    }
}
