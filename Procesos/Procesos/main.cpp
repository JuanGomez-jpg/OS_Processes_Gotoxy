#include <iostream>
#include <windows.h>
#include <time.h>
#include "Menu.h"

#define PROCESOS_RESTANTES 9;

using namespace std;


void Color(int fondo, int texto)
{
    HANDLE Console=GetStdHandle(STD_OUTPUT_HANDLE);
    int nuevoColor=texto+(fondo*16);
    SetConsoleTextAttribute(Console, nuevoColor);
}

int main()
{
    srand (time(NULL));

    Menu m;

    m.init();

    return 0;
}


