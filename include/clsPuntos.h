#ifndef CLSPUNTOS_H
#define CLSPUNTOS_H
#include <cstdio>
#include <cstring>
#include <clsScreen.h>
#include <clsText.h>
#include <clsError.h>
#include <clsPunto.h>

class clsPuntos
{
    public:
        void init();
        int TotalPuntos();
        int Sort();
        void mostrarPuntos(clsScreen*);

    protected:

    private:
        clsPunto *todos;


};

#endif // CLSPUNTOS_H
