#include <iostream>
#include <windows.h>
#include <cwchar>

using namespace std;

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

void AltEnter(){
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void changeFont_Console_Size(int size)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = size;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //stores the console's current dimensions

    MoveWindow(console, r.left, r.top, 120000, 9001, TRUE);

}

void invocarMenu ()
{
    // Imprimir las filas de los bordes
    SetColor(4); // Rojo
    for (int i(1) ; i < 100 ; ++i)
    {
        gotoxy(i,0); printf("%c",205);
        gotoxy(i,26); printf("%c", 205);
        gotoxy(i,2); printf("%c", 205);
    }
    // Imprimir las columnas de los bordes
    SetColor(6); // Amarillo
    for (int i (1) ; i < 26 ; ++i)
    {
        gotoxy(0,i); printf("%c", 186);
        gotoxy(100,i); printf("%c", 186);
    }

    SetColor(15); // Blanco
    // Título
    gotoxy(39,1); printf("Administraci%cn de Procesos", 162);

    SetColor(4); // Rojo
    //Esquina sup. izquierda
    gotoxy(0,0); printf("%c",201);
    //Inter. ziquierda
    gotoxy(0,2); printf("%c",204);
    //Esquina inf. izquierda
    gotoxy(0,26); printf("%c", 200);

    //Esquina sup. derecha
    gotoxy(100,0); printf("%c",187);
    //Inter. derecha
    gotoxy(100,2); printf("%c",185);
    //Esquina inf. derecha
    gotoxy(100,26); printf("%c", 188);

    // Cuadro de los procesos
    for (int i(2) ; i < 25 ; ++i)
    {
        gotoxy(i,4); printf("%c",205);
        gotoxy(i,6); printf("%c",205);
    }
    // Columnas de los procesos
    gotoxy(1,5); printf("%c",186);
    gotoxy(6,5); printf("%c",186);
    gotoxy(15,5); printf("%c",186);
    gotoxy(26,5); printf("%c",186);

    // Intersecciones de los procesos
    //gotoxy(1,5); printf("%c",186);


    SetColor(15); // Blanco
    //Datos de los Procesos
    gotoxy(3,3); cout<<"Datos de los procesos";
    gotoxy(3,5); cout<<"ID";
    gotoxy(8,5); cout<<"Inicio";
    gotoxy(17,5); cout<<"Duraci\242n ";

}

int main()
{
    system("pause");
    system("cls");

    invocarMenu();
    //changeFont_Console_Size(36);

    //Color(37, 46);
    gotoxy(30, 10); getchar();

    cout<<endl;

    return 0;
}
