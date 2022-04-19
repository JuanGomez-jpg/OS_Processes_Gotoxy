#ifndef METODOS_H
#define METODOS_H

#include <iostream>
#include <vector>
#include <windows.h>
#include "Proceso.h"
#include "Menu.h"
#include "Advertencias.h"
#include "Validaciones.h"

using namespace std;

class Metodos
{
public:
    Metodos();

    int agregarProcesoMan(int procesosRestantes, vector<Proceso> &procesos);
    int agregarProcesoAut(int procesosRestantes, vector<Proceso> &procesos);
    void gotoxy(int x,int y);
    void SetColor(int ForgC);
    string removerEspacios(string resp);
    void modificarProceso(int procesosRestantes, int cantidadMaxProc, vector<Proceso> &procesos);
    void modificar(vector<Proceso> &procesos);

private:

};

#endif // METODOS_H
