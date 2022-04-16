#include <iostream>
#include <windows.h>
#include <cwchar>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cctype>

using namespace std;


void invocarInterfaz();

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
}

void invocarInterfaz ()
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
    for (int i(3) ; i < 28 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,6); printf("%c",205);
    }

    // Columnas de los procesos
    gotoxy(2,5); printf("%c",186);
    gotoxy(7,5); printf("%c",186);
    gotoxy(16,5); printf("%c",186);
    gotoxy(27,5); printf("%c",186);

    // Intersecciones de los procesos lado izquierdo
    gotoxy(2,4); printf("%c",201);
    gotoxy(2,6); printf("%c",200);
    // Intersecciones de los procesos lado derecho
    gotoxy(27,4); printf("%c",187);
    gotoxy(27,6); printf("%c",188);
    // Intersecciones de los procesos
    gotoxy(7,4); printf("%c",203);
    gotoxy(7,6); printf("%c",202);
    gotoxy(16,4); printf("%c",203);
    gotoxy(16,6); printf("%c",202);

    SetColor(15); // Blanco
    //Datos de los Procesos
    gotoxy(5,3); cout<<"Datos de los procesos";
    gotoxy(4,5); cout<<"ID";
    gotoxy(9,5); cout<<"Inicio";
    gotoxy(18,5); cout<<"Duraci\242n ";


}

int invocarMenu (int procesosRestantes)
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

    if (procesosRestantes == 15)
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


    return opc;
}

int main()
{
    system("pause");
    system("cls");

    int procesosRestantes = 15;

    gotoxy(33,4); cout<<"Procesos Restantes: "<<procesosRestantes;

    invocarInterfaz();
    invocarMenu(procesosRestantes);

     getchar();

    cout<<endl;

    return 0;
}
