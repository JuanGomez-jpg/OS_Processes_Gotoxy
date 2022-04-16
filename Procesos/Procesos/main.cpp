#include <iostream>
#include <windows.h>
#include <cwchar>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <list>

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

void invocarInterfaz();
int Menu (int procesosRestantes);

void Color(int fondo, int texto)
{
    HANDLE Console=GetStdHandle(STD_OUTPUT_HANDLE);
    int nuevoColor=texto+(fondo*16);
    SetConsoleTextAttribute(Console, nuevoColor);
}

void SetColor(int ForgC){
             WORD wColor;
             HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
             CONSOLE_SCREEN_BUFFER_INFO csbi;

            if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){

            wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
            SetConsoleTextAttribute(hStdOut, wColor);
            } //End
     return;
}

void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

string removerEspacios(string resp)
{
    string value = "";
    for (size_t i(0) ; i < resp.size() ; ++i)
    {
        if (resp.at(i) != ' ')
            value += resp.at(i);
    }
    return value;
}

bool validarEntradaMenu(string resp)
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

void advertenciaError()
{
    SetColor(4); // Rojo
    // Filas y columnas del mensaje de error
    for (int i(47) ; i < 75 ; ++i)
    {
        gotoxy(i,16); printf("%c",205);
        gotoxy(i,20); printf("%c",205);

        for (int j(17) ; j < 20 ; ++j)
        {
            gotoxy(46,j); printf("%c",186);
            gotoxy(75,j); printf("%c",186);
        }
    }
    // Esquinas del mensaje de error
    gotoxy(46,16); printf("%c",201); // Sup. izquierda
    gotoxy(75,16); printf("%c", 187); // Sup. derecha
    gotoxy(46,20); printf("%c",200); // Inf. izquierda
    gotoxy(75,20); printf("%c",188); // Inf. derecha

    // Mensaje de error
    gotoxy(58,17); cout<<"ERROR";
    gotoxy(50,18); cout<<"Debe ingresar un valor";
    gotoxy(55,19); cout<<"entre 1 y 5";
    Sleep(3000);
    // Limpiar el mensaje de error
    for (int i(46) ; i < 76 ; ++i)
    {
        gotoxy(i,16); cout<<" ";
        gotoxy(i,17); cout<<" ";
        gotoxy(i,18); cout<<" ";
        gotoxy(i,19); cout<<" ";
        gotoxy(i,20); cout<<" ";
    }
    // Limpiar respuesta
    for (int i (70) ; i < 119 ; ++i)
    {
        gotoxy(i, 9); cout<<" ";
    }
    SetColor(15); // Blanco
}

void invocarInterfaz()
{
    // Imprimir las filas de los bordes
    SetColor(4); // Rojo
    for (int i(1) ; i < 119 ; ++i)
    {
        gotoxy(i,0); printf("%c",205);
        gotoxy(i,2); printf("%c", 205);
        gotoxy(i,29); printf("%c", 205);
    }
    // Imprimir las columnas de los bordes
    SetColor(6); // Amarillo
    for (int i (1) ; i < 29 ; ++i)
    {
        gotoxy(0,i); printf("%c", 186);
        gotoxy(119,i); printf("%c", 186);
    }

    SetColor(15); // Blanco
    // Título
    gotoxy(48,1); printf("Administraci%cn de Procesos", 162);

    SetColor(4); // Rojo
    //Esquina sup. izquierda
    gotoxy(0,0); printf("%c",201);
    //Inter. ziquierda
    gotoxy(0,2); printf("%c",204);
    //Esquina inf. izquierda
    gotoxy(0,29); printf("%c", 200);

    //Esquina sup. derecha
    gotoxy(119,0); printf("%c",187);
    //Inter. derecha
    gotoxy(119,2); printf("%c",185);
    //Esquina inf. derecha
    gotoxy(119,29); printf("%c", 188);

    // Cuadro de los procesos
    for (int i(2) ; i < 27 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,6); printf("%c",205);
    }

    // Columnas de los procesos
    gotoxy(1,5); printf("%c",186);
    gotoxy(6,5); printf("%c",186);
    gotoxy(15,5); printf("%c",186);
    gotoxy(26,5); printf("%c",186);

    // Intersecciones de los procesos lado izquierdo
    gotoxy(1,4); printf("%c",201);
    gotoxy(1,6); printf("%c",200);
    // Intersecciones de los procesos lado derecho
    gotoxy(26,4); printf("%c",187);
    gotoxy(26,6); printf("%c",188);
    // Intersecciones de los procesos
    gotoxy(6,4); printf("%c",203);
    gotoxy(6,6); printf("%c",202);
    gotoxy(15,4); printf("%c",203);
    gotoxy(15,6); printf("%c",202);

    SetColor(15); // Blanco
    //Datos de los Procesos
    gotoxy(4,3); cout<<"Datos de los procesos";
    gotoxy(3,5); cout<<"ID";
    gotoxy(8,5); cout<<"Inicio";
    gotoxy(17,5); cout<<"Duraci\242n ";


}

void limpiarMenu()
{
    for (int j(3) ; j < 10 ; ++j)
    {
        for (int i(60) ; i < 93; ++i)
        {
            gotoxy(i,j); cout<<" ";
            //Sleep(1);
        }
    }
}

int agregarProcesoMan(int procesosRestantes)
{
    if (procesosRestantes == 0)
    {

    }
    else
    {

    }
}

int Menu (int procesosRestantes)
{
    int opc = 0;
    string resp = "";
    const int maxProcesos = 21;

    // Blanco
    SetColor(15);
    gotoxy(73, 3); cout<<"Men\243";

    if (procesosRestantes == 0)
    {   // Rojo
        SetColor(4);
        gotoxy(60, 4); cout<<"1) A\244adir proceso manualmente";
        gotoxy(60, 5); cout<<"2) A\244adir proceso autom\240ticamente";
    }
    else
    {
        // Blanco
        SetColor(15);
        gotoxy(60, 4); cout<<"1) A\244adir proceso manualmente";
        gotoxy(60, 5); cout<<"2) A\244adir proceso autom\240ticamente";
    }

    if (procesosRestantes == maxProcesos)
    {   // Rojo
        SetColor(4);
        gotoxy(60, 6); cout<<"3) Modificar un proceso";
        gotoxy(60, 7); cout<<"4) Comenzar";
        // Blanco
        SetColor(15);
    }
    else
    {
        // Blanco
        SetColor(15);
        gotoxy(60, 6); cout<<"3) Modificar un proceso";
        gotoxy(60, 7); cout<<"4) Comenzar";
    }
    gotoxy(60, 8); cout<<"5) Salir";
    gotoxy(60, 9); cout<<"Respuesta: ";
    gotoxy(70, 9); getline(cin, resp);
    fflush(stdin);

    resp = removerEspacios(resp);
    if (validarEntradaMenu(resp))
    {
        do
        {
            resp = "";
            advertenciaError();
            gotoxy(70, 9); getline(cin, resp);
            fflush(stdin);
            resp = removerEspacios(resp);
        }while (validarEntradaMenu(resp) != false);
    }
    opc = stoi(resp);

    return opc;
}

int main()
{
    cout<<"Antes de comenzar, procura seleccionar el tama\244o de la fuente 36, fuente Consolas,"<<endl
        <<"el tama\244o del buffer de la ventana: 120, 9001"<<endl
        <<"el tama\244o de la ventana: 120, 30"<<endl
        <<"para el correcto funcionamiento del programa."<<endl<<endl
        <<"Una vez hecho esto, presione cualquier tecla para comenzar."<<endl<<endl;
    system("pause");
    system("cls");

    int procesosRestantes = 21, opc = 0;
    invocarInterfaz();

    do{
        gotoxy(28,4); cout<<"Procesos Restantes: "<<procesosRestantes;

        opc = Menu(procesosRestantes);
        limpiarMenu();
        switch (opc) {
            case 1:
                agregarProcesoMan(procesosRestantes);
                break;
            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;
        }

    }while(opc != 5);

    getchar();

    cout<<endl;

    return 0;
}


