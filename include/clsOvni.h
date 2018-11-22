//#############################################################################
// ARCHIVO             : clsOvni.h
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
#ifndef CLSOVNI_H
#define CLSOVNI_H

#include <adnConsts.h>
#include <clsSprite.h>
#include <clsRandom.h>
#include <clsScreen.h>

class clsOvni : public clsSprite
{
    public:
        clsOvni();
        void inherit(){};
        int init(clsScreen *s);
        void setVelocidad(int);
        int getVelocidad();
        void avanzar(clsScreen *);
        int getInitia();
        void setInitia(int, clsScreen*);
        bool toco(clsSprite*);

    protected:

    private:
        int initia = 0;
        clsScreen *screen;
        clsRandom random;
        int velocidad;
};

#endif // CLSOVNI_H
