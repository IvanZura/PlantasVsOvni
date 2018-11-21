#ifndef CLSPUNTOS_H
#define CLSPUNTOS_H
#include <cstdio>
#include <cstring>
#include <clsScreen.h>
#include <clsText.h>
#include <clsError.h>

class clsPuntos
{
    public:
        void init();
        int setPuntos(char*, int);
        int getPuntos(clsScreen*, clsText*, clsText*);

    protected:

    private:
        const char F_PUNTOS[90] = "./archivos/puntos.dat";
        char nombre[30];
        int puntos;
        clsError error;
        clsText titulo;
        clsText puntajes[12];
};

#endif // CLSPUNTOS_H
