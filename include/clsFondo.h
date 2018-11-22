//#############################################################################
// ARCHIVO             : clsFondo.h
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
#ifndef CLSFONDO_H
#define CLSFONDO_H

#include <clsSprite.h>
#include <clsScreen.h>


class clsFondo : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen *s);

    protected:

    private:
        clsScreen *screen;
};

#endif // CLSFONDO_H
