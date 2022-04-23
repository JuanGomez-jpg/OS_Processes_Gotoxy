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

        int getColorB() const;
        void setColorB(int newColorB);

        int getColB() const;
        void setColB(int newColB);

        int getFilB() const;
        void setFilB(int newFilB);

        int getMaxVal() const;
        void setMaxVal(int newMaxVal);

        int getTiempoTranscurrido() const;
        void setTiempoTranscurrido(int newTiempoTranscurrido);

private:
        string idP;
        int inicio, duracion, colT, filT, colorB, colB, filB, maxVal ,tiempoTranscurrido;

};

#endif // PROCESO_H
