//#############################################################################
// ARCHIVO             : clsDisparoPlanta.h
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
#ifndef CLSDISPAROPLANTA_H
#define CLSDISPAROPLANTA_H

#include <clsSprite.h>


class clsDisparoPlanta : public clsSprite
{
    public:
        clsDisparoPlanta();
        void inherit(){};
        int init(clsScreen*, int, int);
        int getInitia();
        void setInitia(int, clsScreen*);
        bool toco(clsSprite*);

    protected:

    private:
        int initia = 0;
        clsScreen *screen;
};

#endif // CLSDISPAROPLANTA_H
