#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <iostream>
#include <windows.h>
#include <vector>
#include "Proceso.h"

using namespace std;

class Validaciones
{
public:
    Validaciones();

    bool validarEntradaMenu(string resp);
    bool validarEntradaProceso(string resp, int opc, int limSup);
    bool validarEntradaModificar(string resp);
    void validarProcesoExistente(string resp, vector<Proceso> &procesos, int *pos, int *err);

private:

};

#endif // VALIDACIONES_H

