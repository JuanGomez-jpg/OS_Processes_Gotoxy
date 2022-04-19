#include "Validaciones.h"

Validaciones::Validaciones()
{

}

bool Validaciones::validarEntradaMenu(string resp)
{
    // Variable bandera
    bool val = false;
    // Arreglo de char para almacenar la entrada
    char a[resp.size()];
    //Tamaño de la entrada
    int size = resp.size();

    for (int i(0) ; i < size; ++i) a[i] = resp.at(i);

    for (int i(0) ; i < size; ++i)
    {
        if ( (a[i] >= 0 && a[i] <= 47) || (a[i] >= 54)) val = true;
    }

    if (!val)
    {
        int respAux = atoi(a);
        if (respAux <= 0 || respAux >= 6)
        {
            val = true;
        }
    }

    if (val) return true;

    return false;
}

bool Validaciones::validarEntradaProceso(string resp)
{
    // Variable bandera
    bool val = false;
    // Arreglo de char para almacenar la entrada
    char a[resp.size()];
    //Tamaño de la entrada
    int size = resp.size();

    for (int i(0) ; i < size; ++i) a[i] = resp.at(i);

    for (int i(0) ; i < size; ++i)
    {
        if ( (a[i] >= 0 && a[i] <= 47) || (a[i] >= 58)) val = true;
    }

    if (!val)
    {
        int respAux = atoi(a);
        if (respAux < 0)
        {
            val = true;
        }
    }

    if (val) return true;

    return false;
}

bool Validaciones::validarEntradaModificar(string resp)
{
    // Variable bandera
    bool val = false;
    // Arreglo de char para almacenar la entrada
    char a[resp.size()];
    //Tamaño de la entrada
    int size = resp.size();

    for (int i(0) ; i < size; ++i) a[i] = resp.at(i);

    for (int i(0) ; i < size; ++i)
    {
        if ( (a[i] >= 0 && a[i] <= 48) || (a[i] >= 51)) val = true;
    }

    if (!val)
    {
        int respAux = atoi(a);
        if (respAux <= 0 || respAux >= 3)
        {
            val = true;
        }
    }

    if (val) return true;

    return false;
}

void Validaciones::validarProcesoExistente(string resp, vector<Proceso> &procesos, int *pos, int *err)
{
    // Arreglo de char para almacenar la entrada
    char a[resp.size()];
    //Tamaño de la entrada
    int size = resp.size();

    for (int i(0) ; i < size; ++i) a[i] = resp.at(i);

    for (int i(0) ; i < size; ++i)
    {
        if ( (a[i] >= 0 && a[i] <= 47) || (a[i] >= 58)) *err = 4;
    }

    if (*err == 0)
    {
        // Verificar si el valor es menor o igual a cero
        int respAux = atoi(a);
        if (respAux <= 0)
        {
            *err = 4;
        }
        if (*err == 0)
        {
            *err = 4;
            // Verificar si existe el proceso (ID) iterando en la lista
            for (size_t i(0) ; i < procesos.size() ; ++i)
            {
                if (procesos.at(i).getIdP() == "P" + resp)
                {
                    *err = 0;
                    *pos = i;
                    break;
                }
            }

        }
    }
}



