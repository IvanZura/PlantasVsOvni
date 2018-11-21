#ifndef CLSMOTOR_H
#define CLSMOTOR_H
#include <clsError.h>
#include <clsEvent.h>
#include <clsMode.h>
#include <clsScreen.h>
#include <adnConsts.h>
#include <clsDot.h>
#include <clsRandom.h>
#include <clsMenu.h>
#include <clsFondo.h>
#include <clsPlanta.h>
#include <clsOvni.h>
#include <clsTimer.h>
#include <clsDisparoPlanta.h>
#include <clsLog.h>
#include <clsText.h>
#include <clsCajaNombre.h>

class clsMotor
{
    protected:
        clsEvent event;
        clsError error;
        clsMode mode;
        clsScreen screen;
        clsDot dot;


    public:
        int init();
        int menu();
        int run();
        int keyCommand(bool*, Uint16, clsTimer*);
        int strLen(char*);
        int strToInt(char*);
        int PerdistePapu();

    private:
        char nombre[30];
        char bufferText[7];
        int puntaje = 0;
        int cantPersonajes = 30;
        int dificultad = 3;
        int dificultadTiempo = 1000;
        clsRandom random;

        clsText SaludTexto[5];
        clsText PuntajeTexto[2];
        clsText PerdisteText;
        clsText PausaText;
        clsText NombreText[3];

        clsMenu menuF;
        clsFondo fondo;
        clsDisparoPlanta disparoPlanta[30];
        clsPlanta planta1;
        clsPlanta planta2;
        clsPlanta planta3;
        clsPlanta planta4;
        clsPlanta planta5;
        clsOvni ovni[30];
        clsTimer timer;
        clsLog log;
        clsCajaNombre caja;

};

#endif // CLSMOTOR_H
