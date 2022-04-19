#include <iostream>
#include <windows.h>
#include <cwchar>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <vector>
#include <time.h>
#include "Proceso.h"
#include "Menu.h"

#define PROCESOS_RESTANTES 9;

using namespace std;

/*
void sortAscending(vector<Proceso> &procesos)
{
    struct ascendingData{
        inline bool operator () (const Proceso& p1, const Proceso p2){
            return (p1.getDuracion() < p2.getDuracion());
        }
    };

    sort(procesos.begin(), procesos.end(), ascendingData());
}*/

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


