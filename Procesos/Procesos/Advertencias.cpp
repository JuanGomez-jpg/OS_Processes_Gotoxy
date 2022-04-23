#include "Advertencias.h"

Advertencias::Advertencias()
{

}

void Advertencias::gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Advertencias::SetColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }

    return;
}

void Advertencias::advertenciaNoProcesos()
{
    SetColor(7); // Blanco
    // Filas y columnas del mensaje de error
    for (int i(47) ; i < 75 ; ++i)
    {
        gotoxy(i,13); printf("%c",205);
        gotoxy(i,18); printf("%c",205);

        for (int j(14) ; j < 18 ; ++j)
        {
            gotoxy(46,j); printf("%c",186);
            gotoxy(75,j); printf("%c",186);
        }
    }
    // Esquinas del mensaje de error
    gotoxy(46,13); printf("%c",201); // Sup. izquierda
    gotoxy(75,13); printf("%c", 187); // Sup. derecha
    gotoxy(46,18); printf("%c",200); // Inf. izquierda
    gotoxy(75,18); printf("%c",188); // Inf. derecha

    SetColor(4); // Rojo
    // Mensaje de error
    gotoxy(58,13); cout<<"ERROR";
    SetColor(6); // Amarillo
    gotoxy(50,15); cout<<"Todav\241a no hay ning\243n";
    gotoxy(52,16); cout<<"proceso registrado";
    SetColor(15); // Blanco
    gotoxy(42,21); cout<<"Presione cualquier tecla para continuar";
    gotoxy(46,20); system("pause");

    // Limpiar el mensaje de error
    for (int i(40) ; i < 90 ; ++i)
    {
        gotoxy(i,13); cout<<" ";
        gotoxy(i,14); cout<<" ";
        gotoxy(i,15); cout<<" ";
        gotoxy(i,16); cout<<" ";
        gotoxy(i,17); cout<<" ";
        gotoxy(i,18); cout<<" ";
        gotoxy(i,20); cout<<" ";
        gotoxy(i,21); cout<<" ";
    }
    // Limpiar respuesta
    for (int i (70) ; i < 119 ; ++i)
    {
        gotoxy(i, 9); cout<<" ";
    }
    SetColor(15); // Blanco
}

void Advertencias::advertenciaErrorMaximoProcesos()
{
    SetColor(7); // Blanco
    // Filas y columnas del mensaje de error
    for (int i(47) ; i < 75 ; ++i)
    {
        gotoxy(i,13); printf("%c",205);
        gotoxy(i,18); printf("%c",205);

        for (int j(14) ; j < 18 ; ++j)
        {
            gotoxy(46,j); printf("%c",186);
            gotoxy(75,j); printf("%c",186);
        }
    }
    // Esquinas del mensaje de error
    gotoxy(46,13); printf("%c",201); // Sup. izquierda
    gotoxy(75,13); printf("%c", 187); // Sup. derecha
    gotoxy(46,18); printf("%c",200); // Inf. izquierda
    gotoxy(75,18); printf("%c",188); // Inf. derecha

    SetColor(4); // Rojo
    // Mensaje de error
    gotoxy(58,13); cout<<"ERROR";
    SetColor(6); // Amarillo
    gotoxy(48,15); cout<<"Ya ha registrado la m\240xima";
    gotoxy(51,16); cout<<"cantidad de procesos";

    SetColor(15); // Blanco
    gotoxy(42,21); cout<<"Presione cualquier tecla para continuar";
    gotoxy(46,20); system("pause");

    // Limpiar el mensaje de error
    for (int i(40) ; i < 90 ; ++i)
    {
        gotoxy(i,13); cout<<" ";
        gotoxy(i,14); cout<<" ";
        gotoxy(i,15); cout<<" ";
        gotoxy(i,16); cout<<" ";
        gotoxy(i,17); cout<<" ";
        gotoxy(i,18); cout<<" ";
        gotoxy(i,20); cout<<" ";
        gotoxy(i,21); cout<<" ";
    }
    // Limpiar respuesta
    for (int i (70) ; i < 119 ; ++i)
    {
        gotoxy(i, 9); cout<<" ";
    }
    SetColor(15); // Blanco
}

void Advertencias::advertenciaErrorProcesos(int ent, vector<Proceso> &proceso, int limSup)
{
    SetColor(7); // Blanco
    // Filas y columnas del mensaje de error
    for (int i(47) ; i < 75 ; ++i)
    {
        gotoxy(i,13); printf("%c",205);
        gotoxy(i,18); printf("%c",205);

        for (int j(14) ; j < 18 ; ++j)
        {
            gotoxy(46,j); printf("%c",186);
            gotoxy(75,j); printf("%c",186);
        }
    }
    // Esquinas del mensaje de error
    gotoxy(46,13); printf("%c",201); // Sup. izquierda
    gotoxy(75,13); printf("%c", 187); // Sup. derecha
    gotoxy(46,18); printf("%c",200); // Inf. izquierda
    gotoxy(75,18); printf("%c",188); // Inf. derecha

    SetColor(4); // Rojo
    // Mensaje de error
    gotoxy(58,13); cout<<"ERROR";
    SetColor(6); // Amarillo
    gotoxy(50,15); cout<<"Debe ingresar un n\243mero";
    // Error - Agregar Proceso Manualmente
    if (ent == 1)
    {
        gotoxy(55,16); cout<<"entre 0 y 67";
        // Limpiar respuesta
        for (int i (69) ; i < 119 ; ++i)
        {
            gotoxy(i, 5); cout<<" ";
        }
    }
    // Error - Agregar Proceso Manualmente
    else if (ent == 2)
    {
        gotoxy(55,16); cout<<"entre 2 y "<<limSup;
        // Limpiar respuesta
        for (int i (71) ; i < 119 ; ++i)
        {
            gotoxy(i, 7); cout<<" ";
        }
    }
    // Error - Modificar - Opciones 1 y 2
    else if (ent == 3)
    {
        gotoxy(56,16); cout<<"entre 1 y 2";
        // Limpiar respuesta
        for (int i (65) ; i < 119 ; ++i)
        {
            gotoxy(i, 7); cout<<" ";
        }
    }
    // Error - Modificar Proceso - Entrada no Valida (No valores)
    else if (ent == 4)
    {
        string size = to_string(proceso.size());
        gotoxy(56,16); cout<<"entre 1 y " + size;
        // Limpiar respuesta
        for (int i (60) ; i < 119 ; ++i)
        {
            gotoxy(i, 5); cout<<" ";
        }
    }

    SetColor(15); // Blanco
    gotoxy(42,21); cout<<"Presione cualquier tecla para continuar";
    gotoxy(46,20); system("pause");

    // Limpiar el mensaje de error
    for (int i(40) ; i < 90 ; ++i)
    {
        gotoxy(i,13); cout<<" ";
        gotoxy(i,14); cout<<" ";
        gotoxy(i,15); cout<<" ";
        gotoxy(i,16); cout<<" ";
        gotoxy(i,17); cout<<" ";
        gotoxy(i,18); cout<<" ";
        gotoxy(i,20); cout<<" ";
        gotoxy(i,21); cout<<" ";
    }
    SetColor(15); // Blanco
}

void Advertencias::advertenciaErrorMenu()
{
    SetColor(7); // Blanco
    // Filas y columnas del mensaje de error
    for (int i(47) ; i < 75 ; ++i)
    {
        gotoxy(i,13); printf("%c",205);
        gotoxy(i,18); printf("%c",205);

        for (int j(14) ; j < 18 ; ++j)
        {
            gotoxy(46,j); printf("%c",186);
            gotoxy(75,j); printf("%c",186);
        }
    }
    // Esquinas del mensaje de error
    gotoxy(46,13); printf("%c",201); // Sup. izquierda
    gotoxy(75,13); printf("%c", 187); // Sup. derecha
    gotoxy(46,18); printf("%c",200); // Inf. izquierda
    gotoxy(75,18); printf("%c",188); // Inf. derecha

    SetColor(4); // Rojo
    // Mensaje de error
    gotoxy(58,13); cout<<"ERROR";

    SetColor(6); // Amarillo
    gotoxy(50,15); cout<<"Debe ingresar un valor";
    gotoxy(55,16); cout<<"entre 1 y 5";

    SetColor(15); // Blanco
    gotoxy(42,21); cout<<"Presione cualquier tecla para continuar";
    gotoxy(46,20); system("pause");

    // Limpiar el mensaje de error
    for (int i(40) ; i < 90 ; ++i)
    {
        gotoxy(i,13); cout<<" ";
        gotoxy(i,14); cout<<" ";
        gotoxy(i,15); cout<<" ";
        gotoxy(i,16); cout<<" ";
        gotoxy(i,17); cout<<" ";
        gotoxy(i,18); cout<<" ";
        gotoxy(i,20); cout<<" ";
        gotoxy(i,21); cout<<" ";
    }
    // Limpiar respuesta
    for (int i (70) ; i < 119 ; ++i)
    {
        gotoxy(i, 9); cout<<" ";
    }
    SetColor(15); // Blanco
}


