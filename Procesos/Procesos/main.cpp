#include <iostream>
#include <windows.h>
#include <cwchar>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>
#include <list>
#include <time.h>

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

bool validarEntradaProceso(string resp)
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

bool validarEntradaModificar(string resp)
{
    // Variable bandera
    bool val = false;
    // Arreglo de char para almacenar la entrada
    char a[resp.size()];
    //Tamaño de la entrada
    int size = resp.size();
    //Opcion
    int opc = 0;

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
        else
            opc = respAux;
    }

    if (opc == 1)
    {

    }
    else
    {

    }


    if (val) return true;

    return false;
}

void advertenciaErrorMenu()
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

void advertenciaErrorProcesos(int ent)
{
    SetColor(4); // Rojo
    // Filas y columnas del mensaje de error
    for (int i(48) ; i < 75 ; ++i)
    {
        gotoxy(i,16); printf("%c",205);
        gotoxy(i,20); printf("%c",205);

        for (int j(17) ; j < 20 ; ++j)
        {
            gotoxy(47,j); printf("%c",186);
            gotoxy(75,j); printf("%c",186);
        }
    }
    // Esquinas del mensaje de error
    gotoxy(47,16); printf("%c",201); // Sup. izquierda
    gotoxy(75,16); printf("%c", 187); // Sup. derecha
    gotoxy(47,20); printf("%c",200); // Inf. izquierda
    gotoxy(75,20); printf("%c",188); // Inf. derecha

    // Mensaje de error
    gotoxy(59,17); cout<<"ERROR";
    gotoxy(50,18); cout<<"Debe ingresar un n\243mero";
    if (ent == 1)
    {
        gotoxy(53,19); cout<<"mayor o igual a 0";
        // Limpiar respuesta
        for (int i (68) ; i < 119 ; ++i)
        {
            gotoxy(i, 5); cout<<" ";
        }
    }
    else if (ent == 2)
    {
        gotoxy(53,19); cout<<"mayor o igual a 1";
        // Limpiar respuesta
        for (int i (70) ; i < 119 ; ++i)
        {
            gotoxy(i, 7); cout<<" ";
        }
    }
    else if (ent == 3)
    {
        gotoxy(56,19); cout<<"entre 1 y 2";
        // Limpiar respuesta
        for (int i (65) ; i < 119 ; ++i)
        {
            gotoxy(i, 7); cout<<" ";
        }
    }

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
    SetColor(15); // Blanco
}

void advertenciaErrorMaximoProcesos()
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
    gotoxy(48,18); cout<<"Ya ha registrado la m\240xima";
    gotoxy(51,19); cout<<"cantidad de procesos";
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

void advertenciaNoProcesos()
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
    gotoxy(50,18); cout<<"Todav\241a no hay ning\243n";
    gotoxy(52,19); cout<<"proceso registrado";
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
    gotoxy(17,5); cout<<"Duraci\242n";


}

void procesosEjecucion()
{
    SetColor(15); // Blanco
    // Titulo
    gotoxy(28, 3); cout<<"Orden de ejecuci\242n";
    gotoxy(30, 5); cout<<"ID";
    gotoxy(35, 5); cout<<"Ejecuci\242n";

    SetColor(8);
    // Filas
    for (int i (29) ; i < 45 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,25); printf("%c",205);
    }
    // Columnas
    for (int i(5); i < 25 ; ++i)
    {
        gotoxy(28,i); printf("%c",186);
        gotoxy(33,i); printf("%c",186);
        gotoxy(45,i); printf("%c",186);
    }

    // Esquinas izquierdas
    gotoxy(28,4); printf("%c",201);
    gotoxy(28,25); printf("%c",200);

    // Esquinas derechas
    gotoxy(45,4); printf("%c",187);
    gotoxy(45,25); printf("%c",188);

    //Intersecciones Frame
    gotoxy(33,4);  printf("%c",203);
    gotoxy(33,25); printf("%c",202);
}

void mostrarProcesosAgregados(Proceso p)
{
    SetColor(15); // Blanco
    gotoxy(3, p.getColT()); cout<<""<<p.getIdP();
    gotoxy(10, p.getColT()); cout<<""<<p.getInicio();
    gotoxy(20, p.getColT()); cout<<""<<p.getDuracion();

    SetColor(4); // Rojo
    // Mostrar cuadro, columnas
    gotoxy(1, p.getColT()); printf("%c",186);
    gotoxy(6, p.getColT()); printf("%c",186);
    gotoxy(15, p.getColT()); printf("%c",186);
    gotoxy(26, p.getColT()); printf("%c",186);

    for (int i (2) ; i < 26 ; ++i)
    {
        gotoxy(i, p.getColT() + 1); printf("%c",205);
    }

    // Esquinas - Izquierda
    gotoxy(1, p.getColT() - 1); printf("%c",204);
    gotoxy(1, p.getColT() + 1); printf("%c",200);

    // Esquinas - Izquierda + 1
    gotoxy(6, p.getColT() - 1); printf("%c",206);
    gotoxy(6, p.getColT() + 1); printf("%c",202);

    // Esquinas - Izquierda + 2
    gotoxy(15, p.getColT() - 1); printf("%c",206);
    gotoxy(15, p.getColT() + 1); printf("%c",202);

    // Esquinas - Izquierda + 2
    gotoxy(26, p.getColT() - 1); printf("%c",185);
    gotoxy(26, p.getColT() + 1); printf("%c",188);

    SetColor(15); // Blanco

}

void cuadroProcesosEjecucion()
{
    SetColor(9); // Azul claro
    // Filas
    for (int i(48) ; i < 118 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,25); printf("%c",205);
    }
    // Columnas
    for (int i(5); i < 25; ++i)
    {
        gotoxy(47,i); printf("%c",186);
        gotoxy(118,i); printf("%c",186);
    }

    // Esquinas superiores
    gotoxy(47,4); printf("%c",201);
    gotoxy(118,4); printf("%c",187);
    // Esquinas inferiores
    gotoxy(47,25); printf("%c",200);
    gotoxy(118,25); printf("%c",188);

    SetColor(15); // Blanco
    // Titulo
    gotoxy(48, 3); cout<<"Ejecuci\242n de procesos";
}

void limpiarMenu()
{
    for (int j(3) ; j < 10 ; ++j)
    {
        for (int i(55) ; i < 93; ++i)
        {
            gotoxy(i,j); cout<<" ";
            //Sleep(1);
        }
    }
}

int agregarProcesoMan(int procesosRestantes, list<Proceso> &procesos)
{
    string resp = "";
    int procesosAux = procesosRestantes, inicio = 0, duracion = 0;
    if (procesosRestantes == 0)
    {
        advertenciaErrorMaximoProcesos();
    }
    else
    {
        limpiarMenu();

        // Titulo
        gotoxy(60,3); cout<<"Agregar";

        // Inicio - Entrada

        gotoxy(55, 5); cout<<"Inicio (0- ): ";
        gotoxy(68, 5); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (validarEntradaProceso(resp))
        {
            do
            {
                resp = "";
                advertenciaErrorProcesos(1);
                gotoxy(68, 5); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (validarEntradaProceso(resp) != false);
        }
        inicio = stoi(resp);

        // Duracion - Entrada

        gotoxy(55, 7); cout<<("Duraci\242n (1- ): ");
        gotoxy(70, 7); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (validarEntradaProceso(resp))
        {
            do
            {
                resp = "";
                advertenciaErrorProcesos(2);
                gotoxy(70, 7); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (validarEntradaProceso(resp) != false);
        }
        duracion = stoi(resp);

        Proceso p;
        p.setInicio(inicio);
        p.setDuracion(duracion);
        string id = "P" + to_string(procesos.size() + 1);
        int posCol = 0;

        if (procesos.size() == 0)
            posCol = 7;
        else
            posCol = procesos.back().getColT() + 2;

        p.setBarra(0);
        p.setFilT(2);
        p.setColT(posCol);
        p.setIdP(id);
        procesos.push_back(p);

        --procesosAux;
    }

    return procesosAux;
}

int agregarProcesoAut(int procesosRestantes, list<Proceso> &procesos)
{
    int procesosAux = procesosRestantes;
    if (procesosRestantes == 0)
    {
        advertenciaErrorMaximoProcesos();
    }
    else
    {
        limpiarMenu();

        Proceso p;
        p.setInicio(rand() % 200);
        p.setDuracion(1 + rand() % 200);
        string id = "P" + to_string(procesos.size() + 1);
        int posCol = 0;

        if (procesos.size() == 0)
            posCol = 7;
        else
            posCol = procesos.back().getColT() + 2;

        p.setBarra(0);
        p.setFilT(2);
        p.setColT(posCol);
        p.setIdP(id);
        procesos.push_back(p);

        --procesosAux;
    }

    return procesosAux;

}

void modificarProceso(int procesosRestantes, int cantidadMaxProc, list<Proceso> &procesos)
{
    string resp = "";
    int opcion = 0;
    if ( (cantidadMaxProc - procesosRestantes) == 0)
    {
        advertenciaNoProcesos();
    }
    else
    {
        limpiarMenu();

        // Titulo
        gotoxy(65,3); cout<<"Modificar";

        // Inicio - Entrada

        gotoxy(55, 5); cout<<"1) Ingresar el id del proceso";
        gotoxy(55, 6); cout<<"2) Cancelar";
        gotoxy(55, 7); cout<<"Respuesta: ";
        gotoxy(65, 7); getline(cin, resp);
        fflush(stdin);

        resp = removerEspacios(resp);
        if (validarEntradaModificar(resp))
        {
            do
            {
                resp = "";
                advertenciaErrorProcesos(3);
                gotoxy(65, 7); getline(cin, resp);
                fflush(stdin);
                resp = removerEspacios(resp);
            }while (validarEntradaModificar(resp) != false);
        }
        opcion = stoi(resp); // String to Int

        if (opcion == 1)
        {

        }
        else
            limpiarMenu();

    }
}

int Menu (int procesosRestantes, int maxProcesos)
{
    int opc = 0;
    string resp = "";

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
            advertenciaErrorMenu();
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
    srand (time(NULL));

    int procesosRestantes = 10, opc = 0;
    const int cantidadMaximaProcesos = procesosRestantes;
    list<Proceso> procesos;

    cout<<"Antes de comenzar, procura seleccionar el tama\244o de la fuente 36, fuente Consolas,"<<endl
        <<"el tama\244o del buffer de la ventana: 120, 9001"<<endl
        <<"el tama\244o de la ventana: 120, 30"<<endl
        <<"para el correcto funcionamiento del programa."<<endl<<endl
        <<"Una vez hecho esto, presione cualquier tecla para comenzar."<<endl<<endl;
    system("pause");
    system("cls");

    invocarInterfaz();

    do{
        gotoxy(28,4); cout<<"Procesos Restantes: "<<procesosRestantes<<" ";

        opc = Menu(procesosRestantes, cantidadMaximaProcesos);

        switch (opc) {
            case 1:
                procesosRestantes = agregarProcesoMan(procesosRestantes, procesos);
                limpiarMenu();
                mostrarProcesosAgregados(procesos.back());
                break;

            case 2:
                procesosRestantes = agregarProcesoAut(procesosRestantes, procesos);
                limpiarMenu();
                mostrarProcesosAgregados(procesos.back());
                break;

            case 3:
                modificarProceso(procesosRestantes, cantidadMaximaProcesos, procesos);
                limpiarMenu();
                break;

            case 4:
                procesosEjecucion();
                cuadroProcesosEjecucion();
                break;

            case 5:
                break;
        }

    }while(opc != 5);

    cout<<endl;

    return 0;
}


