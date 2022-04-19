#include "Proceso.h"

Proceso::Proceso(){ }

Proceso::~Proceso(){ }

const string &Proceso::getIdP() const
{
    return idP;
}

void Proceso::setIdP(const string &newIdP)
{
    idP = newIdP;
}

int Proceso::getInicio() const
{
    return inicio;
}

void Proceso::setInicio(int newInicio)
{
    inicio = newInicio;
}

int Proceso::getDuracion() const
{
    return duracion;
}

void Proceso::setDuracion(int newDuracion)
{
    duracion = newDuracion;
}

int Proceso::getColT() const
{
    return colT;
}

void Proceso::setColT(int newColT)
{
    colT = newColT;
}

int Proceso::getFilT() const
{
    return filT;
}

void Proceso::setFilT(int newFilT)
{
    filT = newFilT;
}

int Proceso::getBarra() const
{
    return barra;
}

void Proceso::setBarra(int newBarra)
{
    barra = newBarra;
}

