#ifndef CLSPUNTO_H
#define CLSPUNTO_H
#include <cstring>
#include <cstdio>

class clsPunto
{
    public:
        int getPuntos();
        char* getNombre();
        void setPuntos(int);
        void setNombre(char*);
        void Guardar();

    protected:

    private:
        char nombre[30];
        int puntos;
};

#endif // CLSPUNTO_H
