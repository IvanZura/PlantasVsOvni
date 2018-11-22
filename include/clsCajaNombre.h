//#############################################################################
// ARCHIVO             : clsCajaNombre.h
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
#ifndef CLSCAJANOMBRE_H
#define CLSCAJANOMBRE_H

#include <clsSprite.h>


class clsCajaNombre : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen*, int, int);

    protected:

    private:
        clsScreen *screen;
};

#endif // CLSCAJANOMBRE_H
