#include "clsPunto.h"
const char F_PUNTOS[90] = "./archivos/puntos.dat";

int clsPunto::getPuntos()
{
    return this->puntos;
}
char* clsPunto::getNombre()
{
    return this->nombre;
}
void clsPunto::setNombre(char* nombre)
{
    strcpy(this->nombre, nombre);
}
void clsPunto::setPuntos(int puntos)
{
    this->puntos = puntos;
}
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
