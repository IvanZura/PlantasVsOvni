//#############################################################################
// ARCHIVO             : clsMenu.h
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
#ifndef CLSMENU_H
#define CLSMENU_H

#include <clsSprite.h>


class clsMenu : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen *s);
        bool fueClick(int, int);

    protected:

    private:
        clsScreen *screen;
};

#endif // CLSMENU_H
