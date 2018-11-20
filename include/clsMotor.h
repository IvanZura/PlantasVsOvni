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
        int keyCommand(bool*, Uint16);

    private:
        int cantPersonajes = 100;
        clsRandom random;
        clsMenu menuF;
        clsFondo fondo;
        clsDisparoPlanta disparoPlanta[100];
        clsPlanta planta1;
        clsPlanta planta2;
        clsPlanta planta3;
        clsPlanta planta4;
        clsPlanta planta5;
        clsOvni ovni[100];
        clsTimer timer;
        clsLog log;
};

#endif // CLSMOTOR_H
