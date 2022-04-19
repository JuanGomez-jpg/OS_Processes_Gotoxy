#ifndef PROCESO_H
#define PROCESO_H

#include <iostream>

using namespace std;

// Clase Proceso
class Proceso{
    public:
        Proceso();
        ~Proceso();

        const string &getIdP() const;
        void setIdP(const string &newIdP);

        int getInicio() const;
        void setInicio(int newInicio);

        int getDuracion() const;
        void setDuracion(int newDuracion);

        int getColT() const;
        void setColT(int newColT);

        int getFilT() const;
        void setFilT(int newFilT);

        int getBarra() const;
        void setBarra(int newBarra);

private:
        string idP;
        int inicio, duracion, colT, filT, barra;

};

#endif // PROCESO_H
