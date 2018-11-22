//#############################################################################
// ARCHIVO             : clsPlanta.h
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
#ifndef CLSPLANTA_H
#define CLSPLANTA_H

#include <clsSprite.h>
#include <clsRandom.h>
#include <clsTimer.h>
#include <clsDisparoPlanta.h>


class clsPlanta : public clsSprite
{
    public:
        void inherit(){};
        int init(clsScreen *s);
        bool fueClick(int, int);
        void setSalud(char*);
        char* getSalud();
        void disparo(clsScreen*);
        bool toco(clsSprite*);
        void lastima(clsScreen*);
        int strLen(char*);
        int strToInt(char*);
        void setChoqueCero();
    protected:

    private:
        char salud[4];
        int choque = 0;
        clsScreen *screen;
        clsRandom random;
        clsTimer timer;
        clsDisparoPlanta disparoPlanta;
};

#endif // CLSPLANTA_H
