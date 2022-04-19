#ifndef MENU_H
#define MENU_H
#define PROCESOS_RESTANTES 9;

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
#include "Metodos.h"

using namespace std;

class Menu
{
public:
    Menu();

    void invocarInterfaz();
    void gotoxy(int x,int y);
    void SetColor(int ForgC);
    void procesosEjecucion();
    void cuadroProcesosEjecucion();
    void limpiarMenu();
    int MenuOpc (int procesosRestantes, int maxProcesos);
    void init();
    void mostrarProcesosAgregados(Proceso p, string action, int size);

private:
    vector<Proceso> procesos;

};

#endif // MENU_H
