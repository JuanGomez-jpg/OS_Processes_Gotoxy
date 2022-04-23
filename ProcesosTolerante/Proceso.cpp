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

int Proceso::getColorB() const
{
    return colorB;
}

void Proceso::setColorB(int newColorB)
{
    colorB = newColorB;
}

int Proceso::getColB() const
{
    return colB;
}

void Proceso::setColB(int newColB)
{
    colB = newColB;
}

int Proceso::getFilB() const
{
    return filB;
}

void Proceso::setFilB(int newFilB)
{
    filB = newFilB;
}

int Proceso::getMaxVal() const
{
    return maxVal;
}

void Proceso::setMaxVal(int newMaxVal)
{
    maxVal = newMaxVal;
}

int Proceso::getTiempoTranscurrido() const
{
    return tiempoTranscurrido;
}

void Proceso::setTiempoTranscurrido(int newTiempoTranscurrido)
{
    tiempoTranscurrido = newTiempoTranscurrido;
}


