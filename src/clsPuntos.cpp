//#############################################################################
// ARCHIVO             : clsPuntos.cpp
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
// DESCRIPCION: Esta clase maneja los puntos al momento de jugar.
//
///////////////////////////////////////////////////////////////////////////////
#include "clsPuntos.h"
clsError error;
clsText titulo;
clsText presioneEnter;
clsText puntajes[14];
const char F_PUNTOS[90] = "./archivos/puntos.dat";

//=============================================================================
// METODO    : void init()
// ACCION    : Inicializa el archivo de los puntos.
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPuntos::init()
{
    FILE *filePuntos;
    filePuntos = fopen(F_PUNTOS, "rb");
    if(filePuntos == NULL)
    {
        fclose(filePuntos);
        filePuntos = fopen(F_PUNTOS, "ab");
        fclose(filePuntos);
    }
    else
    {
        fclose(filePuntos);
    }
    titulo.init();
    titulo.loadFont("FONTS/snap.TTF", 60);
    titulo.setFontColor(BLACK);
    presioneEnter.init();
    presioneEnter.loadFont("FONTS/snap.TTF", 40);
    presioneEnter.setFontColor(BLACK);
    //this->titulo.setStyle(BOLD);
    for(int i= 0; i < 12; i++)
    {
        puntajes[i].init();
        puntajes[i].loadFont("FONTS/snap.TTF", 40);
        puntajes[i].setFontColor(BLACK);
        //this->puntajes[i].setStyle(BOLD);
    }
}
//=============================================================================
// METODO    : int TotalPuntos()
// ACCION    : Cuenta la cantidad de registros que hay en el archivo de puntos.
// PARAMETROS: ninguno.
// DEVUELVE  : int - cantidad de puntos.
//-----------------------------------------------------------------------------
int clsPuntos::TotalPuntos()
{
    int total;
    FILE *archivo;
    archivo = fopen(F_PUNTOS, "rb");
    if(archivo != NULL){
        fseek(archivo, 0, SEEK_END);
        total = ftell(archivo) / sizeof(clsPunto);
    }
    else
    {
        fclose(archivo);
        return 0;
    }
    fclose(archivo);
    return total;
}
//=============================================================================
// METODO    : int Sort()
// ACCION    : Agarra todos los registros del archivo y los ordena.
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
int clsPuntos::Sort()
{
    bool salir = false;
    FILE *archivo;
    archivo = fopen(F_PUNTOS, "rb");
    this->todos = new clsPunto[this->TotalPuntos()];
    fread(this->todos, sizeof(clsPunto), this->TotalPuntos(), archivo);
    while(!salir)
    {
        salir = true;
        for(int i=0; i<this->TotalPuntos()-1; i++)
        {
            if(this->todos[i].getPuntos() < this->todos[i+1].getPuntos())
            {
                clsPunto puntoS; puntoS = this->todos[i]; this->todos[i] = this->todos[i+1]; this->todos[i+1] = puntoS;
                salir = false;
            }
        }
    }
}
//=============================================================================
// METODO    : void mostrarPuntos()
// ACCION    : Ejecuta Sort() y los registros que dejo los muestra.
// PARAMETROS: ninguno.
// DEVUELVE  : nada.
//-----------------------------------------------------------------------------
void clsPuntos::mostrarPuntos(clsScreen *screen)
{
    this->Sort();
    int i = 0;
    int c = 2;
    titulo.centredWrite("TABLA DE PUNTAJES", 20, screen->getPtr());
    puntajes[0].write("NOMBRE", 300, 100, screen->getPtr());
    puntajes[1].write("PUNTAJE", 600, 100, screen->getPtr());
    presioneEnter.centredWrite("Presione la tecla ENTER para continuar...", 500, screen->getPtr());
    screen->refresh();
    for(int z = 0; z < this->TotalPuntos(); z++)
    {
        if(z >= 5)
        {
            break;
        }
        char buffer[70];
        int Y = 150 + i;
        itoa(this->todos[z].getPuntos(), buffer, 10);
        puntajes[c].write(this->todos[z].getNombre(), 300, Y, screen->getPtr());
        puntajes[c+1].write(buffer, 700, Y, screen->getPtr());
        screen->refresh();
        i = i + 40;
        c = c + 2;
    }
}

