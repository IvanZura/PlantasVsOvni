#include "clsPuntos.h"

void clsPuntos::init()
{
    FILE *filePuntos;
    filePuntos = fopen(this->F_PUNTOS, "rb");
    if(filePuntos == NULL)
    {
        fclose(filePuntos);
        filePuntos = fopen(this->F_PUNTOS, "wb");
        fclose(filePuntos);
    }
    this->titulo.init();
    this->titulo.loadFont("FONTS/Montserrat-Regular.ttf", 60);
    this->titulo.setFontColor(BLACK);
    this->titulo.setStyle(BOLD);
    for(int i= 0; i < 12; i++)
    {
        this->puntajes[i].init();
        this->puntajes[i].loadFont("FONTS/Montserrat-Regular.ttf", 40);
        this->puntajes[i].setFontColor(BLACK);
        this->puntajes[i].setStyle(BOLD);
    }
}
int clsPuntos::setPuntos(char* nombre, int puntos)
{
    strcpy(this->nombre, nombre);
    this->puntos = puntos;
    FILE *filePuntos;
    filePuntos = fopen(this->F_PUNTOS, "ab");
    if(filePuntos != NULL)
    {
        if(fwrite(this, sizeof(clsPuntos), 1, filePuntos))
        {
            fclose(filePuntos);
            return 0;
        }
        else
        {
            fclose(filePuntos);
            return 1;
        }

    }
}

int clsPuntos::getPuntos(clsScreen *screen, clsText *text, clsText *textP)
{
    error.set(0);
    FILE *filePuntos;
    filePuntos = fopen(this->F_PUNTOS, "rb");
    if(filePuntos != NULL)
    {
        int i = 0;
        int c = 2;
        this->titulo.centredWrite("TABLA DE PUNTAJES", 20, screen->getPtr());
        this->puntajes[0].write("NOMBRE", 300, 100, screen->getPtr());
        this->puntajes[1].write("PUNTAJE", 600, 100, screen->getPtr());
        while(fread(this, sizeof(clsPuntos), 1, filePuntos))
        {
            if(c == 10)
            {
                break;
            }
            char buffer[7];
            int Y = 150 + i;
            itoa(this->puntos, buffer, 10);
            this->puntajes[c].write(this->nombre, 300, Y, screen->getPtr());
            this->puntajes[++c].write(buffer, 700, Y, screen->getPtr());
            screen->refresh();
            i = i + 40;
            c = c + 2;
        }
    }
    fclose(filePuntos);
    return error.get();
}
