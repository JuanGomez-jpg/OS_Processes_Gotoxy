#ifndef ADVERTENCIAS_H
#define ADVERTENCIAS_H

#include <iostream>
#include <windows.h>
#include <vector>
#include "Proceso.h"

using namespace std;

class Advertencias
{
public:
    Advertencias();

    void gotoxy(int x,int y);
    void SetColor(int ForgC);
    void advertenciaNoProcesos();
    void advertenciaErrorMaximoProcesos();
    void advertenciaErrorProcesos(int ent, vector<Proceso> &proceso, int limSup);
    void advertenciaErrorMenu();

private:

};

#endif // ADVERTENCIAS_H

