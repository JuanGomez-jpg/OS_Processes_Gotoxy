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
   } //End

    return;
}

void Advertencias::advertenciaNoProcesos()
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

void Advertencias::advertenciaErrorMaximoProcesos()
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

void Advertencias::advertenciaErrorProcesos(int ent, vector<Proceso> &proceso)
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
    // Error - Agregar Proceso Manualmente
    if (ent == 1)
    {
        gotoxy(53,19); cout<<"mayor o igual a 0";
        // Limpiar respuesta
        for (int i (68) ; i < 119 ; ++i)
        {
            gotoxy(i, 5); cout<<" ";
        }
    }
    // Error - Agregar Proceso Manualmente
    else if (ent == 2)
    {
        gotoxy(53,19); cout<<"mayor o igual a 1";
        // Limpiar respuesta
        for (int i (70) ; i < 119 ; ++i)
        {
            gotoxy(i, 7); cout<<" ";
        }
    }
    // Error - Modificar - Opciones 1 y 2
    else if (ent == 3)
    {
        gotoxy(56,19); cout<<"entre 1 y 2";
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
        gotoxy(56,19); cout<<"entre 1 y " + size;
        // Limpiar respuesta
        for (int i (60) ; i < 119 ; ++i)
        {
            gotoxy(i, 5); cout<<" ";
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

void Advertencias::advertenciaErrorMenu()
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


